#include "vendor.h"
#include "water.h"
#include "wifi.h"

void setup() {

  Serial.begin(115200);    // Inicia a 1 fase
  pinMode(led, OUTPUT);    // Adiciona o LED default
  waterInterruptAdd ();    // Adiciona o pino D4 como interrupcao
  wifiStartConn ();        // Inicia a conexao com a rede wifi definida

}

void loop () {

  waterDataClean ();       // Zera os dados para nova leitura
  waterInterruptON ();     // Habilita a interrupção
  digitalWrite(led, HIGH); // LED indicando que interrupção foi ativada
  delay(1000);             // Precisa de delay entre habilitar e desabilitar interrupção
  digitalWrite(led, LOW);  // LED indicando que interrupção foi desativada
  waterInterruptOFF ();    // Desabilita interrupção após 2 segundos (os dados foram coletados neste intervalo)
  waterData ();            // Chama as variáveis para armazenar os dados coletados
  waterDataPrint ();       // Imprime na serial os dados coletados
  wifiHostPrint ();        // Imprime a conexao com o servidor
  wifiServerConn ();       // Conectacta na porta 80 do servidor para enviar os dados para a pagina PHP

}

