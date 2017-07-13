// http://firebase-arduino.readthedocs.io/en/latest/
// https://github.com/firebase/firebase-arduino

#include <FirebaseArduino.h>

double d =  0.1;

void firebaseStartConn() {
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Serial.println("Firebase Conectado: " + String(FIREBASE_HOST) + "\n");
}

void firebaseSendData() {

  Firebase.setFloat("usuario/atualConsumo", consumo * 1000);
  if (Firebase.failed()) {
    Serial.println("ERRO: o Consumo não pode salvo no Firebase");
    Serial.println(Firebase.error());
    return;
  }
//  d = d + 0.1;
}
