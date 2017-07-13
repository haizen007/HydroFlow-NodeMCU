#include <ESP8266WiFi.h>
#include <WiFiClient.h>

const char* ssid      = "Yonathan";
const char* password  = "88220000";
const char* host      = "hydroflow.online";

const char* var1      = "var1=+Vazao+de:+";
const char* var2      = "&var2=+L/min+";
const char* var3      = "&var3=+Consumidos:+";
const char* var4      = "&var4=+Litros";

void wifiStartConn () {

  Serial.println();
  Serial.println();
  Serial.print("Conectando ao SSID: ");
  Serial.println(ssid);
  digitalWrite(D0, HIGH); // 1 yellow

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    digitalWrite(D2, HIGH);  // 1 red enquanto nao conectar
    delay(250);
    Serial.print(".");
  }
  digitalWrite(D2, LOW);  // 1 red
  digitalWrite(D1, HIGH); // 1 green

  Serial.println();
  Serial.println("WIFI Conectado");
  Serial.print("IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();
}

void wifiHostPrint () {

  Serial.print("Conectando ao Servidor: ");
  Serial.println(host);
  Serial.println();
  digitalWrite(D5, HIGH); // 2 yellow

}

void wifiServerConn () {

  // WiFiClient class para criar conexoes TCP
  WiFiClient client;
  const int httpPort = 80;
  if (!client.connect(host, httpPort)) {
    Serial.println("ERRO de Conexao");
    digitalWrite(D7, HIGH); // 2 red
    return;
  }
  digitalWrite(D6, HIGH); // 2 green

  String url = "/http/post.php?";
  url += var1;
  url += (mediaSeg / 5);
  url += var2;
  url += var3;
  url += total;
  url += var4;

  Serial.print("Requisitando URL: ");
  Serial.println(url);

  // Envia a requisicao pro servidor
  client.print(String("POST ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" +
               "Connection: close\r\n\r\n");

  // Le todas as linhas da resposta do servidor e imprime
  while (client.available()) {
    String line = client.readStringUntil('\r');
    Serial.println(line);
  }

  Serial.println("Conexao Encerrada");
  Serial.println();

}

