/*
 * Copyright (c)  RWTH Aachen. All rights reserved.
 *
 * http://www.se-rwth.de/
 */
package montiarc.cocos;

import de.monticore.symboltable.Scope;
import de.se_rwth.commons.logging.Log;
import montiarc._ast.ASTIOAssignment;
import montiarc._ast.ASTValuation;
import montiarc._ast.ASTValueList;
import montiarc._cocos.MontiArcASTIOAssignmentCoCo;
import montiarc._symboltable.VariableSymbol;

import java.util.ArrayList;
import java.util.Optional;

/**
 * Checks that variables don't get assigned the special No Data symbol "--" on transitions.
 *
 * @author Fuerste
 * @implements [Wor16] AT3: The special literal value NoDatais not used for variables.
 */
public class AutomatonNoDataAssignedToVariable  implements MontiArcASTIOAssignmentCoCo {
  @Override public void check(ASTIOAssignment node) {

    ArrayList<ASTValuation> valuations = new ArrayList<>();
    Optional<? extends Scope> scope = node.getEnclosingScope().get().getEnclosingScope()
        .get().getEnclosingScope();
    Scope componentScope = scope.get();

    if (node.isPresentAlternative()) {

      for (ASTValueList astValueList : node.getAlternative().getValueListList()) {
        if (astValueList.isPresentNoData()) {
          if (node.isPresentName()) {

            Optional<VariableSymbol> varsym = componentScope.<VariableSymbol>resolve(
                node.getName(), VariableSymbol.KIND);
            if (varsym.isPresent()) {
              Log.error("0xMA092 Assignment of special value NoData (\"--\") to Variables "
                      + "is not allowed",
                  node.get_SourcePositionEnd());
            }

          }
        }
      }

    }
    else {
      if (node.isPresentValueList() && node.getValueList().isPresentNoData()) {
          Optional<VariableSymbol> varsym = componentScope.<VariableSymbol>resolve(
              node.getName(), VariableSymbol.KIND);
          if (varsym.isPresent()) {
            Log.error("0xMA092 Assignment of special value NoData (\"--\") to Variables is "
                    + "not allowed",
                node.get_SourcePositionEnd());
          }
        }
    }


  }
}