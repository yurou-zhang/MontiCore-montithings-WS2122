package de.monticore.lang.montiarc.ajava;

import java.nio.file.Paths;

import de.monticore.ModelingLanguageFamily;
import de.monticore.automaton.ioautomaton.JavaHelper;
import de.monticore.io.paths.ModelPath;
import de.monticore.lang.montiarc.ajava._symboltable.AJavaLanguageFamily;
import de.monticore.symboltable.GlobalScope;
import de.monticore.symboltable.Scope;

public class AbstractSymtabTest {
  protected static Scope createSymTab(String modelPath) {
    ModelingLanguageFamily fam = new AJavaLanguageFamily();
    final ModelPath mp = new ModelPath(Paths.get(modelPath), Paths.get("src/main/resources/defaultTypes"));
    GlobalScope scope = new GlobalScope(mp, fam);
    JavaHelper.addJavaPrimitiveTypes(scope);
    return scope;
  }
}