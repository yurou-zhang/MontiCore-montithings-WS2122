package de.monticore.automaton.ioautomatonjava._symboltable;

import de.monticore.ast.ASTNode;
import de.monticore.automaton.ioautomaton._symboltable.VariableSymbol;
import de.monticore.java.symboltable.JavaFieldSymbol;
import de.monticore.java.symboltable.JavaTypeSymbolReference;
import de.monticore.symboltable.MutableScope;
import de.monticore.symboltable.resolving.SymbolAdapter;
import de.monticore.symboltable.types.JTypeSymbol;
import de.monticore.symboltable.types.references.JTypeReference;

public class Variable2FieldAdapter extends JavaFieldSymbol implements SymbolAdapter<VariableSymbol> {
  private VariableSymbol adaptee;
  
  private static JavaTypeSymbolReference createReference(JTypeReference<? extends JTypeSymbol> reference) {
    return new JavaTypeSymbolReference(reference.getName(), reference.getEnclosingScope(), reference.getDimension());
  }

  public Variable2FieldAdapter(VariableSymbol adaptee) {
    super(adaptee.getName(), JavaFieldSymbol.KIND, createReference(adaptee.getTypeReference()));
    this.adaptee = adaptee;
  }

  @Override
  public VariableSymbol getAdaptee() {
    return adaptee;
  }
  
  @Override
  public void setType(JavaTypeSymbolReference type) {
    adaptee.setTypeReference(type);
    super.setType(type);
  }
  
  @Override
  public void setEnclosingScope(MutableScope scope) {
    adaptee.setEnclosingScope(scope);
    super.setEnclosingScope(scope);
  }
  
  @Override
  public void setFullName(String fullName) {
    adaptee.setFullName(fullName);
    super.setFullName(fullName);
  }
  
  @Override
  public void setPackageName(String packageName) {
    adaptee.setPackageName(packageName);
    super.setPackageName(packageName);
  }
  
  @Override
  public void setAstNode(ASTNode node) {
    adaptee.setAstNode(node);
    super.setAstNode(node);
  }
}