<#-- (c) https://github.com/MontiCore/monticore -->
${tc.signature("comp","config","isMonitor","className")}
<#include "/template/component/helper/GeneralPreamble.ftl">

${className}Result${Utils.printFormalTypeParameters(comp)} result;
<#list comp.getAllOutgoingPorts() as outPort>
    if (${Identifier.getInterfaceName()}.getPort${outPort.getName()?cap_first}()->hasValue(<#if isMonitor>portMonitorUuid${outPort.getName()?cap_first}
<#else>
    this->uuid
</#if>)) {
    result.set${outPort.getName()?cap_first}(${Identifier.getInterfaceName()}.getPort${outPort.getName()?cap_first}()->getCurrentValue(<#if isMonitor>portMonitorUuid${outPort.getName()?cap_first}

<#else>
    this->uuid
</#if>)->getPayload().value());
    }
</#list>