/* Generated by /home/luke/Projects/OpenDDS/bin/opendds_idl version 3.15 (ACE version 6.2a_p19) running on input file /home/luke/Projects/montithings/core/generators/montithings2cpp/src/main/resources/rte/montithings-RTE/dds/message-types/DDSMessage.idl */
#include "DDSMessageTypeSupportImpl.h"

#include <cstring>
#include <stdexcept>
#include "dds/DCPS/BuiltInTopicUtils.h"
#include "dds/DCPS/ContentFilteredTopicImpl.h"
#include "dds/DCPS/DataReaderImpl_T.h"
#include "dds/DCPS/DataWriterImpl_T.h"
#include "dds/DCPS/FilterEvaluator.h"
#include "dds/DCPS/MultiTopicDataReader_T.h"
#include "dds/DCPS/PoolAllocator.h"
#include "dds/DCPS/PublicationInstance.h"
#include "dds/DCPS/PublisherImpl.h"
#include "dds/DCPS/Qos_Helper.h"
#include "dds/DCPS/RakeData.h"
#include "dds/DCPS/RakeResults_T.h"
#include "dds/DCPS/ReceivedDataElementList.h"
#include "dds/DCPS/Registered_Data_Types.h"
#include "dds/DCPS/Service_Participant.h"
#include "dds/DCPS/SubscriberImpl.h"
#include "dds/DCPS/Util.h"
#include "dds/DCPS/debug.h"
#include "dds/DdsDcpsDomainC.h"


/* Begin MODULE: CORBA */


/* End MODULE: CORBA */


/* Begin MODULE: DDSMessage */



/* Begin STRUCT: Message */

OPENDDS_BEGIN_VERSIONED_NAMESPACE_DECL
namespace OpenDDS { namespace DCPS {

void gen_find_size(const DDSMessage::Message& stru, size_t& size, size_t& padding)
{
  ACE_UNUSED_ARG(stru);
  ACE_UNUSED_ARG(size);
  ACE_UNUSED_ARG(padding);
  if ((size + padding) % 4) {
    padding += 4 - ((size + padding) % 4);
  }
  size += gen_max_marshaled_size(stru.id);
  find_size_ulong(size, padding);
  size += ACE_OS::strlen(stru.content.in()) + 1;
}

bool operator<<(Serializer& strm, const DDSMessage::Message& stru)
{
  ACE_UNUSED_ARG(strm);
  ACE_UNUSED_ARG(stru);
  return (strm << stru.id)
    && (strm << stru.content.in());
}

bool operator>>(Serializer& strm, DDSMessage::Message& stru)
{
  ACE_UNUSED_ARG(strm);
  ACE_UNUSED_ARG(stru);
  return (strm >> stru.id)
    && (strm >> stru.content.out());
}

size_t gen_max_marshaled_size(const DDSMessage::Message& stru, bool align)
{
  ACE_UNUSED_ARG(stru);
  ACE_UNUSED_ARG(align);
  return 0;
}

size_t gen_max_marshaled_size(KeyOnly<const DDSMessage::Message> stru, bool align)
{
  ACE_UNUSED_ARG(stru);
  ACE_UNUSED_ARG(align);
  return 0;
}

void gen_find_size(KeyOnly<const DDSMessage::Message> stru, size_t& size, size_t& padding)
{
  ACE_UNUSED_ARG(stru);
  ACE_UNUSED_ARG(size);
  ACE_UNUSED_ARG(padding);
}

bool operator<<(Serializer& strm, KeyOnly<const DDSMessage::Message> stru)
{
  ACE_UNUSED_ARG(strm);
  ACE_UNUSED_ARG(stru);
  return true;
}

bool operator>>(Serializer& strm, KeyOnly<DDSMessage::Message> stru)
{
  ACE_UNUSED_ARG(strm);
  ACE_UNUSED_ARG(stru);
  return true;
}

}  }
OPENDDS_END_VERSIONED_NAMESPACE_DECL

OPENDDS_BEGIN_VERSIONED_NAMESPACE_DECL
namespace OpenDDS { namespace DCPS {

void vwrite(OpenDDS::DCPS::ValueWriter& value_writer, const DDSMessage::Message& value)
{
  ACE_UNUSED_ARG(value_writer);
  ACE_UNUSED_ARG(value);
  value_writer.begin_struct();
  value_writer.begin_field("id");
  value_writer.write_int32(value.id);
  value_writer.end_field();
  value_writer.begin_field("content");
  value_writer.write_string(value.content);
  value_writer.end_field();
  value_writer.end_struct();
}

}  }
OPENDDS_END_VERSIONED_NAMESPACE_DECL


namespace DDSMessage {
::DDS::DataWriter_ptr MessageTypeSupportImpl::create_datawriter()
{
  typedef OpenDDS::DCPS::DataWriterImpl_T<Message> DataWriterImplType;
  ::DDS::DataWriter_ptr writer_impl = ::DDS::DataWriter::_nil();
  ACE_NEW_NORETURN(writer_impl,
                   DataWriterImplType());
  return writer_impl;
}

::DDS::DataReader_ptr MessageTypeSupportImpl::create_datareader()
{
  typedef OpenDDS::DCPS::DataReaderImpl_T<Message> DataReaderImplType;
  ::DDS::DataReader_ptr reader_impl = ::DDS::DataReader::_nil();
  ACE_NEW_NORETURN(reader_impl,
                   DataReaderImplType());
  return reader_impl;
}

#ifndef OPENDDS_NO_MULTI_TOPIC
::DDS::DataReader_ptr MessageTypeSupportImpl::create_multitopic_datareader()
{
  typedef OpenDDS::DCPS::DataReaderImpl_T<Message> DataReaderImplType;
  typedef OpenDDS::DCPS::MultiTopicDataReader_T<Message, DataReaderImplType> MultiTopicDataReaderImplType;
  ::DDS::DataReader_ptr multitopic_reader_impl = ::DDS::DataReader::_nil();
  ACE_NEW_NORETURN(multitopic_reader_impl,
                   MultiTopicDataReaderImplType());
  return multitopic_reader_impl;
}
#endif /* !OPENDDS_NO_MULTI_TOPIC */

#ifndef OPENDDS_NO_CONTENT_SUBSCRIPTION_PROFILE
const OpenDDS::DCPS::MetaStruct& MessageTypeSupportImpl::getMetaStructForType()
{
  return OpenDDS::DCPS::getMetaStruct<Message>();
}
#endif /* !OPENDDS_NO_CONTENT_SUBSCRIPTION_PROFILE */

bool MessageTypeSupportImpl::has_dcps_key()
{
  return TraitsType::gen_has_key ();
}

const char* MessageTypeSupportImpl::default_type_name() const
{
  return TraitsType::type_name();
}

MessageTypeSupport::_ptr_type MessageTypeSupportImpl::_narrow(CORBA::Object_ptr obj)
{
  return TypeSupportType::_narrow(obj);
}
}

#ifndef OPENDDS_NO_CONTENT_SUBSCRIPTION_PROFILE
OPENDDS_BEGIN_VERSIONED_NAMESPACE_DECL
namespace OpenDDS { namespace DCPS {

template<>
struct MetaStructImpl<DDSMessage::Message> : MetaStruct {
  typedef DDSMessage::Message T;

#ifndef OPENDDS_NO_MULTI_TOPIC
  void* allocate() const { return new T; }

  void deallocate(void* stru) const { delete static_cast<T*>(stru); }

  size_t numDcpsKeys() const { return 0; }

#endif /* OPENDDS_NO_MULTI_TOPIC */

  bool isDcpsKey(const char* field) const
  {
    ACE_UNUSED_ARG(field);
    return false;
  }

  Value getValue(const void* stru, const char* field) const
  {
    const DDSMessage::Message& typed = *static_cast<const DDSMessage::Message*>(stru);
    ACE_UNUSED_ARG(typed);
    if (std::strcmp(field, "id") == 0) {
      return typed.id;
    }
    if (std::strcmp(field, "content") == 0) {
      return typed.content.in();
    }
    throw std::runtime_error("Field " + OPENDDS_STRING(field) + " not found or its type is not supported (in struct DDSMessage::Message)");
  }

  Value getValue(Serializer& ser, const char* field) const
  {
    if (std::strcmp(field, "id") == 0) {
      ACE_CDR::Long val;
      if (!(ser >> val)) {
        throw std::runtime_error("Field 'id' could not be deserialized");
      }
      return val;
    } else {
      if (!ser.skip(1, 4)) {
        throw std::runtime_error("Field 'id' could not be skipped");
      }
    }
    if (std::strcmp(field, "content") == 0) {
      TAO::String_Manager val;
      if (!(ser >> val.out())) {
        throw std::runtime_error("Field 'content' could not be deserialized");
      }
      return val;
    } else {
      ACE_CDR::ULong len;
      if (!(ser >> len)) {
        throw std::runtime_error("String 'content' length could not be deserialized");
      }
      if (!ser.skip(static_cast<ACE_UINT16>(len))) {
        throw std::runtime_error("String 'content' contents could not be skipped");
      }
    }
    if (!field[0]) {
      return 0;
    }
    throw std::runtime_error("Field " + OPENDDS_STRING(field) + " not valid for struct DDSMessage::Message");
  }

  ComparatorBase::Ptr create_qc_comparator(const char* field, ComparatorBase::Ptr next) const
  {
    ACE_UNUSED_ARG(next);
    if (std::strcmp(field, "id") == 0) {
      return make_field_cmp(&T::id, next);
    }
    if (std::strcmp(field, "content") == 0) {
      return make_field_cmp(&T::content, next);
    }
    throw std::runtime_error("Field " + OPENDDS_STRING(field) + " not found or its type is not supported (in struct DDSMessage::Message)");
  }

#ifndef OPENDDS_NO_MULTI_TOPIC
  const char** getFieldNames() const
  {
    static const char* names[] = {"id", "content", 0};
    return names;
  }

  const void* getRawField(const void* stru, const char* field) const
  {
    if (std::strcmp(field, "id") == 0) {
      return &static_cast<const T*>(stru)->id;
    }
    if (std::strcmp(field, "content") == 0) {
      return &static_cast<const T*>(stru)->content;
    }
    throw std::runtime_error("Field " + OPENDDS_STRING(field) + " not found or its type is not supported (in struct DDSMessage::Message)");
  }

  void assign(void* lhs, const char* field, const void* rhs,
    const char* rhsFieldSpec, const MetaStruct& rhsMeta) const
  {
    ACE_UNUSED_ARG(lhs);
    ACE_UNUSED_ARG(field);
    ACE_UNUSED_ARG(rhs);
    ACE_UNUSED_ARG(rhsFieldSpec);
    ACE_UNUSED_ARG(rhsMeta);
    if (std::strcmp(field, "id") == 0) {
      static_cast<T*>(lhs)->id = *static_cast<const CORBA::Long*>(rhsMeta.getRawField(rhs, rhsFieldSpec));
      return;
    }
    if (std::strcmp(field, "content") == 0) {
      static_cast<T*>(lhs)->content = *static_cast<const TAO::String_Manager*>(rhsMeta.getRawField(rhs, rhsFieldSpec));
      return;
    }
    throw std::runtime_error("Field " + OPENDDS_STRING(field) + " not found or its type is not supported (in struct DDSMessage::Message)");
  }
#endif /* OPENDDS_NO_MULTI_TOPIC */

  bool compare(const void* lhs, const void* rhs, const char* field) const
  {
    ACE_UNUSED_ARG(lhs);
    ACE_UNUSED_ARG(field);
    ACE_UNUSED_ARG(rhs);
    if (std::strcmp(field, "id") == 0) {
      return static_cast<const T*>(lhs)->id == static_cast<const T*>(rhs)->id;
    }
    if (std::strcmp(field, "content") == 0) {
      return 0 == ACE_OS::strcmp(static_cast<const T*>(lhs)->content.in(), static_cast<const T*>(rhs)->content.in());
    }
    throw std::runtime_error("Field " + OPENDDS_STRING(field) + " not found or its type is not supported (in struct DDSMessage::Message)");
  }
};

template<>
const MetaStruct& getMetaStruct<DDSMessage::Message>()
{
  static MetaStructImpl<DDSMessage::Message> msi;
  return msi;
}

bool gen_skip_over(Serializer& ser, DDSMessage::Message*)
{
  ACE_UNUSED_ARG(ser);
  MetaStructImpl<DDSMessage::Message>().getValue(ser, "");
  return true;
}

}  }
OPENDDS_END_VERSIONED_NAMESPACE_DECL

#endif

/* End STRUCT: Message */

/* End MODULE: DDSMessage */