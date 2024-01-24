#include <WiFi.h>
#include <HTTPClient.h>;
#include <ArduinoJson.h>;

const char* ssid = "Oalis";
const char* password = "oalis636807";

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  Serial.println("Configuring access point...");
  
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  
  Serial.println("Conectado");
  Serial.println(WiFi.localIP());
  Serial.println("");
}

void loop() {
  if((WiFi.status() == WL_CONNECTED)){
    Serial.println("+");
    
    long rnd = random(1, 10);
    HTTPClient client;

    client.begin("https://jsonplaceholder.typicode.com/comments?id=" + String(rnd));
    int httpCode = client.GET();
    
    if(httpCode > 0){
      String payload = client.getString();
      Serial.println("\nStatuscode: " + String(httpCode));
      Serial.println(payload);
    }else{
      Serial.println("Error on HTTP Request");
    }

    delay(60000);
  }else{
    Serial.println("-");
    delay(500);
  }
}
