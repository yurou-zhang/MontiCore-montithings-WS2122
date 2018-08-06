package components.body.subcomponents;

import components.body.subcomponents._subcomponents.Car;

/**
 * Valid model. 
 */
component Garage {

  port 
    in List<java.util.HashMap<Boolean,Double>> wheels,
    out java.util.HashMap<Double[],List<String>>[] motor;

  component Car<String>("My awesome car");
  
  connect wheels -> car.wheels;
  connect car.motor -> motor;
}