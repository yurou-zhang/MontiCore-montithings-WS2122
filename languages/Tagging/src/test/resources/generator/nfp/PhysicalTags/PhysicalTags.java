/* generated by template templates.de.monticore.lang.tagschema.TagSchema*/


package nfp.PhysicalTags;

import de.monticore.lang.tagging._symboltable.TaggingResolver;
import de.monticore.symboltable.resolving.CommonResolvingFilter;

/**
 * generated by TagSchema.ftl
 */
public class PhysicalTags {

  protected static PhysicalTags instance = null;

  protected PhysicalTags() {}

  protected static PhysicalTags getInstance() {
    if (instance == null) {
      instance = new PhysicalTags();
    }
    return instance;
  }

  protected void doRegisterTagTypes(TaggingResolver tagging) {
    tagging.addTagSymbolCreator(new IsPhysicalSymbolCreator());
    tagging.addTagSymbolResolvingFilter(CommonResolvingFilter.create(IsPhysicalSymbol.KIND));
    tagging.addTagSymbolCreator(new WeightSymbolCreator());
    tagging.addTagSymbolResolvingFilter(CommonResolvingFilter.create(WeightSymbol.KIND));
    tagging.addTagSymbolCreator(new SizeSymbolCreator());
    tagging.addTagSymbolResolvingFilter(CommonResolvingFilter.create(SizeSymbol.KIND));
  }

  public static void registerTagTypes(TaggingResolver tagging) {
    getInstance().doRegisterTagTypes(tagging);
  }

}