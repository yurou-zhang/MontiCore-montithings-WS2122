/* -*- C++ -*- */
// (c) https://github.com/MontiCore/monticore
/* Generated by /home/luke/Projects/OpenDDS/bin/opendds_idl version 3.15 (ACE version 6.2a_p19) running on input file /home/luke/Projects/montithings/core/generators/montithings2cpp/src/main/resources/rte/montithings-RTE/dds/message-types/DDSMessage.idl */
#ifndef OPENDDS_IDL_GENERATED_DDSMESSAGETYPESUPPORTIMPL_H_FIFCK6
#define OPENDDS_IDL_GENERATED_DDSMESSAGETYPESUPPORTIMPL_H_FIFCK6
#include "DDSMessageC.h"
#include "dds/DCPS/Definitions.h"
#include "dds/DdsDcpsC.h"
#include "DDSMessageTypeSupportC.h"
#include "dds/DCPS/Serializer.h"
#include "dds/DCPS/TypeSupportImpl.h"
#include "dds/DCPS/ValueWriter.h"


/* Begin MODULE: CORBA */


/* End MODULE: CORBA */


/* Begin MODULE: DDSMessage */



/* Begin STRUCT: Message */

OPENDDS_BEGIN_VERSIONED_NAMESPACE_DECL
namespace OpenDDS { namespace DCPS {

void gen_find_size(const DDSMessage::Message& stru, size_t& size, size_t& padding);

bool operator<<(Serializer& strm, const DDSMessage::Message& stru);

bool operator>>(Serializer& strm, DDSMessage::Message& stru);

size_t gen_max_marshaled_size(const DDSMessage::Message& stru, bool align);

size_t gen_max_marshaled_size(KeyOnly<const DDSMessage::Message> stru, bool align);

void gen_find_size(KeyOnly<const DDSMessage::Message> stru, size_t& size, size_t& padding);

bool operator<<(Serializer& strm, KeyOnly<const DDSMessage::Message> stru);

bool operator>>(Serializer& strm, KeyOnly<DDSMessage::Message> stru);

template <>
struct MarshalTraits<DDSMessage::Message> {
  static bool gen_is_bounded_size() { return false; }
  static bool gen_is_bounded_key_size() { return true; }
  static bool to_message_block(ACE_Message_Block&, const DDSMessage::Message&) { return false; }
  static bool from_message_block(DDSMessage::Message&, const ACE_Message_Block&) { return false; }
};
}  }
OPENDDS_END_VERSIONED_NAMESPACE_DECL


namespace DDSMessage {
/// This structure supports use of std::map with one or more keys.
struct  Message_OpenDDS_KeyLessThan {
  bool operator()(const DDSMessage::Message&, const DDSMessage::Message&) const
  {
    // With no keys, return false to allow use of
    // map with just one entry
    return false;
  }
};
}

OPENDDS_BEGIN_VERSIONED_NAMESPACE_DECL
namespace OpenDDS { namespace DCPS {

void vwrite(OpenDDS::DCPS::ValueWriter& value_writer, const DDSMessage::Message& value);

}  }
OPENDDS_END_VERSIONED_NAMESPACE_DECL


namespace DDSMessage {
class MessageTypeSupportImpl;
}

OPENDDS_BEGIN_VERSIONED_NAMESPACE_DECL
namespace OpenDDS { namespace DCPS {
template <>
struct DDSTraits<DDSMessage::Message> {
  typedef DDSMessage::Message MessageType;
  typedef DDSMessage::MessageSeq MessageSequenceType;
  typedef DDSMessage::MessageTypeSupport TypeSupportType;
  typedef DDSMessage::MessageTypeSupportImpl TypeSupportTypeImpl;
  typedef DDSMessage::MessageDataWriter DataWriterType;
  typedef DDSMessage::MessageDataReader DataReaderType;
  typedef DDSMessage::Message_OpenDDS_KeyLessThan LessThanType;

  static const char* type_name () { return "DDSMessage::Message"; }
  static bool gen_has_key () { return false; }
  static size_t key_count () { return 0; }

  static size_t gen_max_marshaled_size(const MessageType& x, bool align) { return ::OpenDDS::DCPS::gen_max_marshaled_size(x, align); }
  static void gen_find_size(const MessageType& arr, size_t& size, size_t& padding) { ::OpenDDS::DCPS::gen_find_size(arr, size, padding); }

  static size_t gen_max_marshaled_size(const OpenDDS::DCPS::KeyOnly<const MessageType>& x, bool align) { return ::OpenDDS::DCPS::gen_max_marshaled_size(x, align); }
  static void gen_find_size(const OpenDDS::DCPS::KeyOnly<const MessageType>& arr, size_t& size, size_t& padding) { ::OpenDDS::DCPS::gen_find_size(arr, size, padding); }
};
}  }
OPENDDS_END_VERSIONED_NAMESPACE_DECL


namespace DDSMessage {
class  MessageTypeSupportImpl
  : public virtual OpenDDS::DCPS::LocalObject<MessageTypeSupport>
  , public virtual OpenDDS::DCPS::TypeSupportImpl
{
public:
  typedef OpenDDS::DCPS::DDSTraits<Message> TraitsType;
  typedef MessageTypeSupport TypeSupportType;
  typedef MessageTypeSupport::_var_type _var_type;
  typedef MessageTypeSupport::_ptr_type _ptr_type;

  MessageTypeSupportImpl() {}
  virtual ~MessageTypeSupportImpl() {}

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
  static MessageTypeSupport::_ptr_type _narrow(CORBA::Object_ptr obj);
};
}

#ifndef OPENDDS_NO_CONTENT_SUBSCRIPTION_PROFILE
OPENDDS_BEGIN_VERSIONED_NAMESPACE_DECL
namespace OpenDDS { namespace DCPS {

class MetaStruct;

template<typename T>
const MetaStruct& getMetaStruct();

template<>
const MetaStruct& getMetaStruct<DDSMessage::Message>();
bool gen_skip_over(Serializer& ser, DDSMessage::Message*);

}  }
OPENDDS_END_VERSIONED_NAMESPACE_DECL

#endif

/* End STRUCT: Message */

/* End MODULE: DDSMessage */
#endif /* OPENDDS_IDL_GENERATED_DDSMESSAGETYPESUPPORTIMPL_H_FIFCK6 */