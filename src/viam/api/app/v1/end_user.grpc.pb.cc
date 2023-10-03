// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: app/v1/end_user.proto

#include "app/v1/end_user.pb.h"
#include "app/v1/end_user.grpc.pb.h"

#include <functional>
#include <grpcpp/support/async_stream.h>
#include <grpcpp/support/async_unary_call.h>
#include <grpcpp/impl/channel_interface.h>
#include <grpcpp/impl/client_unary_call.h>
#include <grpcpp/support/client_callback.h>
#include <grpcpp/support/message_allocator.h>
#include <grpcpp/support/method_handler.h>
#include <grpcpp/impl/rpc_service_method.h>
#include <grpcpp/support/server_callback.h>
#include <grpcpp/impl/codegen/server_callback_handlers.h>
#include <grpcpp/server_context.h>
#include <grpcpp/impl/service_type.h>
#include <grpcpp/support/sync_stream.h>
namespace viam {
namespace app {
namespace v1 {

static const char* EndUserService_method_names[] = {
  "/viam.app.v1.EndUserService/IsLegalAccepted",
  "/viam.app.v1.EndUserService/AcceptLegal",
};

std::unique_ptr< EndUserService::Stub> EndUserService::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< EndUserService::Stub> stub(new EndUserService::Stub(channel, options));
  return stub;
}

EndUserService::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options)
  : channel_(channel), rpcmethod_IsLegalAccepted_(EndUserService_method_names[0], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_AcceptLegal_(EndUserService_method_names[1], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::Status EndUserService::Stub::IsLegalAccepted(::grpc::ClientContext* context, const ::viam::app::v1::IsLegalAcceptedRequest& request, ::viam::app::v1::IsLegalAcceptedResponse* response) {
  return ::grpc::internal::BlockingUnaryCall< ::viam::app::v1::IsLegalAcceptedRequest, ::viam::app::v1::IsLegalAcceptedResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_IsLegalAccepted_, context, request, response);
}

void EndUserService::Stub::async::IsLegalAccepted(::grpc::ClientContext* context, const ::viam::app::v1::IsLegalAcceptedRequest* request, ::viam::app::v1::IsLegalAcceptedResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::viam::app::v1::IsLegalAcceptedRequest, ::viam::app::v1::IsLegalAcceptedResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_IsLegalAccepted_, context, request, response, std::move(f));
}

void EndUserService::Stub::async::IsLegalAccepted(::grpc::ClientContext* context, const ::viam::app::v1::IsLegalAcceptedRequest* request, ::viam::app::v1::IsLegalAcceptedResponse* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_IsLegalAccepted_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::viam::app::v1::IsLegalAcceptedResponse>* EndUserService::Stub::PrepareAsyncIsLegalAcceptedRaw(::grpc::ClientContext* context, const ::viam::app::v1::IsLegalAcceptedRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::viam::app::v1::IsLegalAcceptedResponse, ::viam::app::v1::IsLegalAcceptedRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_IsLegalAccepted_, context, request);
}

::grpc::ClientAsyncResponseReader< ::viam::app::v1::IsLegalAcceptedResponse>* EndUserService::Stub::AsyncIsLegalAcceptedRaw(::grpc::ClientContext* context, const ::viam::app::v1::IsLegalAcceptedRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncIsLegalAcceptedRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status EndUserService::Stub::AcceptLegal(::grpc::ClientContext* context, const ::viam::app::v1::AcceptLegalRequest& request, ::viam::app::v1::AcceptLegalResponse* response) {
  return ::grpc::internal::BlockingUnaryCall< ::viam::app::v1::AcceptLegalRequest, ::viam::app::v1::AcceptLegalResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_AcceptLegal_, context, request, response);
}

void EndUserService::Stub::async::AcceptLegal(::grpc::ClientContext* context, const ::viam::app::v1::AcceptLegalRequest* request, ::viam::app::v1::AcceptLegalResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::viam::app::v1::AcceptLegalRequest, ::viam::app::v1::AcceptLegalResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_AcceptLegal_, context, request, response, std::move(f));
}

void EndUserService::Stub::async::AcceptLegal(::grpc::ClientContext* context, const ::viam::app::v1::AcceptLegalRequest* request, ::viam::app::v1::AcceptLegalResponse* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_AcceptLegal_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::viam::app::v1::AcceptLegalResponse>* EndUserService::Stub::PrepareAsyncAcceptLegalRaw(::grpc::ClientContext* context, const ::viam::app::v1::AcceptLegalRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::viam::app::v1::AcceptLegalResponse, ::viam::app::v1::AcceptLegalRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_AcceptLegal_, context, request);
}

::grpc::ClientAsyncResponseReader< ::viam::app::v1::AcceptLegalResponse>* EndUserService::Stub::AsyncAcceptLegalRaw(::grpc::ClientContext* context, const ::viam::app::v1::AcceptLegalRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncAcceptLegalRaw(context, request, cq);
  result->StartCall();
  return result;
}

EndUserService::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      EndUserService_method_names[0],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< EndUserService::Service, ::viam::app::v1::IsLegalAcceptedRequest, ::viam::app::v1::IsLegalAcceptedResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](EndUserService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::viam::app::v1::IsLegalAcceptedRequest* req,
             ::viam::app::v1::IsLegalAcceptedResponse* resp) {
               return service->IsLegalAccepted(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      EndUserService_method_names[1],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< EndUserService::Service, ::viam::app::v1::AcceptLegalRequest, ::viam::app::v1::AcceptLegalResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](EndUserService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::viam::app::v1::AcceptLegalRequest* req,
             ::viam::app::v1::AcceptLegalResponse* resp) {
               return service->AcceptLegal(ctx, req, resp);
             }, this)));
}

EndUserService::Service::~Service() {
}

::grpc::Status EndUserService::Service::IsLegalAccepted(::grpc::ServerContext* context, const ::viam::app::v1::IsLegalAcceptedRequest* request, ::viam::app::v1::IsLegalAcceptedResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status EndUserService::Service::AcceptLegal(::grpc::ServerContext* context, const ::viam::app::v1::AcceptLegalRequest* request, ::viam::app::v1::AcceptLegalResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


}  // namespace viam
}  // namespace app
}  // namespace v1
