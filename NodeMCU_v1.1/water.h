// A base de calculo é a cada 5s mediante o delay total criado na Main
// Durante este intervalo são registrados e enviados os dados para o Servidor

int tempo;               // Variável para contagem de Segundos
double vazao;            // Variável para armazenar o valor em L/mins
double total;            // Variável para de Litros Consumidos
double consumo;          // Variável para tirar a média a cada Segundo
volatile int pulso;      // Volátil para garantir que irá atualizar durante o processo de interrupção
const byte segundos = 3; // Quantidade de segundos de delay entre o início e o fim de uma interrupção

void addPulso () {
  pulso++; // Incrementa a variável de contagem dos pulsos
}

void waterInterruptAdd () {
  attachInterrupt(D4, addPulso, RISING); // Configura o pino D4 para trabalhar com interrupção
}

void waterInterruptON () {
  interrupts();   // Habilita interrupção
}

void waterInterruptOFF () {
  noInterrupts(); // Desabilita interrupção
}

void waterDataClean () {
  pulso = 0; // Zera a variável para contar os giros por segundos
}

void waterData () {

  vazao = pulso / 5.5;               // Converte para L/min
  consumo = vazao / (60 / segundos); // Converte Litros (60s / delay entre a leitura de interrupção)
  tempo = tempo + 5;                 // Adiciona 5 segundos ao tempo
  total = total + consumo;           // Soma o consumo atual ao total

}

void waterDataPrint () {

  Serial.print("Vazao de: " + String(vazao / segundos) + " L/min | "); // Imprime vazão de X segundos
  Serial.print("Consumidos: " + String(consumo) + " Litros | ");       // Imprime  o consumo de X segundos
  Serial.print("Tempo: " + String(tempo) + "s | ");                    // Imprime a contagem de tempo de 5 em 5 segundos
  Serial.print("Total: " + String(total) + " Litros \n");              // Imprime o total consumido até o momento em Litros

}

