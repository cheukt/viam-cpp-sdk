// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: google/api/launch_stage.proto

#include "google/api/launch_stage.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>

PROTOBUF_PRAGMA_INIT_SEG

namespace _pb = ::PROTOBUF_NAMESPACE_ID;
namespace _pbi = _pb::internal;

namespace google {
namespace api {
}  // namespace api
}  // namespace google
static const ::_pb::EnumDescriptor* file_level_enum_descriptors_google_2fapi_2flaunch_5fstage_2eproto[1];
static constexpr ::_pb::ServiceDescriptor const** file_level_service_descriptors_google_2fapi_2flaunch_5fstage_2eproto = nullptr;
const uint32_t TableStruct_google_2fapi_2flaunch_5fstage_2eproto::offsets[1] = {};
static constexpr ::_pbi::MigrationSchema* schemas = nullptr;
static constexpr ::_pb::Message* const* file_default_instances = nullptr;

const char descriptor_table_protodef_google_2fapi_2flaunch_5fstage_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\035google/api/launch_stage.proto\022\ngoogle."
  "api*\214\001\n\013LaunchStage\022\034\n\030LAUNCH_STAGE_UNSP"
  "ECIFIED\020\000\022\021\n\rUNIMPLEMENTED\020\006\022\r\n\tPRELAUNC"
  "H\020\007\022\020\n\014EARLY_ACCESS\020\001\022\t\n\005ALPHA\020\002\022\010\n\004BETA"
  "\020\003\022\006\n\002GA\020\004\022\016\n\nDEPRECATED\020\005BZ\n\016com.google"
  ".apiB\020LaunchStageProtoP\001Z-google.golang."
  "org/genproto/googleapis/api;api\242\002\004GAPIb\006"
  "proto3"
  ;
static ::_pbi::once_flag descriptor_table_google_2fapi_2flaunch_5fstage_2eproto_once;
const ::_pbi::DescriptorTable descriptor_table_google_2fapi_2flaunch_5fstage_2eproto = {
    false, false, 286, descriptor_table_protodef_google_2fapi_2flaunch_5fstage_2eproto,
    "google/api/launch_stage.proto",
    &descriptor_table_google_2fapi_2flaunch_5fstage_2eproto_once, nullptr, 0, 0,
    schemas, file_default_instances, TableStruct_google_2fapi_2flaunch_5fstage_2eproto::offsets,
    nullptr, file_level_enum_descriptors_google_2fapi_2flaunch_5fstage_2eproto,
    file_level_service_descriptors_google_2fapi_2flaunch_5fstage_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::_pbi::DescriptorTable* descriptor_table_google_2fapi_2flaunch_5fstage_2eproto_getter() {
  return &descriptor_table_google_2fapi_2flaunch_5fstage_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2 static ::_pbi::AddDescriptorsRunner dynamic_init_dummy_google_2fapi_2flaunch_5fstage_2eproto(&descriptor_table_google_2fapi_2flaunch_5fstage_2eproto);
namespace google {
namespace api {
const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* LaunchStage_descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_google_2fapi_2flaunch_5fstage_2eproto);
  return file_level_enum_descriptors_google_2fapi_2flaunch_5fstage_2eproto[0];
}
bool LaunchStage_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
      return true;
    default:
      return false;
  }
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace api
}  // namespace google
PROTOBUF_NAMESPACE_OPEN
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>