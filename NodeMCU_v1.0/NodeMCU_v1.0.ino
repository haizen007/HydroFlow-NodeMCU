#include "vendor.h"
#include "water.h"
#include "wifi.h"

void setup() {

  Serial.begin(115200); // Inicia a 1 fase
  ledsAdd();            // Adiciona os Leds (D0, D1, D2, D5, D6, D7)
  waterInterruptAdd (); // Adiciona o pino D4 como interrupcao
  wifiStartConn ();     // Inicia a conexao com a rede wifi definida

}

void loop () {

  waterDataClean ();    // Zera os dados para nova leitura
  waterInterruptON ();  // Desabilita interrupção após 5 segundos (os dados foram coletados neste intervalo)
  delay(1500);          // Precisa de delay entre habilitar e desabilitar interrupção
  ledsOFF ();           // Desliga todos os leds da fase 2 (D5, D6, D7) para iniciar novamente
  delay(1500);          // Mais 1.5 segundo de delay
  wifiHostPrint ();     // Imprime a conexao com o servidor
  delay(2000);          // Mais 2 segundos de delay
  waterData ();         // Chama as variáveis para armazenar os dados coletados
  waterInterruptOFF (); // Habilita a interrupção
  waterDataPrint ();    // Imprime na serial os dados coletados
  wifiServerConn ();    // Conectacta na porta 80 do servidor para enviar os dados para a pagina PHP

}

