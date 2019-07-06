/*
 * Copyright (c) 2017 RWTH Aachen. All rights reserved.
 *
 * http://www.se-rwth.de/
 */
package montiarc;

import java.io.File;
import java.io.IOException;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.Optional;
import java.util.Set;

import com.google.common.collect.Sets;

import de.monticore.ModelingLanguageFamily;
import de.monticore.io.paths.ModelPath;
import de.monticore.symboltable.GlobalScope;
import de.monticore.symboltable.Scope;
import de.se_rwth.commons.logging.Log;
import montiarc._ast.ASTMACompilationUnit;
import montiarc._ast.ASTMontiArcNode;
import montiarc._cocos.MontiArcCoCoChecker;
import montiarc._parser.MontiArcParser;
import montiarc._symboltable.ComponentSymbol;
import montiarc._symboltable.MontiArcLanguageFamily;
import montiarc.cocos.MontiArcCoCos;
import montiarc.helper.JavaDefaultTypesManager;

/**
 * MontiArcTool
 *
 * @author Pfeiffer, Wortmann
 * @version $Revision$, $Date$
 */
public class MontiArcTool {
  
  protected ModelingLanguageFamily family;
  
  protected MontiArcCoCoChecker checker;
  
  private boolean isSymTabInitialized;
  
  /**
   * Constructor for montiarc.MontiArcTool
   */
  public MontiArcTool() {
    this(new MontiArcLanguageFamily(), MontiArcCoCos.createChecker());
  }
  
  /**
   * Constructor for montiarc.MontiArcTool
   */
  public MontiArcTool(ModelingLanguageFamily fam) {
    this(fam, MontiArcCoCos.createChecker());
  }
  
  /**
   * Constructor for montiarc.MontiArcTool
   */
  public MontiArcTool(ModelingLanguageFamily fam, MontiArcCoCoChecker checker) {
    this.family = fam;
    this.checker = checker;
    isSymTabInitialized = false;
  }
  
  public Optional<ASTMACompilationUnit> parse(String filename) {
    MontiArcParser p = new MontiArcParser();
    Optional<ASTMACompilationUnit> compUnit;
    try {
      compUnit = p.parse(filename);
      return compUnit;
    }
    catch (IOException e) {
      e.printStackTrace();
    }
    return Optional.empty();
    
  }
  
  /**
   * Executes CoCos on MontiArcNode
   * 
   * @param node
   * @return true if no errors occurred
   */
  public boolean checkCoCos(ASTMontiArcNode node) {
    if (!isSymTabInitialized) {
      Log.error("Symtab has to be initialized before checking CoCos");
      return false;
    }
    if (!node.getSymbolOpt().isPresent() && !node.getSpannedScopeOpt().isPresent()) {
      Log.error(
          "Symtab is not linked with passed node! Call getSymbol() or getASTNode() for getting the ast.");
    }
    
    checker.checkAll(node);
    if (Log.getErrorCount() != 0) {
      Log.debug("Found " + Log.getErrorCount() + " errors in node " + node + ".", "XX");
      return false;
    }
    return true;
  }
  
  /**
   * Loads a ComponentSymbol with the passed componentName. The componentName is the full qualified
   * name of the component model. Modelpaths are folders relative to the project path and containing
   * the packages the models are located in. When the ComponentSymbol is resolvable it is returned.
   * Otherwise the optional is empty.
   * 
   * @param componentName Name of the component
   * @param modelPaths Folders containing the packages with models
   * @return
   */
  public Optional<ComponentSymbol> loadComponentSymbolWithoutCocos(String componentName,
      File... modelPaths) {
    Scope s = initSymbolTable(modelPaths);
    return s.<ComponentSymbol> resolve(componentName, ComponentSymbol.KIND);
  }
  
  public Optional<ComponentSymbol> loadComponentSymbolWithCocos(String componentName,
      File... modelPaths) {
    Optional<ComponentSymbol> compSym = loadComponentSymbolWithoutCocos(componentName, modelPaths);
    
    if (compSym.isPresent()) {
      checkCoCos((ASTMontiArcNode) compSym.get().getAstNode().get());
    }
    
    return compSym;
  }
  
  /**
   * Loads the AST of the passed model with name componentName. The componentName is the fully
   * qualified. Modelpaths are folders relative to the project path and containing the packages the
   * models are located in. When the ComponentSymbol is resolvable it is returned. Otherwise the
   * optional is empty.
   * 
   * @param modelPath The model path containing the package with the model
   * @param model the fully qualified model name
   * @return the AST node of the model
   */
  public Optional<ASTMontiArcNode> getAstNode(String modelPath, String model) {
    // ensure an empty log
    Log.getFindings().clear();
    Optional<ComponentSymbol> comp = loadComponentSymbolWithoutCocos(model,
        Paths.get(modelPath).toFile());
    
    if (!comp.isPresent()) {
      Log.error("Model could not be resolved!");
      return Optional.empty();
    }

    if(!comp.get().getAstNode().isPresent()){
      return Optional.empty();
    }
    return Optional.of((ASTMontiArcNode) comp.get().getAstNode().get());
  }
  
  /**
   * Initializes the Symboltable by introducing scopes for the passed modelpaths. It does not create
   * the symbol table! Symbols for models within the modelpaths are not added to the symboltable
   * until resolve() is called. Modelpaths are relative to the project path and do contain all the
   * packages the models are located in. E.g. if model with fqn a.b.C lies in folder
   * src/main/resources/models/a/b/C.arc, the modelpath is src/main/resources.
   * 
   * @param modelPaths
   * @return The initialized symbol table
   */
  public Scope initSymbolTable( Boolean fromCPPGen, File... modelPaths) {
    Set<Path> p = Sets.newHashSet();
    for (File mP : modelPaths) {
      p.add(Paths.get(mP.getAbsolutePath()));
    }
    
    final ModelPath mp = new ModelPath(p);
    
    GlobalScope gs = new GlobalScope(mp, family);
    
    if (fromCPPGen) {
      JavaDefaultTypesManager.addCPPPrimitiveTypes(gs);
    }else {
      JavaDefaultTypesManager.addJavaPrimitiveTypes(gs);
    }
    isSymTabInitialized = true;
    return gs;
  }
  
  /**
   * Initializes the Symboltable by introducing scopes for the passed modelpaths. It does not create
   * the symbol table! Symbols for models within the modelpaths are not added to the symboltable
   * until resolve() is called. Modelpaths are relative to the project path and do contain all the
   * packages the models are located in. E.g. if model with fqn a.b.C lies in folder
   * src/main/resources/models/a/b/C.arc, the modelPath is src/main/resources.
   * 
   * @param modelPath The model path for the symbol table
   * @return the initialized symbol table
   */
  public Scope initSymbolTable(String modelPath) {
    return initSymbolTable(false, Paths.get(modelPath).toFile());
  }
  
  
  public Scope initSymbolTable(File... modelPaths) {
    return initSymbolTable(false, modelPaths);
  }
}
