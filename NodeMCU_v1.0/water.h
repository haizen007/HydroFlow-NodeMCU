// A base de calculo é a cada 5s mediante o delay total criado na Main
// Durante este intervalo são registrados e enviados os dados para o Servidor

double vazao;      // Variável para armazenar o valor em L/mins
double mediaSeg;   // Variável para tirar a média a cada 1 minuto
double mediaMin;   // Variável para tirar a média a cada 1 minuto
double total;      // Variável para de Litros Consumidos
int contaPulso;   // Variável para a quantidade de pulsos
int iSeg;          // Variável para contagem
int iMin;          // Variável para contagem

void incPulso () {
  contaPulso++;    // Incrementa a variável de contagem dos pulsos
}

void waterInterruptAdd () {
  attachInterrupt(D4, incPulso, RISING); // Configura o pino D4 para trabalhar com interrupção
}

void waterDataClean () {

  mediaSeg = 0;   // Zera a variável media para uma nova contagem
  contaPulso = 0; // Zera a variável para contar os giros por segundos
}

void waterInterruptON () {
  sei();          // Habilita interrupção
}

void waterInterruptOFF () {
  cli();          // Desabilita interrupção
}

void waterData () {

  vazao = contaPulso / 5.5;       // Converte para L/min
  mediaSeg = mediaSeg + vazao;    // Soma a vazão para o calculo da media / seg
  mediaMin = mediaMin + vazao;    // Soma a vazão para o calculo da media / min
  iMin++;
}

void waterDataPrint () {
	
  Serial.print("Vazao de: ");           // Imprime
  Serial.print(mediaSeg / 5);           // Vazão de 5 segundos
  Serial.print(" L/min - Consumidos: ");// Imprime
  Serial.print(mediaSeg / 60);          // Consumo daqueles 5 segundos
  Serial.print(" Litros | ");           // Imprime
  Serial.print(iMin * 5 );              // Imprime a contagem de 5 em 5 segundos
  Serial.print("s");                    // Imprime
  total = total + (mediaSeg / 60);      // Total consumido até o momento em litros
  Serial.print(" | Total: ");           // Imprime
  Serial.print(total);                  // Imprime o total
  Serial.println(" Litros");            // Imprime

}

