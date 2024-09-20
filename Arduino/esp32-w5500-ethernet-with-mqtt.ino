// Mqtt Library used here is
// https://github.com/256dpi/arduino-mqtt
 
#include <SPI.h>
#include <Ethernet.h>
#include <MQTT.h>
 
byte mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED};
byte ip[] = {192, 168, 1, 177};  // <- change to match your network
 
EthernetClient net;
MQTTClient client;
 
unsigned long lastMillis = 0;
 
void connect() {
  Serial.print("connecting...");
  while (!client.connect("espw5500", "", "")) {
    Serial.print(".");
    delay(1000);
  }
 
  Serial.println("\nconnected!");
 
  client.subscribe("/EthernetW500");
}
 
void messageReceived(String &topic, String &payload) {
  Serial.println("incoming: " + topic + " - " + payload);
 
  // Note: Do not use the client in the callback to publish, subscribe or
  // unsubscribe as it may cause deadlocks when other things arrive while
  // sending and receiving acknowledgments. Instead, change a global variable,
  // or push to a queue and handle it in the loop after calling `client.loop()`.
}
 
void setup() {
  Serial.begin(115200);
  Ethernet.init(33); //CS pin IO33
  Ethernet.begin(mac, ip);
 
  // Note: Local domain names (e.g. "Computer.local" on OSX) are not supported
  // by Arduino. You need to set the IP address directly.
  client.begin("test.mosquitto.org", net);
  client.onMessage(messageReceived);
 
  connect();
}
 
void loop() {
  client.loop();
  delay(10);  // <- fixes some issues with WiFi stability
 
  if (!client.connected()) {
    connect();
  }
 
  // publish a message roughly every second.
  if (millis() - lastMillis > 1000) {
    lastMillis = millis();
    client.publish("/EthernetW500", "world");
  }
}
