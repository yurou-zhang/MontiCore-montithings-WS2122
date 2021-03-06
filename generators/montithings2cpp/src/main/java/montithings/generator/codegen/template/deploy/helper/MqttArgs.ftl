<#-- (c) https://github.com/MontiCore/monticore -->
${tc.signature("comp", "config")}
<#include "/template/Preamble.ftl">

TCLAP::ValueArg${"<"}std::string${">"} brokerHostnameArg ("","brokerHostname","Hostname (or IP address) of the MQTT broker",false,"localhost","string");
TCLAP::ValueArg${"<"}int${">"} brokerPortArg ("","brokerPort","Network port of the MQTT broker",false,1883,"int");
cmd.add ( brokerHostnameArg );
cmd.add ( brokerPortArg );

TCLAP::SwitchArg muteMqttLogger ("", "muteMQTT", "Suppress all logs from MQTT broker", false);
cmd.add (muteMqttLogger);