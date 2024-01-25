# HTTP GET Request with Esp32
Esse é um projeto bem simples utilizando o Esp32 para fazer requisições HTTP, no caso do tipo GET.
Embora simples, é um projeto que para mim abre um mundo para meus projetos usando Sistemas Embarcados.

## Desafios
- Conectar o Esp32 ao Wifi;
- Fazer requisições HTTP;
- Trabalhar com JSON usando C++.

## Aprendizados

### Conectando no Wifi

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

### Requisição HTTP em si
Basta adicionar alguns detalhes no código acima:
1- Importar mais 1 biblioteca;
```c++
#include <HTTPClient.h>;
```
2- setup() continua igual;
3- loop() ficará assim no final:
```c++
void loop() {
  if((WiFi.status() == WL_CONNECTED)){
    Serial.println("+");
    
    long rnd = random(1, 10); // Apenas para gerar um id randômico, poderia ser um ID estático.
    HTTPClient client; // Declarando HTTPclient a partir da utilização da lib "HTTPClient".

    client.begin("https://jsonplaceholder.typicode.com/comments?id=" + String(rnd)); // Iniciando cliente com a url da API
    int httpCode = client.GET(); // Utilizando método GET na API declarada anteriormente
    
    if(httpCode > 0){
      // Se tiver sido bem sucedido 
      String payload = client.getString();
      Serial.println("\nStatuscode: " + String(httpCode));
      Serial.println(payload);
    }else{
      // Se não tiver sido bem sucedido
      Serial.println("Error on HTTP Request");
    }

    delay(60000);
  }else{
    Serial.println("-");
    delay(500);
  }
}
```

## Autores

- [@Victor-Lis](https://www.github.com/Victor-Lis)

