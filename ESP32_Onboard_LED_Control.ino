#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "YOUR_WIFI_NAME";
const char* password = "YOUR_WIFI_PASSWORD";

WebServer server(80);

const int ledPin = 2;
bool ledState = false;

void handleRoot() {
  String html = "<!DOCTYPE html><html><head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">";
  html += "<title>ESP32 LED Control</title>";
  html += "<style>body { font-family: Arial, sans-serif; text-align: center; margin-top: 50px; background-color: #111; color: white; }";
  html += ".button { display: inline-block; padding: 15px 30px; font-size: 24px; cursor: pointer; text-decoration: none; color: white; background-color: #00c853; border-radius: 8px; margin: 20px; }";
  html += ".button-off { background-color: #d50000; }</style></head><body>";
  html += "<h1>ESP32 Web Server</h1>";
  html += "<h2>LED is <strong>" + String(ledState ? "ON" : "OFF") + "</strong></h2>";
  if (ledState) {
    html += "<p><a href=\"/off\" class=\"button button-off\">Turn OFF</a></p>";
  } else {
    html += "<p><a href=\"/on\" class=\"button\">Turn ON</a></p>";
  }
  html += "</body></html>";
  
  server.send(200, "text/html", html);
}

void handleLedOn() {
  ledState = true;
  digitalWrite(ledPin, HIGH);
  server.sendHeader("Location", "/");
  server.send(303);
}

void handleLedOff() {
  ledState = false;
  digitalWrite(ledPin, LOW);
  server.sendHeader("Location", "/");
  server.send(303);
}

void handleNotFound() {
  server.send(404, "text/plain", "404: Not Found");
}

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  
  Serial.println("Connecting to Wi-Fi...");
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  Serial.println("\nWi-Fi Connected!");
  Serial.print("ESP32 IP Address: ");
  Serial.println(WiFi.localIP());
  
  server.on("/", HTTP_GET, handleRoot);
  server.on("/on", HTTP_GET, handleLedOn);
  server.on("/off", HTTP_GET, handleLedOff);
  server.onNotFound(handleNotFound);
  
  server.begin();
  Serial.println("HTTP Server Started");
}

void loop() {
  server.handleClient();
}
