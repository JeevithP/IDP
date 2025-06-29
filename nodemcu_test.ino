#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <ArduinoJson.h>

// Wi-Fi credentials
const char* ssid = "YourWiFiName";
const char* password = "YourWiFiPassword";

// Flask server IP + port (replace with your computer's IP)
const char* serverUrl = "http://192.168.X.X:5000/predict";

void setup() {
  Serial.begin(115200);
  delay(1000);

  // Connect to WiFi
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nConnected to WiFi");
  
  // Simulated sensor values (you can replace with real sensor readings)
  float temp = 30.5;
  float volt = 3.3;
  float curr = 1.9;
  float ambient = 32.0;
  float charge = 60.0;

  // Prepare JSON data
  StaticJsonDocument<200> jsonDoc;
  jsonDoc["temperature"] = temp;
  jsonDoc["voltage"] = volt;
  jsonDoc["current"] = curr;
  jsonDoc["ambient_temp"] = ambient;
  jsonDoc["battery_charge"] = charge;

  String jsonStr;
  serializeJson(jsonDoc, jsonStr);

  // Send POST request
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    http.begin(serverUrl);
    http.addHeader("Content-Type", "application/json");
    
    int httpResponseCode = http.POST(jsonStr);

    if (httpResponseCode > 0) {
      String response = http.getString();
      Serial.println("Server Response:");
      Serial.println(response);
    } else {
      Serial.print("Error in HTTP request: ");
      Serial.println(httpResponseCode);
    }
    http.end();
  } else {
    Serial.println("WiFi Disconnected");
  }
}

void loop() {
  // Optional: Send data every 15 seconds
  delay(15000);
}
