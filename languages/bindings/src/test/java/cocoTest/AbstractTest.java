// (c) https://github.com/MontiCore/monticore
package cocoTest;

import bindings.BindingsTool;
import bindings._ast.ASTBindingsCompilationUnit;
import bindings._parser.BindingsParser;
import bindings._symboltable.IBindingsGlobalScope;
import bindings.util.Error;
import de.se_rwth.commons.logging.Finding;
import de.se_rwth.commons.logging.Log;
import de.se_rwth.commons.logging.LogStub;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.BeforeAll;
import org.junit.jupiter.api.BeforeEach;

import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.List;
import java.util.regex.Matcher;
import java.util.regex.Pattern;
import java.util.stream.Collectors;

public abstract class AbstractTest {

  protected Pattern errorCodePattern;

  @BeforeAll
  public static void cleanUpLog() {
    Log.getFindings().clear();
    Log.enableFailQuick(false);
    LogStub.init();
  }

  @BeforeEach
  public void setUp() {
    Log.getFindings().clear();
    errorCodePattern = supplyErrorCodePattern();
    assert errorCodePattern != null;
  }

  protected abstract Pattern supplyErrorCodePattern();

  protected Pattern getErrorCodePattern() {
    return errorCodePattern;
  }

  protected void checkExpectedErrorsPresent(List<Finding> findings,
    Error[] expErrors) {
    List<String> actualErrorCodes = collectErrorCodes(findings);
    List<String> expErrorCodes = collectErrorCodes(expErrors);

    Assertions.assertTrue(actualErrorCodes.containsAll(expErrorCodes), String.format("Expected "
      + "error codes: " + expErrorCodes.toString() + " Actual error codes: "
      + actualErrorCodes.toString()));
  }

  protected void checkNoAdditionalErrorsPresent(List<Finding> findings,
    Error[] expErrors) {
    List<String> actualErrorCodes = collectErrorCodes(findings);
    List<String> expErrorCodes = collectErrorCodes(expErrors);

    actualErrorCodes.removeAll(expErrorCodes);

    Assertions.assertEquals(0, actualErrorCodes.size());
  }

  protected void checkOnlyExpectedErrorsPresent(List<Finding> findings,
    Error[] expErrors) {
    checkExpectedErrorsPresent(findings, expErrors);
    checkNoAdditionalErrorsPresent(findings, expErrors);
  }

  protected List<String> collectErrorCodes(Error[] errors) {
    return Arrays.stream(errors)
      .map(Error::getErrorCode)
      .collect(Collectors.toList());
  }

  protected List<String> collectErrorCodes(List<Finding> findings) {
    return findings.stream()
      .map(f -> collectErrorCodes(f.getMsg()))
      .flatMap(Collection::stream)
      .collect(Collectors.toList());
  }

  protected List<String> collectErrorCodes(String msg) {
    List<String> errorCodes = new ArrayList<>();
    Matcher matcher = getErrorCodePattern().matcher(msg);
    while (matcher.find()) {
      errorCodes.add(matcher.group());
    }
    return errorCodes;
  }

  public ASTBindingsCompilationUnit getAST(String modelPath, String fileName) {
    ASTBindingsCompilationUnit bindingsAST = null;
    try {
      bindingsAST = new BindingsParser().parseBindingsCompilationUnit(modelPath + fileName).orElse(null);
    }
    catch (IOException e) {
      Log.error("File '" + modelPath + fileName + "' Bindings artifact was not found");
    }
    Assertions.assertNotNull(bindingsAST);
    BindingsTool tool = new BindingsTool();
    IBindingsGlobalScope sc = tool.createSymboltable(bindingsAST, new File(modelPath));
    System.out.println(sc);
    return bindingsAST;
  }
}