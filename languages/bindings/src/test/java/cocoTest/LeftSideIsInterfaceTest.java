// (c) https://github.com/MontiCore/monticore
package cocoTest;

import bindings._cocos.BindingsCoCoChecker;
import bindings._cocos.LeftSideIsInterface;
import bindings.util.BindingsError;
import de.se_rwth.commons.logging.Log;
import org.junit.jupiter.api.Test;

import java.util.regex.Pattern;

public class LeftSideIsInterfaceTest extends AbstractTest {

  @Override
  protected Pattern supplyErrorCodePattern() {
    return BindingsError.ERROR_CODE_PATTERN;
  }

  @Test
  void shouldFailWithInvalidBinding() {
    BindingsCoCoChecker checker = new BindingsCoCoChecker().addCoCo(new LeftSideIsInterface());
    checker.checkAll(getAST("cocoTest/interfaceMismatch/WrongModel.mtb"));
    this.checkOnlyExpectedErrorsPresent(Log.getFindings(),
        new BindingsError[] { BindingsError.LEFT_SIDE_NO_INTERFACE});
  }
}