#include <ESP8266WiFi.h>

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

void wifiHostPrint () {
  Serial.println("\nConectando ao Servidor: " + String(HOST_SERVER));
}

void wifiServerConn () {

  // WiFiClient class para criar conexoes TCP
  WiFiClient client;
  if (!client.connect(HOST_SERVER, HOST_PORT)) {
    Serial.println("ERRO de Conexao");
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

  // Envia a requisicao pro Servidor
  client.println(String("GET ") + url + " HTTP/1.1\r\n" + "host: " + HOST_SERVER + "\r\n\r\n");

  Serial.println("Conexao Encerrada\n");

}

