package components.body.ports;

/**
 * Invalid model. Muliple connectors send to rootOut.
 */
component InPortAmbiguousSender {
  port out rootOut;

  component A {
    port out String aOut;
  }
  
  component B {
    port in String bIn;
  }
  
  connect a.aOut -> b.bIn;
  
  connect a.aOut -> rootOut;
  
  component A myA
    [aOut -> b.bIn, rootOut];
}