//#include <ESP8266WiFi.h>
//#include <PubSubClient.h>
#include </home/aubbiali/Arduino/embeddedExercise/WifiConfig.h>

// MQTT Broker
//const char *mqtt_broker = "broker.emqx.io";
//const char *topic = "esp8266/test";
//const char *mqtt_username = "emqx";
//const char *mqtt_password = "public";
//const int mqtt_port = 1883;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(1000);
  Serial.println(SSID);
}
