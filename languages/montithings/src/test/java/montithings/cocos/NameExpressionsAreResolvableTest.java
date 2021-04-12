// (c) https://github.com/MontiCore/monticore
package montithings.cocos;

import montithings._cocos.MontiThingsCoCoChecker;
import montithings.util.MontiThingsError;
import org.junit.jupiter.params.provider.Arguments;

import java.util.stream.Stream;

public class NameExpressionsAreResolvableTest extends AbstractCoCoTest {

  protected static MontiThingsCoCoChecker getChecker() {
    return new MontiThingsCoCoChecker()
      .addCoCo(new InterfaceExists())
      .addCoCo(new NameExpressionsAreResolvable());
  }

  protected static Stream<Arguments> validInput() {
    return Stream.of(
      Arguments.of("cocoTest.valid.Source")
    );
  }

  protected static Stream<Arguments> invalidInput() {
    return Stream.of(
      Arguments.of(getChecker(),
        "cocoTest.nameExpressionsAreResolvableTest.unknownVariable.Source",
        1,
        new MontiThingsError[] { MontiThingsError.IDENTIFIER_UNKNOWN }
      ),
      Arguments.of(getChecker(),
        "cocoTest.nameExpressionsAreResolvableTest.variableDefaultUnknown.Source",
        1,
        new MontiThingsError[] { MontiThingsError.IDENTIFIER_UNKNOWN }
      )
    );
  }
}