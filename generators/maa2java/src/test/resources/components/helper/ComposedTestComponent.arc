package components.helper;

component ComposedTestComponent {

  component ComponentWithDefaultParameters("1st") first;
  component ComponentWithDefaultParameters("2nd", 42) second;
  component ComponentWithDefaultParameters("3rd", 3, new Integer(7)) third;
}