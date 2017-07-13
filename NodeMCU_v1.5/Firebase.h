#include <FirebaseArduino.h>

/**
   Classe para conectar e enviar dados ao Firebase
   http://firebase-arduino.readthedocs.io/en/latest/
   https://github.com/firebase/firebase-arduino
*/

void firebaseConn() {
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Serial.println("Firebase iniciado: " + String(FIREBASE_HOST) + "\n");
}

void firebaseDataSend() {
  Firebase.setFloat("/usuario/consumo/tempoReal/", consumo * 1000); // Converte para mL
  if (Firebase.failed()) {
    Serial.println("ERRO: o Consumo não foi salvo no Firebase");
    Serial.println(Firebase.error());
    return;
  }
}

void firebaseDataTimeStamp() {
  StaticJsonBuffer<50> jsonBuffer;
  JsonObject& timeStampObject = jsonBuffer.createObject();
  timeStampObject[".sv"] = "timestamp";
  Firebase.push("/timestamp/", timeStampObject);
  
//
//  int timeStamp = Firebase.getInt("/timestamp/");
//
//  Firebase.setInt("/usuario/atualHora/", timeStamp);
//  if (Firebase.failed()) {
//    Serial.println("ERRO: o timeStamp não foi salvo no Firebase");
//    Serial.println(Firebase.error());
//    return;
//  }
//
//  Firebase.remove("/timestamp/");
}



