// (c) https://github.com/MontiCore/monticore
package montithings.generator.codegen.xtend.behavior

import montithings._symboltable.ComponentSymbol
import montithings.generator.codegen.xtend.util.Utils
import montithings.generator.codegen.xtend.util.Identifier
import montithings.generator.helper.ComponentHelper

class AtomicComponentStandardImplementation {
	def static generateAbstractAtomicImplementationHeader(ComponentSymbol comp, String compname) {
    var String generics = Utils.printFormalTypeParameters(comp)
    return '''
#pragma once
#include "«compname»Input.h"
#include "«compname»Result.h"
#include "IComputable.h"
#include <stdexcept>
«Utils.printCPPImports(comp)»

«Utils.printNamespaceStart(comp)»

«Utils.printTemplateArguments(comp)»
class «compname»Impl : IComputable<«compname»Input«generics»,«compname»Result«generics»>{
	
private:  
    «Utils.printVariables(comp)»
    «Utils.printConfigParameters(comp)»
    
public:
    «printConstructor(comp)»
	//«compname»Impl() = default;
	«compname»Result«generics» getInitialValues() override;
	«IF ComponentHelper.getExecutionStatements(comp).size > 0»
	«FOR statement : ComponentHelper.getExecutionStatements(comp)»
	«compname»Result«generics» «statement.method»(«compname»Input«generics» input);
	«ENDFOR»
	«compname»Result«generics» «ComponentHelper.getElseStatement(comp).get.method»(«compname»Input«generics» input);
	«compname»Result«generics» compute(«compname»Input«generics» input) override {
	  throw std::runtime_error("Invoking compute() on component «comp.packageName».«compname» which has if-then-else behavior");
	}
	«ELSE»
	«compname»Result«generics» compute(«compname»Input«generics» input) override;
	«ENDIF»
};

«IF Utils.hasTypeParameters(comp)»
	«generateAbstractAtomicImplementationBody(comp, compname)»
«ENDIF»
«Utils.printNamespaceEnd(comp)»
'''
  }
  
  def static String generateImplementationFile(ComponentSymbol comp, String compname) {
	  return '''
	#include "«compname»Impl.h"
	«Utils.printNamespaceStart(comp)»
	«IF !Utils.hasTypeParameters(comp)»
	«generateAbstractAtomicImplementationBody(comp, compname)»
	«ENDIF»
	«Utils.printNamespaceEnd(comp)»
	'''
  }
  
  	def static generateAbstractAtomicImplementationBody(ComponentSymbol comp, String compname) {
    var String generics = Utils.printFormalTypeParameters(comp)
    return '''
«Utils.printTemplateArguments(comp)»
«compname»Result«generics» «compname»Impl«generics»::getInitialValues(){
	throw std::runtime_error("Invoking getInitialValues() on abstract implementation «comp.packageName».«compname»");
}

«IF ComponentHelper.getExecutionStatements(comp).size > 0»
	«FOR statement : ComponentHelper.getExecutionStatements(comp)»
		«Utils.printTemplateArguments(comp)»
		«compname»Result«generics» «compname»Impl«generics»::«statement.method»(«compname»Input«generics» «Identifier.inputName»){
			throw std::runtime_error("Invoking «statement.method»() on abstract implementation «comp.packageName».«compname»");  	
		}
		
	«ENDFOR»
	«Utils.printTemplateArguments(comp)»
	«compname»Result«generics» «compname»Impl«generics»::«ComponentHelper.getElseStatement(comp).get.method»(«compname»Input«generics» «Identifier.inputName»){
		throw std::runtime_error("Invoking «ComponentHelper.getElseStatement(comp).get.method»() on abstract implementation «comp.packageName».«compname»");
	}
«ELSE»
«Utils.printTemplateArguments(comp)»
«compname»Result«generics» «compname»Impl«generics»::compute(«compname»Input«generics» «Identifier.inputName»){
	throw std::runtime_error("Invoking compute() on abstract implementation «comp.packageName».«compname»");  	
}
«ENDIF»
'''
  }
  
    def static String printConstructor(ComponentSymbol comp) {
    return '''
«comp.name»Impl(«Utils.printConfigurationParametersAsList(comp)»)
«IF !comp.configParameters.isEmpty»
:
«ENDIF»
«FOR param : comp.configParameters SEPARATOR ','»
    «param.name» («param.name»)
«ENDFOR»
{
}
'''

  }
	
}