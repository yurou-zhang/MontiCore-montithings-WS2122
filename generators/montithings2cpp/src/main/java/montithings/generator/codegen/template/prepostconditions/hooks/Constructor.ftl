<#-- (c) https://github.com/MontiCore/monticore -->
${tc.signature("comp")}
<#include "/template/Preamble.ftl">

<#assign preconditions = ComponentHelper.getPreconditions(comp)>
<#if preconditions?size gt 0>
  <#list 1..preconditions?size as i>
    this->preconditions.emplace (new ${compname}Precondition${i} (this->instanceName));
  </#list>
</#if>
<#assign postconditions = ComponentHelper.getPostconditions(comp)>
<#if postconditions?size gt 0>
  <#list 1..postconditions?size as i>
    this->postconditions.emplace (new ${compname}Postcondition${i}${generics} (this->instanceName));
  </#list>
</#if>