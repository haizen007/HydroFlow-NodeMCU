//-------------------------------- Fornece para a Main --------------------------------//

#define D0 16
#define D1 5
#define D2 4
#define D3 0
#define D4 2
#define D5 14
#define D6 12
#define D7 13
#define D8 15
#define D9 3
#define D10 1

// Define por array todos os pinos usados para os LEDs
void ledsAdd () {

  int ledPins[] = {D0, D1, D2, D5, D6, D7};
  int ledQtd = 6;
  for (int p = 0; p < ledQtd; p++) {
    pinMode(ledPins[p], OUTPUT);
  }

}

// Desabilita LEDs (LOW)
void ledsOFF () {

  int ledPins[] = {D5, D6, D7};
  int ledQtd = 3;
  for (int p = 0; p < ledQtd; p++) {
    digitalWrite(ledPins[p], LOW);
  }

}

