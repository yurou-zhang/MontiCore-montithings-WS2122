/*
 * Copyright (c) 2016 RWTH Aachen. All rights reserved.
 *
 * http://www.se-rwth.de/
 */
package de.monticore.lang.montiarc.montiarc._symboltable;

import static com.google.common.base.Preconditions.checkArgument;
import static com.google.common.base.Strings.isNullOrEmpty;

import java.util.Collection;
import java.util.Optional;
import java.util.function.Predicate;

import de.monticore.symboltable.Scope;
import de.monticore.symboltable.SymbolKind;
import de.monticore.symboltable.modifiers.AccessModifier;
import de.monticore.symboltable.references.SymbolReference;
import de.monticore.symboltable.types.JTypeSymbol;
import de.monticore.symboltable.types.references.CommonJTypeReference;
import de.se_rwth.commons.logging.Log;

/**
 * When resolving to JTypeSymbol method loadReferencedSymbol() of
 * CommonJTypeReference resolves single. As we use an adapter for
 * CDTypeSymbols2JavaTypeSymbols, resolving to CDTypeSymbols throws an error, as
 * there are two possible matching symbol kinds (CDTypeSymbol and Adapter
 * CDTypeSymbol2JavaType). In order to resolve many symbols in
 * loadReferencedSymbol() is overridden in this class.
 *
 * @author Jerome Pfeiffer
 * @version $Revision$, $Date$
 */
public class MAJTypeReference extends CommonJTypeReference<JTypeSymbol> {
  
  private Scope enclosingScope;
  
  private String referencedName;
  
  private SymbolKind referencedKind;
  
  private Predicate predicate = x -> true;
  
  private AccessModifier accessModifier = AccessModifier.ALL_INCLUSION;
  
  /**
   * Constructor for
   * de.monticore.lang.montiarc.montiarc._symboltable.MAJTypeReference
   * 
   * @param referencedSymbolName
   * @param referencedSymbolKind
   * @param definingScopeOfReference
   */
  public MAJTypeReference(
      String referencedSymbolName,
      SymbolKind referencedSymbolKind,
      Scope definingScopeOfReference) {
    super(referencedSymbolName, referencedSymbolKind, definingScopeOfReference);
    this.referencedName = referencedSymbolName;
    this.referencedKind = referencedSymbolKind;
    this.enclosingScope = definingScopeOfReference;
  }
  
  /**
   * @see de.monticore.symboltable.references.CommonSymbolReference#getReferencedSymbol()
   */
  @Override
  public JTypeSymbol getReferencedSymbol() {
    return super.getReferencedSymbol();
  }
  
  /**
   * @see de.monticore.symboltable.references.CommonSymbolReference#loadReferencedSymbol()
   */
  @Override
  protected Optional<JTypeSymbol> loadReferencedSymbol() {
    checkArgument(!isNullOrEmpty(referencedName), " 0xA4070 Symbol name may not be null or empty.");
    Log.errorIfNull(referencedKind);
    
    Log.debug("Load full information of '" + referencedName + "' (Kind " + referencedKind.getName()
        + ").",
        SymbolReference.class.getSimpleName());
    Collection<JTypeSymbol> foundSymbols = enclosingScope.resolveMany(referencedName,
        referencedKind,
        accessModifier);
    
    Optional<JTypeSymbol> resolvedSymbol = Optional.empty();
    
    if (!foundSymbols.isEmpty()) {
      Log.debug("Loaded full information of '" + referencedName + "' successfully.",
          SymbolReference.class.getSimpleName());
      resolvedSymbol = Optional.of(foundSymbols.iterator().next());
    }
    else {
      Log.warn("0xA1038 " + SymbolReference.class.getSimpleName()
          + " Could not load full information of '" +
          referencedName + "' (Kind " + referencedKind.getName() + ").");
    }
    
    return resolvedSymbol;
  }
  
}
