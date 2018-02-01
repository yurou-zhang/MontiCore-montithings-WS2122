package components.body.automaton.transition.guards;

import org.junit.BeforeClass;
import org.junit.Test;

import de.se_rwth.commons.logging.Log;
import infrastructure.AbstractCoCoTest;
import infrastructure.ExpectedErrorInfo;
import montiarc._ast.ASTMontiArcNode;
import montiarc.cocos.MontiArcCoCos;

/**
 * This class checks all context conditions related to automaton guards
 *
 * @author Andreas Wortmann
 */
public class GuardTests extends AbstractCoCoTest {
  
  private static final String MP = "";
  
  private static final String PACKAGE = "components.body.automaton.transition.guards";
  
  @BeforeClass
  public static void setUp() {
    Log.enableFailQuick(false);
  }
  
  @Test
  public void testGuardIsBoolean() {
    checkValid(MP, PACKAGE + "." + "GuardIsBoolean");
  }
  
  @Test
  public void testGuardNotBoolean() {
    ASTMontiArcNode node = getAstNode(MP, PACKAGE + "." + "GuardNotBoolean");
    checkInvalid(MontiArcCoCos.createChecker(), node,
        new ExpectedErrorInfo(3, "xMA036"));
  }
  
  @Test
  public void testGuardWithInstanceOfExpression() {
    ASTMontiArcNode node = getAstNode(MP, PACKAGE + "." + "GuardWithInstanceOfExpression");
    // 1 Error because the models contains an ASTInstanceOfExpression
    checkInvalid(MontiArcCoCos.createChecker(), node,
        new ExpectedErrorInfo(1, "xMA023"));
  }
  
  @Test
  public void testGuardUsesOutgoingPort() {
    ASTMontiArcNode node = getAstNode(MP, PACKAGE + "." + "GuardUsesOutgoingPort");
    checkInvalid(MontiArcCoCos.createChecker(),node, new ExpectedErrorInfo(4, "xMA022"));
  }
  
}