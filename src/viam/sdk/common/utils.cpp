#include <viam/sdk/common/utils.hpp>

#include <random>
#include <unordered_map>
#include <vector>

#include <boost/algorithm/string.hpp>
#include <boost/blank.hpp>
#include <boost/log/core.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/trivial.hpp>
#include <boost/optional/optional.hpp>
#include <grpcpp/client_context.h>

#include <viam/api/common/v1/common.pb.h>

#include <viam/sdk/common/private/utils.hpp>
#include <viam/sdk/common/private/version_metadata.hpp>
#include <viam/sdk/components/component.hpp>
#include <viam/sdk/registry/registry.hpp>

namespace viam {
namespace sdk {

std::vector<unsigned char> string_to_bytes(const std::string& s) {
    std::vector<unsigned char> bytes(s.begin(), s.end());
    return bytes;
};

std::string bytes_to_string(const std::vector<unsigned char>& b) {
    std::string img_string(b.begin(), b.end());
    return img_string;
};

time_pt timestamp_to_time_pt(const google::protobuf::Timestamp& timestamp) {
    return time_pt{std::chrono::seconds{timestamp.seconds()} +
                   std::chrono::nanoseconds{timestamp.nanos()}};
}

google::protobuf::Timestamp time_pt_to_timestamp(time_pt tp) {
    const std::chrono::nanoseconds since_epoch = tp.time_since_epoch();

    const auto sec_floor = std::chrono::duration_cast<std::chrono::seconds>(since_epoch);
    const std::chrono::nanoseconds nano_part = since_epoch - sec_floor;

    google::protobuf::Timestamp result;

    result.set_seconds(sec_floor.count());
    result.set_nanos(static_cast<int32_t>(nano_part.count()));

    return result;
}

response_metadata response_metadata::from_proto(const viam::common::v1::ResponseMetadata& proto) {
    response_metadata metadata;
    metadata.captured_at = timestamp_to_time_pt(proto.captured_at());
    return metadata;
}

viam::common::v1::ResponseMetadata response_metadata::to_proto(const response_metadata& metadata) {
    viam::common::v1::ResponseMetadata proto;
    google::protobuf::Timestamp ts = time_pt_to_timestamp(metadata.captured_at);
    *proto.mutable_captured_at() = std::move(ts);
    return proto;
}

std::chrono::microseconds from_proto(const google::protobuf::Duration& proto) {
    namespace sc = std::chrono;
    const sc::seconds seconds_part{proto.seconds()};
    const sc::nanoseconds nanos_part{proto.nanos()};

    const sc::microseconds from_seconds = sc::duration_cast<sc::microseconds>(seconds_part);
    sc::microseconds from_nanos = sc::duration_cast<sc::microseconds>(nanos_part);

    if ((nanos_part.count() < 0) && (from_nanos > nanos_part)) {
        from_nanos -= sc::microseconds(1);
    } else if ((nanos_part.count() > 0) && (from_nanos < nanos_part)) {
        from_nanos += sc::microseconds(1);
    }
    return from_seconds + from_nanos;
}

google::protobuf::Duration to_proto(std::chrono::microseconds duration) {
    namespace sc = std::chrono;

    const sc::seconds seconds = sc::duration_cast<sc::seconds>(duration);
    const sc::nanoseconds nanos = duration - seconds;

    google::protobuf::Duration proto;
    proto.set_nanos(static_cast<int32_t>(nanos.count()));
    proto.set_seconds(seconds.count());
    return proto;
}

void set_logger_severity_from_args(int argc, char** argv) {
    if (argc >= 3 && strcmp(argv[2], "--log-level=debug") == 0) {
        boost::log::core::get()->set_filter(boost::log::trivial::severity >=
                                            boost::log::trivial::debug);
        return;
    }
    boost::log::core::get()->set_filter(boost::log::trivial::severity >= boost::log::trivial::info);
}

bool operator==(const response_metadata& lhs, const response_metadata& rhs) {
    return lhs.captured_at == rhs.captured_at;
}

void ClientContext::set_client_ctx_authority_() {
    wrapped_context_.set_authority("viam-placeholder");
}

std::string random_debug_key() {
    static const char alphanum[] = "abcdefghijklmnopqrstuvwxyz";
    static std::default_random_engine generator(
        std::chrono::system_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<int> distribution(0, sizeof(alphanum) - 1);

    std::string key;
    key.reserve(6);

    for (int i = 0; i < 6; ++i) {
        key += alphanum[distribution(generator)];
    };

    return key;
}

ProtoStruct debug_map() {
    return debug_map(random_debug_key());
}

ProtoStruct debug_map(std::string debug_key) {
    ProtoStruct map;
    map.emplace(impl::debug_map_key, ProtoValue(std::move(debug_key)));

    return map;
}

void add_debug_entry(ProtoStruct& map, std::string debug_key) {
    map.emplace(impl::debug_map_key, ProtoValue(std::move(debug_key)));
}

void add_debug_entry(ProtoStruct& map) {
    add_debug_entry(map, random_debug_key());
}

ProtoStruct with_debug_entry(ProtoStruct&& map, std::string debug_key) {
    add_debug_entry(map, std::move(debug_key));
    return map;
}

ProtoStruct with_debug_entry(ProtoStruct&& map) {
    add_debug_entry(map);
    return map;
}

void ClientContext::set_debug_key(const std::string& debug_key) {
    wrapped_context_.AddMetadata("dtname", debug_key);
}

void ClientContext::add_viam_client_version_() {
    wrapped_context_.AddMetadata("viam_client", impl::k_version);
}

ClientContext::ClientContext() {
    set_client_ctx_authority_();
    add_viam_client_version_();
}

ClientContext::operator const grpc::ClientContext*() const {
    return &wrapped_context_;
}

ClientContext::operator grpc::ClientContext*() {
    return &wrapped_context_;
}

bool from_dm_from_extra(const ProtoStruct& extra) {
    auto pos = extra.find("fromDataManagement");
    if (pos != extra.end()) {
        const ProtoValue& value = pos->second;

        return (value.is_a<bool>() && value.get_unchecked<bool>());
    }
    return false;
}
std::pair<std::string, std::string> long_name_to_remote_and_short(const std::string& long_name) {
    std::vector<std::string> name_parts;
    // boost::split causes a clang-tidy false positive, see
    // https://bugs.llvm.org/show_bug.cgi?id=41141
    //
    // NOLINTNEXTLINE
    boost::split(name_parts, long_name, boost::is_any_of(":"));
    auto name = name_parts.back();
    name_parts.pop_back();
    auto remote_name = name_parts.empty()
                           ? ""
                           : std::accumulate(std::next(name_parts.begin()),
                                             name_parts.end(),
                                             *name_parts.begin(),
                                             [](const std::string& a, const std::string& b) {
                                                 return a + ":" + b;
                                             });

    return {std::move(remote_name), std::move(name)};
}

}  // namespace sdk
}  // namespace viam
