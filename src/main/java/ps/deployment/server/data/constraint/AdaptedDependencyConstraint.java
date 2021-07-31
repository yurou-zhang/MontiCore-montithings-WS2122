package ps.deployment.server.data.constraint;

import com.google.gson.JsonObject;

public class AdaptedDependencyConstraint extends DependencyConstraint {
  
  private int originalCount;
  
  public AdaptedDependencyConstraint(String dependent, String dependency, int count, boolean exclusive, int originalCount) {
    super(dependent, dependency, count, exclusive);
    this.originalCount = originalCount;
  }
  
  @Override
  public JsonObject serializeJson() {
    JsonObject json = super.serializeJson();
    json.addProperty("originalCount", this.originalCount);
    return json;
  }
  
}
