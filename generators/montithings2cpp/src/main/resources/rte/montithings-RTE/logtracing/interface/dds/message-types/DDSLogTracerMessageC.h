// -*- C++ -*-
// $Id$

/**
 * Code generated by the The ACE ORB (TAO) IDL Compiler v2.2a_p19
 * TAO and the TAO IDL Compiler have been developed by:
 *       Center for Distributed Object Computing
 *       Washington University
 *       St. Louis, MO
 *       USA
 *       http://www.cs.wustl.edu/~schmidt/doc-center.html
 * and
 *       Distributed Object Computing Laboratory
 *       University of California at Irvine
 *       Irvine, CA
 *       USA
 * and
 *       Institute for Software Integrated Systems
 *       Vanderbilt University
 *       Nashville, TN
 *       USA
 *       http://www.isis.vanderbilt.edu/
 *
 * Information about TAO is available at:
 *     http://www.cs.wustl.edu/~schmidt/TAO.html
 **/

// TAO_IDL - Generated from
// be/be_codegen.cpp:152

#ifndef _TAO_IDL_DDSLOGTRACERMESSAGEC_H_
#define _TAO_IDL_DDSLOGTRACERMESSAGEC_H_

#include /**/ "ace/pre.h"


#include /**/ "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */


#include "tao/ORB.h"
#include "tao/Basic_Types.h"
#include "tao/String_Manager_T.h"
#include "tao/VarOut_T.h"
#include "tao/Arg_Traits_T.h"
#include "tao/Basic_Arguments.h"
#include "tao/Special_Basic_Arguments.h"
#include "tao/Any_Insert_Policy_T.h"
#include "tao/Basic_Argument_T.h"
#include "tao/Fixed_Size_Argument_T.h"
#include "tao/Var_Size_Argument_T.h"
#include "tao/UB_String_Arguments.h"
#include /**/ "tao/Version.h"
#include /**/ "tao/Versioned_Namespace.h"

#if TAO_MAJOR_VERSION != 2 || TAO_MINOR_VERSION != 2 || TAO_BETA_VERSION != 0
#error This file should be regenerated with TAO_IDL
#endif

#if defined (TAO_EXPORT_MACRO)
#undef TAO_EXPORT_MACRO
#endif
#define TAO_EXPORT_MACRO 

// TAO_IDL - Generated from
// be/be_visitor_module/module_ch.cpp:38

namespace DDSLogTracerMessage
{

  // TAO_IDL - Generated from
  // be/be_visitor_enum/enum_ch.cpp:47

  enum RequestData
  {
    LOG_ENTRIES,
    INTERNAL_DATA
  };

  typedef RequestData &RequestData_out;

  // TAO_IDL - Generated from
  // be/be_type.cpp:261

  struct Request;

  typedef
    ::TAO_Var_Var_T<
        Request
      >
    Request_var;

  typedef
    ::TAO_Out_T<
        Request
      >
    Request_out;

  // TAO_IDL - Generated from
  // be/be_visitor_structure/structure_ch.cpp:51

  struct  Request
  {

    // TAO_IDL - Generated from
    // be/be_type.cpp:307

    
    typedef Request_var _var_type;
    typedef Request_out _out_type;
    
    ::TAO::String_Manager target_instance;
    ::TAO::String_Manager req_uuid;
    ::TAO::String_Manager trace_uuid;
    ::CORBA::Long from_timestamp;
    DDSLogTracerMessage::RequestData req_data;
  };

  // TAO_IDL - Generated from
  // be/be_type.cpp:261

  struct Response;

  typedef
    ::TAO_Var_Var_T<
        Response
      >
    Response_var;

  typedef
    ::TAO_Out_T<
        Response
      >
    Response_out;

  // TAO_IDL - Generated from
  // be/be_visitor_structure/structure_ch.cpp:51

  struct  Response
  {

    // TAO_IDL - Generated from
    // be/be_type.cpp:307

    
    typedef Response_var _var_type;
    typedef Response_out _out_type;
    
    ::TAO::String_Manager req_uuid;
    DDSLogTracerMessage::RequestData req_data;
    ::TAO::String_Manager content;
  };

// TAO_IDL - Generated from
// be/be_visitor_module/module_ch.cpp:67

} // module DDSLogTracerMessage

// TAO_IDL - Generated from
// be/be_visitor_arg_traits.cpp:68

TAO_BEGIN_VERSIONED_NAMESPACE_DECL


// Arg traits specializations.
namespace TAO
{

  // TAO_IDL - Generated from
  // be/be_visitor_arg_traits.cpp:904

  template<>
  class Arg_Traits< ::DDSLogTracerMessage::RequestData>
    : public
        Basic_Arg_Traits_T<
            ::DDSLogTracerMessage::RequestData,
            TAO::Any_Insert_Policy_Noop
          >
  {
  };

  // TAO_IDL - Generated from
  // be/be_visitor_arg_traits.cpp:947

  template<>
  class Arg_Traits< ::DDSLogTracerMessage::Request>
    : public
        Var_Size_Arg_Traits_T<
            ::DDSLogTracerMessage::Request,
            TAO::Any_Insert_Policy_Noop
          >
  {
  };

  // TAO_IDL - Generated from
  // be/be_visitor_arg_traits.cpp:947

  template<>
  class Arg_Traits< ::DDSLogTracerMessage::Response>
    : public
        Var_Size_Arg_Traits_T<
            ::DDSLogTracerMessage::Response,
            TAO::Any_Insert_Policy_Noop
          >
  {
  };
}

TAO_END_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from
// be/be_visitor_traits.cpp:62

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

// Traits specializations.
namespace TAO
{
}
TAO_END_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from
// be/be_visitor_enum/cdr_op_ch.cpp:37


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

 ::CORBA::Boolean operator<< (TAO_OutputCDR &strm, DDSLogTracerMessage::RequestData _tao_enumerator);
 ::CORBA::Boolean operator>> (TAO_InputCDR &strm, DDSLogTracerMessage::RequestData &_tao_enumerator);

TAO_END_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from
// be/be_visitor_structure/cdr_op_ch.cpp:46


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

 ::CORBA::Boolean operator<< (TAO_OutputCDR &, const DDSLogTracerMessage::Request &);
 ::CORBA::Boolean operator>> (TAO_InputCDR &, DDSLogTracerMessage::Request &);

TAO_END_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from
// be/be_visitor_structure/cdr_op_ch.cpp:46


TAO_BEGIN_VERSIONED_NAMESPACE_DECL

 ::CORBA::Boolean operator<< (TAO_OutputCDR &, const DDSLogTracerMessage::Response &);
 ::CORBA::Boolean operator>> (TAO_InputCDR &, DDSLogTracerMessage::Response &);

TAO_END_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from
// be/be_codegen.cpp:1703
#if defined (__ACE_INLINE__)
#include "DDSLogTracerMessageC.inl"
#endif /* defined INLINE */

#include /**/ "ace/post.h"

#endif /* ifndef */

