# HTTP GET Request with Esp32
Esse é um projeto bem simples utilizando o Esp32 para fazer requisições HTTP, no caso do tipo GET.

## Desafios
- Conectar o Esp32 ao Wifi;
- Fazer requisições HTTP;
- Trabalhar com JSON usando C++.

## Conectando no Wifi

```c++
// Importanto biblioteca
#include <WiFi.h>
...

// Passando as credenciais da rede Wifi
const char* ssid = "network-name";
const char* password = "network-password";

void setup() {
  WiFi.begin(ssid, password);

  // Enquanto não conectar vai ficar exibindo "." no monitor serial
  while (WiFi.status() != WL_CONNECTED) { 
    Serial.print(".");
    delay(500);
  }

  // Após conectar...
  Serial.println("Conectado");
  Serial.println(WiFi.localIP());
  Serial.println("");
}

void loop() {
  if((WiFi.status() == WL_CONNECTED)){
  // Se estiver conectado:
    Serial.println("+");
  }else{
  // Se não estiver conectado:
    Serial.println("-");
  }
  delay(500);
}
```

## Autores

- [@Victor-Lis](https://www.github.com/Victor-Lis)

