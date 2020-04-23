#include <ESP8266WiFi.h>

/*
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
  // Serial.println("\nConectando ao Servidor: " + String(HOST_SERVER));
  WiFiClient client; // Para criar conexoes TCP
  if (!client.connect(HOST_SERVER, HOST_PORT)) {
    Serial.println("ERRO de Conexao com o Servidor: " + String(HOST_SERVER));
    return;
  }
  // Exemplo da String completa: hydroflow.yonathan.com.br/v12/leitura.php?board=60eb692e004a&valor=5
  String url = HOST_URL;
  url += var1;
  url += var2;
  url += (total);
  client.println(String("GET ") + url + " HTTP/1.1\r\n" + "host: " + HOST_SERVER + "\r\n\r\n"); // Envia a requisicao
}

