// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: friend.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_friend_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_friend_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3011000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3011000 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/service.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_friend_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_friend_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxillaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[3]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_friend_2eproto;
namespace fix {
class getFriendListRequest;
class getFriendListRequestDefaultTypeInternal;
extern getFriendListRequestDefaultTypeInternal _getFriendListRequest_default_instance_;
class getFriendListResponse;
class getFriendListResponseDefaultTypeInternal;
extern getFriendListResponseDefaultTypeInternal _getFriendListResponse_default_instance_;
class resultCode;
class resultCodeDefaultTypeInternal;
extern resultCodeDefaultTypeInternal _resultCode_default_instance_;
}  // namespace fix
PROTOBUF_NAMESPACE_OPEN
template<> ::fix::getFriendListRequest* Arena::CreateMaybeMessage<::fix::getFriendListRequest>(Arena*);
template<> ::fix::getFriendListResponse* Arena::CreateMaybeMessage<::fix::getFriendListResponse>(Arena*);
template<> ::fix::resultCode* Arena::CreateMaybeMessage<::fix::resultCode>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace fix {

// ===================================================================

class getFriendListRequest :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:fix.getFriendListRequest) */ {
 public:
  getFriendListRequest();
  virtual ~getFriendListRequest();

  getFriendListRequest(const getFriendListRequest& from);
  getFriendListRequest(getFriendListRequest&& from) noexcept
    : getFriendListRequest() {
    *this = ::std::move(from);
  }

  inline getFriendListRequest& operator=(const getFriendListRequest& from) {
    CopyFrom(from);
    return *this;
  }
  inline getFriendListRequest& operator=(getFriendListRequest&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const getFriendListRequest& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const getFriendListRequest* internal_default_instance() {
    return reinterpret_cast<const getFriendListRequest*>(
               &_getFriendListRequest_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(getFriendListRequest& a, getFriendListRequest& b) {
    a.Swap(&b);
  }
  inline void Swap(getFriendListRequest* other) {
    if (other == this) return;
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline getFriendListRequest* New() const final {
    return CreateMaybeMessage<getFriendListRequest>(nullptr);
  }

  getFriendListRequest* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<getFriendListRequest>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const getFriendListRequest& from);
  void MergeFrom(const getFriendListRequest& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(getFriendListRequest* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "fix.getFriendListRequest";
  }
  private:
  inline ::PROTOBUF_NAMESPACE_ID::Arena* GetArenaNoVirtual() const {
    return nullptr;
  }
  inline void* MaybeArenaPtr() const {
    return nullptr;
  }
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_friend_2eproto);
    return ::descriptor_table_friend_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kIdFieldNumber = 1,
  };
  // uint32 id = 1;
  void clear_id();
  ::PROTOBUF_NAMESPACE_ID::uint32 id() const;
  void set_id(::PROTOBUF_NAMESPACE_ID::uint32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::uint32 _internal_id() const;
  void _internal_set_id(::PROTOBUF_NAMESPACE_ID::uint32 value);
  public:

  // @@protoc_insertion_point(class_scope:fix.getFriendListRequest)
 private:
  class _Internal;

  ::PROTOBUF_NAMESPACE_ID::internal::InternalMetadataWithArena _internal_metadata_;
  ::PROTOBUF_NAMESPACE_ID::uint32 id_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_friend_2eproto;
};
// -------------------------------------------------------------------

class resultCode :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:fix.resultCode) */ {
 public:
  resultCode();
  virtual ~resultCode();

  resultCode(const resultCode& from);
  resultCode(resultCode&& from) noexcept
    : resultCode() {
    *this = ::std::move(from);
  }

  inline resultCode& operator=(const resultCode& from) {
    CopyFrom(from);
    return *this;
  }
  inline resultCode& operator=(resultCode&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const resultCode& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const resultCode* internal_default_instance() {
    return reinterpret_cast<const resultCode*>(
               &_resultCode_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(resultCode& a, resultCode& b) {
    a.Swap(&b);
  }
  inline void Swap(resultCode* other) {
    if (other == this) return;
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline resultCode* New() const final {
    return CreateMaybeMessage<resultCode>(nullptr);
  }

  resultCode* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<resultCode>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const resultCode& from);
  void MergeFrom(const resultCode& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(resultCode* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "fix.resultCode";
  }
  private:
  inline ::PROTOBUF_NAMESPACE_ID::Arena* GetArenaNoVirtual() const {
    return nullptr;
  }
  inline void* MaybeArenaPtr() const {
    return nullptr;
  }
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_friend_2eproto);
    return ::descriptor_table_friend_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kErrmsgFieldNumber = 2,
    kErrorFieldNumber = 1,
  };
  // bytes errmsg = 2;
  void clear_errmsg();
  const std::string& errmsg() const;
  void set_errmsg(const std::string& value);
  void set_errmsg(std::string&& value);
  void set_errmsg(const char* value);
  void set_errmsg(const void* value, size_t size);
  std::string* mutable_errmsg();
  std::string* release_errmsg();
  void set_allocated_errmsg(std::string* errmsg);
  private:
  const std::string& _internal_errmsg() const;
  void _internal_set_errmsg(const std::string& value);
  std::string* _internal_mutable_errmsg();
  public:

  // uint32 error = 1;
  void clear_error();
  ::PROTOBUF_NAMESPACE_ID::uint32 error() const;
  void set_error(::PROTOBUF_NAMESPACE_ID::uint32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::uint32 _internal_error() const;
  void _internal_set_error(::PROTOBUF_NAMESPACE_ID::uint32 value);
  public:

  // @@protoc_insertion_point(class_scope:fix.resultCode)
 private:
  class _Internal;

  ::PROTOBUF_NAMESPACE_ID::internal::InternalMetadataWithArena _internal_metadata_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr errmsg_;
  ::PROTOBUF_NAMESPACE_ID::uint32 error_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_friend_2eproto;
};
// -------------------------------------------------------------------

class getFriendListResponse :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:fix.getFriendListResponse) */ {
 public:
  getFriendListResponse();
  virtual ~getFriendListResponse();

  getFriendListResponse(const getFriendListResponse& from);
  getFriendListResponse(getFriendListResponse&& from) noexcept
    : getFriendListResponse() {
    *this = ::std::move(from);
  }

  inline getFriendListResponse& operator=(const getFriendListResponse& from) {
    CopyFrom(from);
    return *this;
  }
  inline getFriendListResponse& operator=(getFriendListResponse&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const getFriendListResponse& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const getFriendListResponse* internal_default_instance() {
    return reinterpret_cast<const getFriendListResponse*>(
               &_getFriendListResponse_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    2;

  friend void swap(getFriendListResponse& a, getFriendListResponse& b) {
    a.Swap(&b);
  }
  inline void Swap(getFriendListResponse* other) {
    if (other == this) return;
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline getFriendListResponse* New() const final {
    return CreateMaybeMessage<getFriendListResponse>(nullptr);
  }

  getFriendListResponse* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<getFriendListResponse>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const getFriendListResponse& from);
  void MergeFrom(const getFriendListResponse& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(getFriendListResponse* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "fix.getFriendListResponse";
  }
  private:
  inline ::PROTOBUF_NAMESPACE_ID::Arena* GetArenaNoVirtual() const {
    return nullptr;
  }
  inline void* MaybeArenaPtr() const {
    return nullptr;
  }
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_friend_2eproto);
    return ::descriptor_table_friend_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kFriendFieldNumber = 2,
    kResulecodeFieldNumber = 1,
  };
  // repeated bytes friend = 2;
  int friend__size() const;
  private:
  int _internal_friend__size() const;
  public:
  void clear_friend_();
  const std::string& friend_(int index) const;
  std::string* mutable_friend_(int index);
  void set_friend_(int index, const std::string& value);
  void set_friend_(int index, std::string&& value);
  void set_friend_(int index, const char* value);
  void set_friend_(int index, const void* value, size_t size);
  std::string* add_friend_();
  void add_friend_(const std::string& value);
  void add_friend_(std::string&& value);
  void add_friend_(const char* value);
  void add_friend_(const void* value, size_t size);
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string>& friend_() const;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string>* mutable_friend_();
  private:
  const std::string& _internal_friend_(int index) const;
  std::string* _internal_add_friend_();
  public:

  // .fix.resultCode resulecode = 1;
  bool has_resulecode() const;
  private:
  bool _internal_has_resulecode() const;
  public:
  void clear_resulecode();
  const ::fix::resultCode& resulecode() const;
  ::fix::resultCode* release_resulecode();
  ::fix::resultCode* mutable_resulecode();
  void set_allocated_resulecode(::fix::resultCode* resulecode);
  private:
  const ::fix::resultCode& _internal_resulecode() const;
  ::fix::resultCode* _internal_mutable_resulecode();
  public:

  // @@protoc_insertion_point(class_scope:fix.getFriendListResponse)
 private:
  class _Internal;

  ::PROTOBUF_NAMESPACE_ID::internal::InternalMetadataWithArena _internal_metadata_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string> friend__;
  ::fix::resultCode* resulecode_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_friend_2eproto;
};
// ===================================================================

class friendServiceRpc_Stub;

class friendServiceRpc : public ::PROTOBUF_NAMESPACE_ID::Service {
 protected:
  // This class should be treated as an abstract interface.
  inline friendServiceRpc() {};
 public:
  virtual ~friendServiceRpc();

  typedef friendServiceRpc_Stub Stub;

  static const ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor* descriptor();

  virtual void getFriendList(::PROTOBUF_NAMESPACE_ID::RpcController* controller,
                       const ::fix::getFriendListRequest* request,
                       ::fix::getFriendListResponse* response,
                       ::google::protobuf::Closure* done);

  // implements Service ----------------------------------------------

  const ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor* GetDescriptor();
  void CallMethod(const ::PROTOBUF_NAMESPACE_ID::MethodDescriptor* method,
                  ::PROTOBUF_NAMESPACE_ID::RpcController* controller,
                  const ::PROTOBUF_NAMESPACE_ID::Message* request,
                  ::PROTOBUF_NAMESPACE_ID::Message* response,
                  ::google::protobuf::Closure* done);
  const ::PROTOBUF_NAMESPACE_ID::Message& GetRequestPrototype(
    const ::PROTOBUF_NAMESPACE_ID::MethodDescriptor* method) const;
  const ::PROTOBUF_NAMESPACE_ID::Message& GetResponsePrototype(
    const ::PROTOBUF_NAMESPACE_ID::MethodDescriptor* method) const;

 private:
  GOOGLE_DISALLOW_EVIL_CONSTRUCTORS(friendServiceRpc);
};

class friendServiceRpc_Stub : public friendServiceRpc {
 public:
  friendServiceRpc_Stub(::PROTOBUF_NAMESPACE_ID::RpcChannel* channel);
  friendServiceRpc_Stub(::PROTOBUF_NAMESPACE_ID::RpcChannel* channel,
                   ::PROTOBUF_NAMESPACE_ID::Service::ChannelOwnership ownership);
  ~friendServiceRpc_Stub();

  inline ::PROTOBUF_NAMESPACE_ID::RpcChannel* channel() { return channel_; }

  // implements friendServiceRpc ------------------------------------------

  void getFriendList(::PROTOBUF_NAMESPACE_ID::RpcController* controller,
                       const ::fix::getFriendListRequest* request,
                       ::fix::getFriendListResponse* response,
                       ::google::protobuf::Closure* done);
 private:
  ::PROTOBUF_NAMESPACE_ID::RpcChannel* channel_;
  bool owns_channel_;
  GOOGLE_DISALLOW_EVIL_CONSTRUCTORS(friendServiceRpc_Stub);
};


// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// getFriendListRequest

// uint32 id = 1;
inline void getFriendListRequest::clear_id() {
  id_ = 0u;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 getFriendListRequest::_internal_id() const {
  return id_;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 getFriendListRequest::id() const {
  // @@protoc_insertion_point(field_get:fix.getFriendListRequest.id)
  return _internal_id();
}
inline void getFriendListRequest::_internal_set_id(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  
  id_ = value;
}
inline void getFriendListRequest::set_id(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  _internal_set_id(value);
  // @@protoc_insertion_point(field_set:fix.getFriendListRequest.id)
}

// -------------------------------------------------------------------

// resultCode

// uint32 error = 1;
inline void resultCode::clear_error() {
  error_ = 0u;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 resultCode::_internal_error() const {
  return error_;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 resultCode::error() const {
  // @@protoc_insertion_point(field_get:fix.resultCode.error)
  return _internal_error();
}
inline void resultCode::_internal_set_error(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  
  error_ = value;
}
inline void resultCode::set_error(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  _internal_set_error(value);
  // @@protoc_insertion_point(field_set:fix.resultCode.error)
}

// bytes errmsg = 2;
inline void resultCode::clear_errmsg() {
  errmsg_.ClearToEmptyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline const std::string& resultCode::errmsg() const {
  // @@protoc_insertion_point(field_get:fix.resultCode.errmsg)
  return _internal_errmsg();
}
inline void resultCode::set_errmsg(const std::string& value) {
  _internal_set_errmsg(value);
  // @@protoc_insertion_point(field_set:fix.resultCode.errmsg)
}
inline std::string* resultCode::mutable_errmsg() {
  // @@protoc_insertion_point(field_mutable:fix.resultCode.errmsg)
  return _internal_mutable_errmsg();
}
inline const std::string& resultCode::_internal_errmsg() const {
  return errmsg_.GetNoArena();
}
inline void resultCode::_internal_set_errmsg(const std::string& value) {
  
  errmsg_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value);
}
inline void resultCode::set_errmsg(std::string&& value) {
  
  errmsg_.SetNoArena(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:fix.resultCode.errmsg)
}
inline void resultCode::set_errmsg(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  errmsg_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:fix.resultCode.errmsg)
}
inline void resultCode::set_errmsg(const void* value, size_t size) {
  
  errmsg_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:fix.resultCode.errmsg)
}
inline std::string* resultCode::_internal_mutable_errmsg() {
  
  return errmsg_.MutableNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline std::string* resultCode::release_errmsg() {
  // @@protoc_insertion_point(field_release:fix.resultCode.errmsg)
  
  return errmsg_.ReleaseNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline void resultCode::set_allocated_errmsg(std::string* errmsg) {
  if (errmsg != nullptr) {
    
  } else {
    
  }
  errmsg_.SetAllocatedNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), errmsg);
  // @@protoc_insertion_point(field_set_allocated:fix.resultCode.errmsg)
}

// -------------------------------------------------------------------

// getFriendListResponse

// .fix.resultCode resulecode = 1;
inline bool getFriendListResponse::_internal_has_resulecode() const {
  return this != internal_default_instance() && resulecode_ != nullptr;
}
inline bool getFriendListResponse::has_resulecode() const {
  return _internal_has_resulecode();
}
inline void getFriendListResponse::clear_resulecode() {
  if (GetArenaNoVirtual() == nullptr && resulecode_ != nullptr) {
    delete resulecode_;
  }
  resulecode_ = nullptr;
}
inline const ::fix::resultCode& getFriendListResponse::_internal_resulecode() const {
  const ::fix::resultCode* p = resulecode_;
  return p != nullptr ? *p : *reinterpret_cast<const ::fix::resultCode*>(
      &::fix::_resultCode_default_instance_);
}
inline const ::fix::resultCode& getFriendListResponse::resulecode() const {
  // @@protoc_insertion_point(field_get:fix.getFriendListResponse.resulecode)
  return _internal_resulecode();
}
inline ::fix::resultCode* getFriendListResponse::release_resulecode() {
  // @@protoc_insertion_point(field_release:fix.getFriendListResponse.resulecode)
  
  ::fix::resultCode* temp = resulecode_;
  resulecode_ = nullptr;
  return temp;
}
inline ::fix::resultCode* getFriendListResponse::_internal_mutable_resulecode() {
  
  if (resulecode_ == nullptr) {
    auto* p = CreateMaybeMessage<::fix::resultCode>(GetArenaNoVirtual());
    resulecode_ = p;
  }
  return resulecode_;
}
inline ::fix::resultCode* getFriendListResponse::mutable_resulecode() {
  // @@protoc_insertion_point(field_mutable:fix.getFriendListResponse.resulecode)
  return _internal_mutable_resulecode();
}
inline void getFriendListResponse::set_allocated_resulecode(::fix::resultCode* resulecode) {
  ::PROTOBUF_NAMESPACE_ID::Arena* message_arena = GetArenaNoVirtual();
  if (message_arena == nullptr) {
    delete resulecode_;
  }
  if (resulecode) {
    ::PROTOBUF_NAMESPACE_ID::Arena* submessage_arena = nullptr;
    if (message_arena != submessage_arena) {
      resulecode = ::PROTOBUF_NAMESPACE_ID::internal::GetOwnedMessage(
          message_arena, resulecode, submessage_arena);
    }
    
  } else {
    
  }
  resulecode_ = resulecode;
  // @@protoc_insertion_point(field_set_allocated:fix.getFriendListResponse.resulecode)
}

// repeated bytes friend = 2;
inline int getFriendListResponse::_internal_friend__size() const {
  return friend__.size();
}
inline int getFriendListResponse::friend__size() const {
  return _internal_friend__size();
}
inline void getFriendListResponse::clear_friend_() {
  friend__.Clear();
}
inline std::string* getFriendListResponse::add_friend_() {
  // @@protoc_insertion_point(field_add_mutable:fix.getFriendListResponse.friend)
  return _internal_add_friend_();
}
inline const std::string& getFriendListResponse::_internal_friend_(int index) const {
  return friend__.Get(index);
}
inline const std::string& getFriendListResponse::friend_(int index) const {
  // @@protoc_insertion_point(field_get:fix.getFriendListResponse.friend)
  return _internal_friend_(index);
}
inline std::string* getFriendListResponse::mutable_friend_(int index) {
  // @@protoc_insertion_point(field_mutable:fix.getFriendListResponse.friend)
  return friend__.Mutable(index);
}
inline void getFriendListResponse::set_friend_(int index, const std::string& value) {
  // @@protoc_insertion_point(field_set:fix.getFriendListResponse.friend)
  friend__.Mutable(index)->assign(value);
}
inline void getFriendListResponse::set_friend_(int index, std::string&& value) {
  // @@protoc_insertion_point(field_set:fix.getFriendListResponse.friend)
  friend__.Mutable(index)->assign(std::move(value));
}
inline void getFriendListResponse::set_friend_(int index, const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  friend__.Mutable(index)->assign(value);
  // @@protoc_insertion_point(field_set_char:fix.getFriendListResponse.friend)
}
inline void getFriendListResponse::set_friend_(int index, const void* value, size_t size) {
  friend__.Mutable(index)->assign(
    reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:fix.getFriendListResponse.friend)
}
inline std::string* getFriendListResponse::_internal_add_friend_() {
  return friend__.Add();
}
inline void getFriendListResponse::add_friend_(const std::string& value) {
  friend__.Add()->assign(value);
  // @@protoc_insertion_point(field_add:fix.getFriendListResponse.friend)
}
inline void getFriendListResponse::add_friend_(std::string&& value) {
  friend__.Add(std::move(value));
  // @@protoc_insertion_point(field_add:fix.getFriendListResponse.friend)
}
inline void getFriendListResponse::add_friend_(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  friend__.Add()->assign(value);
  // @@protoc_insertion_point(field_add_char:fix.getFriendListResponse.friend)
}
inline void getFriendListResponse::add_friend_(const void* value, size_t size) {
  friend__.Add()->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_add_pointer:fix.getFriendListResponse.friend)
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string>&
getFriendListResponse::friend_() const {
  // @@protoc_insertion_point(field_list:fix.getFriendListResponse.friend)
  return friend__;
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField<std::string>*
getFriendListResponse::mutable_friend_() {
  // @@protoc_insertion_point(field_mutable_list:fix.getFriendListResponse.friend)
  return &friend__;
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace fix

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_friend_2eproto
