#include <ESP8266WiFi.h>

/**
   Classe que envia por GET as requisições ao Servidor HTTP
   As requisições são impressas na Serial
*/

void wifiStartConn () {

  Serial.println("\n\nConectando ao SSID: " + String(WIFI_SSID));

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(250);
    Serial.print(".");
  }

  Serial.println("\nWIFI Conectado");
  Serial.print("IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();

}

void wifiServerConn () {

  Serial.println("\nConectando ao Servidor: " + String(HOST_SERVER));
  WiFiClient client; // Para criar conexoes TCP
  if (!client.connect(HOST_SERVER, HOST_PORT)) {
    Serial.println("ERRO de Conexao com o Servidor");
    return;
  }

  String url = HOST_URL;
  url += var1;
  url += (vazao);
  url += var2;
  url += var3;
  url += (total);
  url += var4;

  Serial.println("URL: " + url);
  client.println(String("GET ") + url + " HTTP/1.1\r\n" + "host: " + HOST_SERVER + "\r\n\r\n"); // Envia a requisicao
  Serial.println("Conexao Encerrada\n");

}

