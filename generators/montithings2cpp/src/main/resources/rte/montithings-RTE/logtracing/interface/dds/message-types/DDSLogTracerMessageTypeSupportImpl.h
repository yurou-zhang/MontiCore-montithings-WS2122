/* -*- C++ -*- */
// (c) https://github.com/MontiCore/monticore
/* Generated by /home/luke/Projects/OpenDDS/bin/opendds_idl version 3.15 (ACE version 6.2a_p19) running on input file /home/luke/Projects/montithings/core/generators/montithings2cpp/src/main/resources/rte/montithings-RTE/logtracing/interface/dds/message-types/DDSLogTracerMessage.idl */
#ifndef OPENDDS_IDL_GENERATED_DDSLOGTRACERMESSAGETYPESUPPORTIMPL_H_UGZG6X
#define OPENDDS_IDL_GENERATED_DDSLOGTRACERMESSAGETYPESUPPORTIMPL_H_UGZG6X
#include "DDSLogTracerMessageC.h"
#include "dds/DCPS/Definitions.h"
#include "dds/DdsDcpsC.h"
#include "DDSLogTracerMessageTypeSupportC.h"
#include "dds/DCPS/Serializer.h"
#include "dds/DCPS/TypeSupportImpl.h"
#include "dds/DCPS/ValueWriter.h"


/* Begin MODULE: CORBA */


/* End MODULE: CORBA */


/* Begin MODULE: DDSLogTracerMessage */



/* Begin ENUM: RequestData */

OPENDDS_BEGIN_VERSIONED_NAMESPACE_DECL
namespace OpenDDS { namespace DCPS {

bool operator<<(Serializer& strm, const DDSLogTracerMessage::RequestData& enumval);

bool operator>>(Serializer& strm, DDSLogTracerMessage::RequestData& enumval);

}  }
OPENDDS_END_VERSIONED_NAMESPACE_DECL

OPENDDS_BEGIN_VERSIONED_NAMESPACE_DECL
namespace OpenDDS { namespace DCPS {

void vwrite(OpenDDS::DCPS::ValueWriter& value_writer, const DDSLogTracerMessage::RequestData& value);

}  }
OPENDDS_END_VERSIONED_NAMESPACE_DECL

OPENDDS_BEGIN_VERSIONED_NAMESPACE_DECL
namespace OpenDDS { namespace DCPS {

extern const char* gen_DDSLogTracerMessage_RequestData_names[];
extern const size_t gen_DDSLogTracerMessage_RequestData_names_size;
}  }
OPENDDS_END_VERSIONED_NAMESPACE_DECL


/* End ENUM: RequestData */


/* Begin STRUCT: Request */

OPENDDS_BEGIN_VERSIONED_NAMESPACE_DECL
namespace OpenDDS { namespace DCPS {

void gen_find_size(const DDSLogTracerMessage::Request& stru, size_t& size, size_t& padding);

bool operator<<(Serializer& strm, const DDSLogTracerMessage::Request& stru);

bool operator>>(Serializer& strm, DDSLogTracerMessage::Request& stru);

size_t gen_max_marshaled_size(const DDSLogTracerMessage::Request& stru, bool align);

size_t gen_max_marshaled_size(KeyOnly<const DDSLogTracerMessage::Request> stru, bool align);

void gen_find_size(KeyOnly<const DDSLogTracerMessage::Request> stru, size_t& size, size_t& padding);

bool operator<<(Serializer& strm, KeyOnly<const DDSLogTracerMessage::Request> stru);

bool operator>>(Serializer& strm, KeyOnly<DDSLogTracerMessage::Request> stru);

template <>
struct MarshalTraits<DDSLogTracerMessage::Request> {
  static bool gen_is_bounded_size() { return false; }
  static bool gen_is_bounded_key_size() { return false; }
  static bool to_message_block(ACE_Message_Block&, const DDSLogTracerMessage::Request&) { return false; }
  static bool from_message_block(DDSLogTracerMessage::Request&, const ACE_Message_Block&) { return false; }
};
}  }
OPENDDS_END_VERSIONED_NAMESPACE_DECL


namespace DDSLogTracerMessage {
/// This structure supports use of std::map with one or more keys.
struct  Request_OpenDDS_KeyLessThan {
  bool operator()(const DDSLogTracerMessage::Request& v1, const DDSLogTracerMessage::Request& v2) const
  {
    using ::operator<; // TAO::String_Manager's operator< is in global NS
    if (v1.target_instance < v2.target_instance) return true;
    if (v2.target_instance < v1.target_instance) return false;
    return false;
  }
};
}

OPENDDS_BEGIN_VERSIONED_NAMESPACE_DECL
namespace OpenDDS { namespace DCPS {

void vwrite(OpenDDS::DCPS::ValueWriter& value_writer, const DDSLogTracerMessage::Request& value);

}  }
OPENDDS_END_VERSIONED_NAMESPACE_DECL


namespace DDSLogTracerMessage {
class RequestTypeSupportImpl;
}

OPENDDS_BEGIN_VERSIONED_NAMESPACE_DECL
namespace OpenDDS { namespace DCPS {
template <>
struct DDSTraits<DDSLogTracerMessage::Request> {
  typedef DDSLogTracerMessage::Request MessageType;
  typedef DDSLogTracerMessage::RequestSeq MessageSequenceType;
  typedef DDSLogTracerMessage::RequestTypeSupport TypeSupportType;
  typedef DDSLogTracerMessage::RequestTypeSupportImpl TypeSupportTypeImpl;
  typedef DDSLogTracerMessage::RequestDataWriter DataWriterType;
  typedef DDSLogTracerMessage::RequestDataReader DataReaderType;
  typedef DDSLogTracerMessage::Request_OpenDDS_KeyLessThan LessThanType;

  static const char* type_name () { return "DDSLogTracerMessage::Request"; }
  static bool gen_has_key () { return true; }
  static size_t key_count () { return 1; }

  static size_t gen_max_marshaled_size(const MessageType& x, bool align) { return ::OpenDDS::DCPS::gen_max_marshaled_size(x, align); }
  static void gen_find_size(const MessageType& arr, size_t& size, size_t& padding) { ::OpenDDS::DCPS::gen_find_size(arr, size, padding); }

  static size_t gen_max_marshaled_size(const OpenDDS::DCPS::KeyOnly<const MessageType>& x, bool align) { return ::OpenDDS::DCPS::gen_max_marshaled_size(x, align); }
  static void gen_find_size(const OpenDDS::DCPS::KeyOnly<const MessageType>& arr, size_t& size, size_t& padding) { ::OpenDDS::DCPS::gen_find_size(arr, size, padding); }
};
}  }
OPENDDS_END_VERSIONED_NAMESPACE_DECL


namespace DDSLogTracerMessage {
class  RequestTypeSupportImpl
  : public virtual OpenDDS::DCPS::LocalObject<RequestTypeSupport>
  , public virtual OpenDDS::DCPS::TypeSupportImpl
{
public:
  typedef OpenDDS::DCPS::DDSTraits<Request> TraitsType;
  typedef RequestTypeSupport TypeSupportType;
  typedef RequestTypeSupport::_var_type _var_type;
  typedef RequestTypeSupport::_ptr_type _ptr_type;

  RequestTypeSupportImpl() {}
  virtual ~RequestTypeSupportImpl() {}

  virtual ::DDS::DataWriter_ptr create_datawriter();
  virtual ::DDS::DataReader_ptr create_datareader();
#ifndef OPENDDS_NO_MULTI_TOPIC
  virtual ::DDS::DataReader_ptr create_multitopic_datareader();
#endif /* !OPENDDS_NO_MULTI_TOPIC */
#ifndef OPENDDS_NO_CONTENT_SUBSCRIPTION_PROFILE
  virtual const OpenDDS::DCPS::MetaStruct& getMetaStructForType();
#endif /* !OPENDDS_NO_CONTENT_SUBSCRIPTION_PROFILE */
  virtual bool has_dcps_key();
  const char* default_type_name() const;
  static RequestTypeSupport::_ptr_type _narrow(CORBA::Object_ptr obj);
};
}

#ifndef OPENDDS_NO_CONTENT_SUBSCRIPTION_PROFILE
OPENDDS_BEGIN_VERSIONED_NAMESPACE_DECL
namespace OpenDDS { namespace DCPS {

class MetaStruct;

template<typename T>
const MetaStruct& getMetaStruct();

template<>
const MetaStruct& getMetaStruct<DDSLogTracerMessage::Request>();
bool gen_skip_over(Serializer& ser, DDSLogTracerMessage::Request*);

}  }
OPENDDS_END_VERSIONED_NAMESPACE_DECL

#endif

/* End STRUCT: Request */


/* Begin STRUCT: Response */

OPENDDS_BEGIN_VERSIONED_NAMESPACE_DECL
namespace OpenDDS { namespace DCPS {

void gen_find_size(const DDSLogTracerMessage::Response& stru, size_t& size, size_t& padding);

bool operator<<(Serializer& strm, const DDSLogTracerMessage::Response& stru);

bool operator>>(Serializer& strm, DDSLogTracerMessage::Response& stru);

size_t gen_max_marshaled_size(const DDSLogTracerMessage::Response& stru, bool align);

size_t gen_max_marshaled_size(KeyOnly<const DDSLogTracerMessage::Response> stru, bool align);

void gen_find_size(KeyOnly<const DDSLogTracerMessage::Response> stru, size_t& size, size_t& padding);

bool operator<<(Serializer& strm, KeyOnly<const DDSLogTracerMessage::Response> stru);

bool operator>>(Serializer& strm, KeyOnly<DDSLogTracerMessage::Response> stru);

template <>
struct MarshalTraits<DDSLogTracerMessage::Response> {
  static bool gen_is_bounded_size() { return false; }
  static bool gen_is_bounded_key_size() { return true; }
  static bool to_message_block(ACE_Message_Block&, const DDSLogTracerMessage::Response&) { return false; }
  static bool from_message_block(DDSLogTracerMessage::Response&, const ACE_Message_Block&) { return false; }
};
}  }
OPENDDS_END_VERSIONED_NAMESPACE_DECL


namespace DDSLogTracerMessage {
/// This structure supports use of std::map with one or more keys.
struct  Response_OpenDDS_KeyLessThan {
  bool operator()(const DDSLogTracerMessage::Response&, const DDSLogTracerMessage::Response&) const
  {
    // With no keys, return false to allow use of
    // map with just one entry
    return false;
  }
};
}

OPENDDS_BEGIN_VERSIONED_NAMESPACE_DECL
namespace OpenDDS { namespace DCPS {

void vwrite(OpenDDS::DCPS::ValueWriter& value_writer, const DDSLogTracerMessage::Response& value);

}  }
OPENDDS_END_VERSIONED_NAMESPACE_DECL


namespace DDSLogTracerMessage {
class ResponseTypeSupportImpl;
}

OPENDDS_BEGIN_VERSIONED_NAMESPACE_DECL
namespace OpenDDS { namespace DCPS {
template <>
struct DDSTraits<DDSLogTracerMessage::Response> {
  typedef DDSLogTracerMessage::Response MessageType;
  typedef DDSLogTracerMessage::ResponseSeq MessageSequenceType;
  typedef DDSLogTracerMessage::ResponseTypeSupport TypeSupportType;
  typedef DDSLogTracerMessage::ResponseTypeSupportImpl TypeSupportTypeImpl;
  typedef DDSLogTracerMessage::ResponseDataWriter DataWriterType;
  typedef DDSLogTracerMessage::ResponseDataReader DataReaderType;
  typedef DDSLogTracerMessage::Response_OpenDDS_KeyLessThan LessThanType;

  static const char* type_name () { return "DDSLogTracerMessage::Response"; }
  static bool gen_has_key () { return false; }
  static size_t key_count () { return 0; }

  static size_t gen_max_marshaled_size(const MessageType& x, bool align) { return ::OpenDDS::DCPS::gen_max_marshaled_size(x, align); }
  static void gen_find_size(const MessageType& arr, size_t& size, size_t& padding) { ::OpenDDS::DCPS::gen_find_size(arr, size, padding); }

  static size_t gen_max_marshaled_size(const OpenDDS::DCPS::KeyOnly<const MessageType>& x, bool align) { return ::OpenDDS::DCPS::gen_max_marshaled_size(x, align); }
  static void gen_find_size(const OpenDDS::DCPS::KeyOnly<const MessageType>& arr, size_t& size, size_t& padding) { ::OpenDDS::DCPS::gen_find_size(arr, size, padding); }
};
}  }
OPENDDS_END_VERSIONED_NAMESPACE_DECL


namespace DDSLogTracerMessage {
class  ResponseTypeSupportImpl
  : public virtual OpenDDS::DCPS::LocalObject<ResponseTypeSupport>
  , public virtual OpenDDS::DCPS::TypeSupportImpl
{
public:
  typedef OpenDDS::DCPS::DDSTraits<Response> TraitsType;
  typedef ResponseTypeSupport TypeSupportType;
  typedef ResponseTypeSupport::_var_type _var_type;
  typedef ResponseTypeSupport::_ptr_type _ptr_type;

  ResponseTypeSupportImpl() {}
  virtual ~ResponseTypeSupportImpl() {}

  virtual ::DDS::DataWriter_ptr create_datawriter();
  virtual ::DDS::DataReader_ptr create_datareader();
#ifndef OPENDDS_NO_MULTI_TOPIC
  virtual ::DDS::DataReader_ptr create_multitopic_datareader();
#endif /* !OPENDDS_NO_MULTI_TOPIC */
#ifndef OPENDDS_NO_CONTENT_SUBSCRIPTION_PROFILE
  virtual const OpenDDS::DCPS::MetaStruct& getMetaStructForType();
#endif /* !OPENDDS_NO_CONTENT_SUBSCRIPTION_PROFILE */
  virtual bool has_dcps_key();
  const char* default_type_name() const;
  static ResponseTypeSupport::_ptr_type _narrow(CORBA::Object_ptr obj);
};
}

#ifndef OPENDDS_NO_CONTENT_SUBSCRIPTION_PROFILE
OPENDDS_BEGIN_VERSIONED_NAMESPACE_DECL
namespace OpenDDS { namespace DCPS {

template<>
const MetaStruct& getMetaStruct<DDSLogTracerMessage::Response>();
bool gen_skip_over(Serializer& ser, DDSLogTracerMessage::Response*);

}  }
OPENDDS_END_VERSIONED_NAMESPACE_DECL

#endif

/* End STRUCT: Response */

/* End MODULE: DDSLogTracerMessage */
#endif /* OPENDDS_IDL_GENERATED_DDSLOGTRACERMESSAGETYPESUPPORTIMPL_H_UGZG6X */
