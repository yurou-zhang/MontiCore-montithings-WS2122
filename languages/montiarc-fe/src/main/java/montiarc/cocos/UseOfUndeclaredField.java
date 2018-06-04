package montiarc.cocos;

import de.monticore.ast.ASTNode;
import de.monticore.java.javadsl._ast.ASTExpression;
import de.monticore.java.javadsl._ast.ASTPrimaryExpression;
import de.monticore.java.javadsl._cocos.JavaDSLASTPrimaryExpressionCoCo;
import de.monticore.java.javadsl._visitor.JavaDSLVisitor;
import de.monticore.java.symboltable.JavaTypeSymbol;
import de.monticore.symboltable.Scope;
import de.monticore.symboltable.Symbol;
import de.se_rwth.commons.logging.Log;
import montiarc._ast.ASTGuardExpression;
import montiarc._ast.ASTIOAssignment;
import montiarc._ast.ASTPort;
import montiarc._ast.ASTVariableDeclaration;
import montiarc._cocos.MontiArcASTGuardExpressionCoCo;
import montiarc._cocos.MontiArcASTIOAssignmentCoCo;
import montiarc._symboltable.PortSymbol;
import montiarc._symboltable.VariableSymbol;

import java.util.Collection;
import java.util.Optional;

/**
 * Context condition for checking, if a reference is used inside an automaton which has not been
 * defined in an {@link ASTVariableDeclaration} or as {@link ASTPort}.
 *
 * @implements [Wor16] AR1: Names used in guards, valuations, and assignments exist in the
 * automaton. (p. 102, Lst. 5.19)
 * @author Gerrit Leonhardt, Andreas Wortmann, Michael Mutert
 */
public class UseOfUndeclaredField
    implements MontiArcASTIOAssignmentCoCo, MontiArcASTGuardExpressionCoCo {
  
  @Override
  public void check(ASTIOAssignment node) {
    // only check left side of IOAssignment, right side is implicitly checked
    // when resolving type of the valuations
    if(node.getName().isPresent()) {
      check(node.getName().get(), node, "assignment");
    }
  }

  /**
   * Private common helper function that is used to check whether a used field
   * by the given name exists.
   * @param name Name of the field
   * @param node Node object of the field
   * @param usage Environment in which the field is used (used in the log)
   */
  private void check(String name, ASTNode node, String usage) {
    if (node.getEnclosingScope().isPresent()) {
      Scope scope = node.getEnclosingScope().get();
      boolean foundVar = scope.resolve(name, VariableSymbol.KIND).isPresent();
      boolean foundPort = scope.resolve(name, PortSymbol.KIND).isPresent();
      final Optional<JavaTypeSymbol> typeSymbolOpt
          = scope.resolve(name, JavaTypeSymbol.KIND);
      boolean foundEnum = false;
      if(typeSymbolOpt.isPresent()) {
        foundEnum = typeSymbolOpt.get().isEnum();
      }
      if (!foundVar && !foundPort && !foundEnum) {
        Log.error(
            String.format("0xMA079: The name '%s' is used in %s, but is " +
                              "neither declared a port, nor as a variable.",
                name, usage),
            node.get_SourcePositionStart());
      }
    }
  }

  @Override
  public void check(ASTGuardExpression node) {
    node.getExpression().accept(new GuardVisitor());
  }

  /**
   * This class is used to check whether names used in GuardExpressions are
   * declared.
   */
  private class GuardVisitor implements JavaDSLVisitor{

    @Override
    public void visit(ASTPrimaryExpression node){

      if (node.getName().isPresent()) {
        check(node.getName().get(), node, "guard");
      }
    }
  }

}
