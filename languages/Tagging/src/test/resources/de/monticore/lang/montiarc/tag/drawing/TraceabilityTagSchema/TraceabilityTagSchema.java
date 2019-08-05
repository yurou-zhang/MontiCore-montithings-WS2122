/* generated by template templates.de.monticore.lang.tagschema.TagSchema*/


package de.monticore.lang.montiarc.tag.drawing.TraceabilityTagSchema;

import de.monticore.lang.tagging._symboltable.TaggingResolver;
import de.monticore.symboltable.resolving.CommonResolvingFilter;

/**
 * generated by TagSchema.ftl
 */
public class TraceabilityTagSchema {

  protected static TraceabilityTagSchema instance = null;

  protected TraceabilityTagSchema() {}

  protected static TraceabilityTagSchema getInstance() {
    if (instance == null) {
      instance = new TraceabilityTagSchema();
    }
    return instance;
  }

  protected void doRegisterTagTypes(TaggingResolver tagging) {
    tagging.addTagSymbolCreator(new IsTraceableSymbolCreator());
    tagging.addTagSymbolResolvingFilter(CommonResolvingFilter.create(IsTraceableSymbol.KIND));
    tagging.addTagSymbolCreator(new TraceableSymbolCreator());
    tagging.addTagSymbolResolvingFilter(CommonResolvingFilter.create(TraceableSymbol.KIND));
  }

  public static void registerTagTypes(TaggingResolver tagging) {
    getInstance().doRegisterTagTypes(tagging);
  }

}