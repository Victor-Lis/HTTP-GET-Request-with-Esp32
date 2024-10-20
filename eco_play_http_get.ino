#include <WiFi.h>
#include <HTTPClient.h>;
#include <ArduinoJson.h>;
#define RXp2 16
#define TXp2 17

const char* ssid = "Oalis";
const char* password = "oalis636807";

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  Serial.println("Configuring access point...");
  Serial2.begin(9600, SERIAL_8N1, RXp2, TXp2);

  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  Serial.println("Conectado");
  Serial.println(WiFi.localIP());
  Serial.println("");
}

void loop() {
  String serialText = Serial2.readString();
  String apiUrl = "https://ecoplay-landingpage.vercel.app/api/tampinha";
  //Serial.print("API URL");
  //Serial.println(apiUrl);

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println(serialText);
    if(serialText.length()){
      Serial.println("+");

      HTTPClient client;

      client.begin(apiUrl);

      Serial.println(client.getString());

      //Serial.println(apiUrl.length());
    
      int httpCode = client.GET();
      //Serial.println(String(httpCode));
      
      if (httpCode > 0) {
        String payload = client.getString();
        Serial.println("\nStatuscode: " + String(httpCode));
        Serial.println(payload);
      } else {
        Serial.println("Error on HTTP Request");
        Serial.println("\nStatuscode: " + String(httpCode));
      }

      delay(50);
    }
  }
}
