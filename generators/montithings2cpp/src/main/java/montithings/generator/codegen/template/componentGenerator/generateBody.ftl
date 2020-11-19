<#-- (c) https://github.com/MontiCore/monticore -->
${tc.signature("comp","compname","config")}
<#assign ComponentHelper = tc.instantiate("montithings.generator.helper.ComponentHelper")>
<#assign Utils = tc.instantiate("montithings.generator.codegen.util.Utils")>
<#assign Identifier = tc.instantiate("montithings.generator.codegen.util.Identifier")>
<#assign Names = tc.instantiate("de.se_rwth.commons.Names")>

${tc.includeArgs("template.util.ports.printMethodBodies", [comp.getPorts(), comp, compname, config])}

<#if comp.isDecomposed()>
    <#if config.getSplittingMode().toString() != "OFF">
        ${tc.includeArgs("template.util.subcomponents.printMethodDefinitions", [comp, config])}
    </#if>

    <#if ComponentHelper.isTimesync(comp) && !ComponentHelper.isApplication(comp)>
        ${tc.includeArgs("template.componentGenerator.printRun", [comp, compname])}
    </#if>
    ${tc.includeArgs("template.componentGenerator.printComputeDecomposed", [comp, compname, config])}
    ${tc.includeArgs("template.componentGenerator.printStartDecomposed", [comp, compname, config])}
<#else>
    ${tc.includeArgs("template.componentGenerator.printComputeAtomic", [comp, compname])}
    ${tc.includeArgs("template.componentGenerator.printStartAtomic", [comp, compname])}
    ${tc.includeArgs("template.componentGenerator.printRun", [comp, compname])}

    ${Utils.printTemplateArguments(comp)}
    void ${compname}${Utils.printFormalTypeParameters(comp)}::initialize(){
    <#list comp.incomingPorts as port >
        getPort${port.getName()?cap_first} ()->registerListeningPort (this->getUuid ());
        <#assign additionalPort = config.getAdditionalPort(port)>
        <#if additionalPort!="Optional.empty">
            <#assign type = ComponentHelper.getRealPortCppTypeString(port.getComponent().get(), port, config)>
            addInPort${port.getName()?cap_first}(new ${Names.getSimpleName(additionalPort.get())?cap_first}<${type}>());
        </#if>
    </#list>
    <#list comp.outgoingPorts as port >
        <#assign additionalPort = config.getAdditionalPort(port)>
        <#if additionalPort!="Optional.empty">
            <#assign type = ComponentHelper.getRealPortCppTypeString(port.getComponent().get(), port, config)>
            addOutPort${port.getName()?cap_first}(new ${Names.getSimpleName(additionalPort.get())?cap_first}<${type}>());
        </#if>
    </#list>
    <#if ComponentHelper.retainState(comp)>
      if (!${Identifier.getBehaviorImplName()}.restoreState ())
    </#if>
    {
    ${compname}Result${Utils.printFormalTypeParameters(comp)} result = ${Identifier.getBehaviorImplName()}.getInitialValues();
    setResult(result);
    }
    }

    ${Utils.printTemplateArguments(comp)}
    void ${compname}${Utils.printFormalTypeParameters(comp)}::setResult(${compname}Result${Utils.printFormalTypeParameters(comp)} result){
    <#list comp.getOutgoingPorts() as portOut >
        this->getPort${portOut.getName()?cap_first}()->setNextValue(result.get${portOut.getName()?cap_first}());
    </#list>
    }
</#if>

${tc.includeArgs("template.componentGenerator.printShouldComputeCheck", [comp, compname])}

${tc.includeArgs("template.util.setup.Setup", [comp, compname, config])}

${tc.includeArgs("template.util.init.Init", [comp, compname, config])}

<#if config.getMessageBroker().toString() == "MQTT">
  ${tc.includeArgs("template.componentGenerator.printPublishConnectors", [comp, config])}

  ${tc.includeArgs("template.componentGenerator.printOnMessage", [comp, config])}
</#if>

${tc.includeArgs("template.componentGenerator.printConstructor", [comp, compname, config])}