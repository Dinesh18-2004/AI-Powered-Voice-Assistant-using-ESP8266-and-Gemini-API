#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include <ESP8266HTTPClient.h>
#include <ArduinoJson.h>

const char* ssid = "wifi name";
const char* password = "password";
const char* Gemini_Token = "API Key";
const char* Gemini_Max_Tokens = "100";
String res = "";

WiFiClientSecure client;

void setup() {
  delay(3000);
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();

  while (!Serial);

  WiFi.begin(ssid, password);
  Serial.print("Connecting to ");
  Serial.println(ssid);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("\nConnected!");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  client.setInsecure();  // Insecure SSL
}

void loop() {
  Serial.println("\nAsk your Question:");
  while (!Serial.available()) delay(1);

  res = "";  // Reset res
  while (Serial.available()) {
    char add = Serial.read();
    res += add;
    yield();
  }

  res.trim();
  res = "\"" + res + "\"";

  Serial.println("\nAsking Your Question: " + res);

  HTTPClient https;

  if (https.begin(client, "https://generativelanguage.googleapis.com/v1beta/models/gemini-1.5-flash:generateContent?key=" + String(Gemini_Token))) {
    https.addHeader("Content-Type", "application/json");

    String payload = "{\"contents\": [{\"parts\":[{\"text\":" + res + "}]}],\"generationConfig\": {\"maxOutputTokens\": " + String(Gemini_Max_Tokens) + "}}";

    int httpCode = https.POST(payload);

    if (httpCode == HTTP_CODE_OK) {
      String response = https.getString();

      DynamicJsonDocument doc(5120);
      Serial.print("Free heap: ");
      Serial.println(ESP.getFreeHeap());

      deserializeJson(doc, response);

      String Answer = doc["candidates"][0]["content"]["parts"][0]["text"];
      Answer.trim();

      // Filter special characters
      String filteredAnswer = "";
      for (size_t i = 0; i < Answer.length(); i++) {
        char c = Answer[i];
        if (isalnum(c) || isspace(c)) {
          filteredAnswer += c;
        } else {
          filteredAnswer += ' ';
        }
      }

      Answer = filteredAnswer;

      Serial.println("\nHere is your Answer:\n");
      Serial.println(Answer);

    } else {
      Serial.printf("[HTTPS] POST failed, error: %s\n", https.errorToString(httpCode).c_str());
    }

    https.end();
  } else {
    Serial.println("[HTTPS] Unable to connect");
  }

  res = "";
}
