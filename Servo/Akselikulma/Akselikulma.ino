
#include <Servo.h>
#include "Sarjaportti.h"

Servo myServo;
Sarjaportti sarjaportti;

// Sarjaportista luettavan merkkijonon maksimipituus
const int merkkijononMaksimipituus = 3;

// Servon PWM pinni
const int servoPin = 9;

// Servon PWM pulssin leveys mikrosekunteina minimi (0) ja maksimikulmilla (180)
// nämä arvot kalibroidaan oman servon mukaisesti.
const int servoMin = 540;
const int servoMax = 2500;

// Mikrokontrollerin ja ohjelman alustaminen, suoritetaan kerran
// kontrollerin käynnistämisen yhteydessä.
void setup() {
  sarjaportti.alusta(merkkijononMaksimipituus);
  myServo.attach(servoPin, servoMin, servoMax);
}

// Pääsilmukka jota kutsutaan loputtomasti
void loop() {
  if (sarjaportti.onkoMerkkijonoLuettu()) {
    int akselikulma = atoi(sarjaportti.merkkijono());
    sarjaportti.tyhjenna();

    Serial.print("Asetetaan akselikulmaksi ");
    Serial.print(akselikulma);
    Serial.println(" astetta.");

    myServo.write(akselikulma);
  }
}

