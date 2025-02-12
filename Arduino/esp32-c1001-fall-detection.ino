#include <WiFi.h>
#include <ESPAsyncWebServer.h>  // https://github.com/ESP32Async/ESPAsyncWebServer
#include "DFRobot_HumanDetection.h" // https://github.com/DFRobot/DFRobot_HumanDetection

// Enter your WiFi Credentials here
const char* ssid = "Enter_your_SSID"; 
const char* password = "Enter_Your_Password";
AsyncWebServer server(80);

DFRobot_HumanDetection hu(&Serial1);

String fallenStatus = "Not fallen";
String humanPresence = "No one is present";

void updateSensorData() {
  if (hu.smHumanData(hu.eHumanPresence) == 1) {
    humanPresence = "Someone is present";
  } else {
    humanPresence = "No one is present";
  }

  if (hu.getFallData(hu.eFallState) == 1) {
    fallenStatus = "Fallen";
  } else {
    fallenStatus = "Not fallen";
  }
}

void setup() {
  Serial.begin(115200);
 

  Serial1.begin(115200, SERIAL_8N1, 5, 18);
  init_fall_sensor();


   WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
  Serial.print("ESP32 IP Address: ");
  Serial.println(WiFi.localIP());

  server.on("/status", HTTP_GET, [](AsyncWebServerRequest *request){
    updateSensorData();
    String json = "{\"fallen\":\"" + fallenStatus + "\", \"human\":\"" + humanPresence + "\"}";
    request->send(200, "application/json", json);
  });

  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    String html = String("<!DOCTYPE html><html><head><meta http-equiv='refresh' content='2'><title>ESP32 Human Detection</title><style>body { font-family: Arial, sans-serif; text-align: center; } .status { padding: 20px; font-size: 24px; font-weight: bold; } .green { color: green; } .red { color: red; }</style></head><body><h2>Human Detection Status</h2><p class='status ") 
        + (fallenStatus == "Fallen" ? "red" : "green") + String("'><b>Fallen Status:</b> ") 
        + fallenStatus + String("</p><p class='status ") 
        + (humanPresence == "Someone is present" ? "green" : "red") + String("'><b>Human Presence:</b> ") 
        + humanPresence + String("</p></body></html>");
    
    request->send(200, "text/html", html);
  });

  server.begin();
}


void init_fall_sensor(){
    Serial.println("Start initialization");
  while (hu.begin() != 0) {
    Serial.println("init error!!!");
    delay(1000);
  }
  Serial.println("Initialization successful");

  Serial.println("Start switching work mode");
  while (hu.configWorkMode(hu.eFallingMode) != 0) {
    Serial.println("error!!!");
    delay(1000);
  }
  Serial.println("Work mode switch successful");

  hu.configLEDLight(hu.eFALLLed, 1);         // Set HP LED switch, it will not light up even if the sensor detects a person present when set to 0.
  hu.configLEDLight(hu.eHPLed, 1);           // Set FALL LED switch, it will not light up even if the sensor detects a person falling when set to 0.
  hu.dmInstallHeight(270);                   // Set installation height, it needs to be set according to the actual height of the surface from the sensor, unit: CM.
  hu.dmFallTime(2);                          // Set fall time, the sensor needs to delay the current set time after detecting a person falling before outputting the detected fall, this can avoid false triggering, unit: seconds.
  //hu.dmUnmannedTime(0);                      // Set unattended time, when a person leaves the sensor detection range, the sensor delays a period of time before outputting a no person status, unit: seconds.
  hu.unattendedTimeConfig(1);               //set time for presence
  hu.dmFallConfig(hu.eResidenceTime, 200);   // Set dwell time, when a person remains still within the sensor detection range for more than the set time, the sensor outputs a stationary dwell status. Unit: seconds.
  hu.dmFallConfig(hu.eFallSensitivityC, 3);  // Set fall sensitivity, range 0~3, the larger the value, the more sensitive.
  hu.sensorRet();   

  Serial.print("Current work mode:");
  switch (hu.getWorkMode()) {
    case 1:
      Serial.println("Fall detection mode");
      break;
    case 2:
      Serial.println("Sleep detection mode");
      break;
    default:
      Serial.println("Read error");
  }

  Serial.print("HP LED status:");
  switch (hu.getLEDLightState(hu.eHPLed)) {
    case 0:
      Serial.println("Off");
      break;
    case 1:
      Serial.println("On");
      break;
    default:
      Serial.println("Read error");
  }
  Serial.print("FALL status:");
  switch (hu.getLEDLightState(hu.eFALLLed)) {
    case 0:
      Serial.println("Off");
      break;
    case 1:
      Serial.println("On");
      break;
    default:
      Serial.println("Read error");
  }

  Serial.print("Radar installation height: ");
  Serial.print(hu.dmGetInstallHeight());
  Serial.println(" cm");
  Serial.print("Fall duration: ");
  Serial.print(hu.getFallTime());
  Serial.println(" seconds");
  Serial.print("Unattended duration: ");
  Serial.print(hu.getUnmannedTime());
  Serial.println(" seconds");
  Serial.print("Dwell duration: ");
  Serial.print(hu.getStaticResidencyTime());
  Serial.println(" seconds");
  Serial.print("Fall sensitivity: ");
  Serial.print(hu.getFallData(hu.eFallSensitivity));
  Serial.println(" seconds");
  Serial.println("===============================");
}

void loop() {
  updateSensorData();
  delay(1000);
}
