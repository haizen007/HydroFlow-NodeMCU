/*
   Classe que faz a leitura de consumo e converte em Litros
   A base de cálculo é a cada x Segundos mediante o delay total criado na "Main"
   Durante este intervalo são registrados e enviados os dados para o Servidor
   O envio é feito pela Classe "Wifi.h"
*/

int tempo;          // Contagem de segundos
double vazao;       // Armazenar o valor em L/mins
double total;       // Total de Litros consumidos
double consumo;     // Média a cada x segundo
volatile int pulso; // Volátil para garantir que irá atualizar durante o processo de interrupção

void addPulso () {
  pulso++; // Incrementa a variável de contagem dos pulsos
}

void waterInterruptAdd () {
  attachInterrupt(D4, addPulso, FALLING); // Configura o pino D4 para interrupção
}

void waterInterruptON () {
  interrupts();   // Habilita interrupção
}

void waterInterruptOFF () {
  noInterrupts(); // Desabilita interrupção
}

void waterDataClean () {
  pulso = 0; // Zera a variável de pulsos para realização de nova contagem
}

void waterDataFake () {
  pulso = rand() % 50 + 5; // Preenche com dados fakes de forma randômica
}

void waterData () {
  vazao = pulso / 5.5;     // Converte para L/min
  consumo = vazao / 40;    // Converte Litros
  tempo = tempo + segundo; // Adiciona x segundo
  total = total + consumo; // Soma o consumo atual ao total
}

void waterDataPrint () {
  Serial.print("Vazao de: " + String(vazao) + " L/min | ");      // Imprime vazão de X segundos
  Serial.print("Consumidos: " + String(consumo) + " Litros | "); // Imprime  o consumo de 1 segundo
  Serial.print("Tempo: " + String(tempo) + "s | ");              // Imprime a contagem de tempo de 1 em 1 segundo
  Serial.print("Total: " + String(total) + " Litros \n");        // Imprime o total consumido até o momento em Litros
}

