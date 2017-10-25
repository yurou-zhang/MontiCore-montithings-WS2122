/*
 * Copyright (c) 2016 RWTH Aachen. All rights reserved.
 *
 * http://www.se-rwth.de/
 */
package montiarc.cocos;

import java.util.Optional;

import de.monticore.symboltable.Scope;
import de.monticore.types.TypesPrinter;
import de.se_rwth.commons.logging.Log;
import montiarc._ast.ASTSubComponent;
import montiarc._cocos.MontiArcASTSubComponentCoCo;
import montiarc._symboltable.ComponentSymbol;

/**
 * Implements R3 and R4 from AHs PhD thesis
 *
 * This CoCo is not activated, since the symbol table will error out if the sub component does not exist.
 * Should only be activated if the symbol table is modified to not give out an error anymore.
 *
 * @author Crispin Kirchner
 */
public class ReferencedSubComponentExists implements MontiArcASTSubComponentCoCo {
  
  /**
   * @see montiarc._cocos.MontiArcASTComponentBodyCoCo#check(montiarc._ast.ASTComponentBody)
   */
  @Override
  public void check(ASTSubComponent node) {
    String referenceName = TypesPrinter.printTypeWithoutTypeArgumentsAndDimension(node.getType());
    
    Scope scope = node.getEnclosingScope().get();
    
    Optional<ComponentSymbol> componentSymbol = scope
        .<ComponentSymbol> resolve(referenceName, ComponentSymbol.KIND);
    
    if (!componentSymbol.isPresent()) {
      Log.error(String.format("0xMA004 Type \"%s\" could not be resolved", referenceName),
          node.get_SourcePositionStart());
    }
  }
  
}
