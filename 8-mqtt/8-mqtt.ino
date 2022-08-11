#include <ESP8266WiFi.h>
#include <MQTT.h>
#include </home/aubbiali/Arduino/embeddedExercise/WifiConfig.h>

WiFiClient net;
MQTTClient client;
unsigned long lastMillis = 0;

void setup() {
  Serial.begin(9600);
  setupWifi();
  setupMQTTBroker();
}

void loop() {
  client.loop();

  if (!client.connected()) {
    setupMQTTBroker();
  }
  
  // publish a message roughly every second.
  if (millis() - lastMillis > 1000) {
    lastMillis = millis();
    client.publish("/helloANDREAAA", "world");
  }
}

void setupWifi(){
  WiFi.begin(WIFINAME, WIFIPASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.println("Connecting to WiFi..");
  }
}

void setupMQTTBroker() {
  client.begin("test.mosquitto.org", net);
  client.onMessage(callback);

  Serial.print("\nconnecting MQTT");
  while (!client.connect("arduino", "public", "public")) {
    Serial.print(".");
    delay(1000);
  }

  Serial.println("\nconnected to MQTT!");

  client.subscribe("/helloANDREAAA");
}

void callback(String &topic, String &payload){
  Serial.println("incoming: " + topic + " - " + payload);
}
