/*
 * Copyright (c) 2015 RWTH Aachen. All rights reserved.
 *
 * http://www.se-rwth.de/
 */
package montiarc._symboltable;

import de.monticore.symboltable.resolving.CommonResolvingFilter;
import de.monticore.symboltable.types.JFieldSymbol;
import de.monticore.symboltable.types.JMethodSymbol;
import de.monticore.symboltable.types.JTypeSymbol;
import montiarc._symboltable.adapters.CDFieldSymbol2JavaFieldFilter;
import montiarc._symboltable.adapters.CDTypeSymbol2JavaTypeFilter;

//XXX: https://git.rwth-aachen.de/montiarc/core/issues/51

/**
 * The MontiArc Language
 *
 * @author Robert Heim, Andreas Wortmann
 */
public class MontiArcLanguage extends MontiArcLanguageTOP {
  
  public static final String FILE_ENDING = "arc";
  
  public MontiArcLanguage() {
    super("MontiArc Language", FILE_ENDING);
  }
  
  @Override
  protected void initResolvingFilters() {
    super.initResolvingFilters();
    // is done in generated TOP-language addResolver(new
    // CommonResolvingFilter<ComponentSymbol>(ComponentSymbol.class,
    // ComponentSymbol.KIND));
    addResolver(new CommonResolvingFilter<ComponentInstanceSymbol>(ComponentInstanceSymbol.KIND));
    addResolver(new CommonResolvingFilter<PortSymbol>(PortSymbol.KIND));
    addResolver(new CommonResolvingFilter<ConnectorSymbol>(ConnectorSymbol.KIND));
    addResolver(new CommonResolvingFilter<VariableSymbol>(VariableSymbol.KIND));
    addResolver(new CommonResolvingFilter<AutomatonSymbol>(AutomatonSymbol.KIND));
    
    
    // Java/P
    addResolver(new CommonResolvingFilter<>(JavaBehaviorSymbol.KIND));
    
    addResolver(CommonResolvingFilter.create(JTypeSymbol.KIND));
    addResolver(CommonResolvingFilter.create(JFieldSymbol.KIND));
    addResolver(CommonResolvingFilter.create(JMethodSymbol.KIND));

    
    // I/O Automaton
    addResolver(new CommonResolvingFilter<StateSymbol>(StateSymbol.KIND));
    addResolver(new TransitionResolvingFilter());
    addResolver(new Variable2FieldResolvingFilter());
    addResolver(new Port2FieldResolvingFilter());
    
    //TODO enable to resolve type arguments of subcomponents
    addResolver(new CDTypeSymbol2JavaTypeFilter());
    addResolver(new CDFieldSymbol2JavaFieldFilter());

    setModelNameCalculator(new MontiArcModelNameCalculator());
  }
  
  @Override
  protected MontiArcModelLoader provideModelLoader() {
    return new MontiArcModelLoader(this);
  }
  
}