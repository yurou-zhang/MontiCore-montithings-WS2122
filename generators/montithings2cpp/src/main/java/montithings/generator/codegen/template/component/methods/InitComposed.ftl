<#-- (c) https://github.com/MontiCore/monticore -->
${tc.signature("comp","config","className")}
<#include "/template/component/helper/GeneralPreamble.ftl">

${Utils.printTemplateArguments(comp)}
void ${className}${Utils.printFormalTypeParameters(comp, false)}::init(){
<#if comp.isPresentParentComponent()>
    super.init();
</#if>

<#if config.getSplittingMode().toString() == "OFF">
    <#list comp.getAstNode().getConnectors() as connector>
        <#list connector.getTargetList() as target>
            <#if ComponentHelper.isIncomingPort(comp, target)>
                // implements "${connector.getSource().getQName()} -> ${target.getQName()}"
                ${Utils.printGetPort(target)}->setDataProvidingPort (${Utils.printGetPort(connector.getSource())});
                <#if ComponentHelper.isSIUnitPort(connector.getSource())>
                    ${Utils.printComponentPrefix(target)}getInterface()->setPort${connector.getSource().getPort()?cap_first}ConversionFactor (${ComponentHelper.getConversionFactorFromSourceAndTarget(connector.source, target)?replace(",", ".")});
                </#if>
            </#if>
        </#list>
    </#list>

    <#list comp.getSubComponents() as subcomponent >
        ${subcomponent.getName()}.init();
    </#list>
</#if>
}