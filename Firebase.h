#include <FirebaseArduino.h>

/**
   Classe para conectar e enviar dados ao Firebase
   http://firebase-arduino.readthedocs.io/en/latest/
   https://github.com/firebase/firebase-arduino
*/

void firebaseConn() {
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Serial.print("Firebase iniciado: " + String(FIREBASE_HOST) + "\n");
}

void firebaseDataSend() {
  Firebase.setFloat("/usuario/consumo/tempoReal/", consumo * 1000); // Converte para mL
  if (Firebase.failed()) {
    Serial.println("ERRO: Consumo nao foi salvo no Firebase");
    return;
  }
}

void firebaseDataTotal() {
  Firebase.setFloat("/total/", total);
  if (Firebase.failed()) {
    Serial.print("ERRO: o Consumo Total não foi salvo no Firebase");
    return;
  }
}

