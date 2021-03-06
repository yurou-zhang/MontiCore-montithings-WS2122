// (c) https://github.com/MontiCore/monticore
package cdlangextension._ast;

import com.google.common.base.Joiner;
import de.se_rwth.commons.StringTransformations;

import java.util.List;

import static com.google.common.collect.Iterables.transform;

/**
 * AST for Strings separated by '::'
 */
public  class ASTCDEQualifiedDoubleColonName extends ASTCDEQualifiedDoubleColonNameTOP {
  public ASTCDEQualifiedDoubleColonName() {
  }

  public ASTCDEQualifiedDoubleColonName(List<String> parts) {
    this.parts=parts;
  }

  @Override
  public  String toString()   {
    return Joiner.on("::").skipNulls().join(
        transform(transform(this.getPartsList(),
            StringTransformations.TRIM_WHITESPACE),
            StringTransformations.TRIM_DOT));
  }
}