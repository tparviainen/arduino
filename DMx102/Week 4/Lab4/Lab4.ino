/*
 * Lab 4 - liikennevalojen sekä puomin ohjaus tasoristeyksessä
 */

#include <Servo.h>

// I/O pinnit servolle, painikkeelle sekä LED:lle
const int servoIo = 9;
const int painikeIo = 2;
const int punainenLiikennevaloIo = 3;
const int vihreaLiikennevaloIo = 4;

// Servon ohjausviive (millisekunteina)
const int servoOhjausviive = 15;

// Puomin aukioloaika (millisekunteina)
const int puominAukioloaika = 5000;

Servo servo;

// Mikrokontrollerin ja ohjelman alustaminen, suoritetaan kerran
// kontrollerin käynnistämisen yhteydessä.
void setup() {
  Serial.begin(9600);
  servo.attach(servoIo);
  pinMode(painikeIo, INPUT);
  pinMode(punainenLiikennevaloIo, OUTPUT);
  pinMode(vihreaLiikennevaloIo, OUTPUT);

  // Normaali toiminta, punaiset valot ja puomi on kiinni
  digitalWrite(punainenLiikennevaloIo, HIGH);
  servo.write(0);
}

// Pääsilmukka jota kutsutaan loputtomasti
void loop() {
  if (digitalRead(painikeIo) == HIGH) {
    Serial.println("Painike painettu");

    // Puomin nostaminen ylös (avaus)
    for (int i = 0; i <= 90; i += 1) {
      servo.write(i);
      delay(servoOhjausviive);
    }

    // Liikennevalojen vaihtaminen vihreäksi
    digitalWrite(punainenLiikennevaloIo, LOW);
    digitalWrite(vihreaLiikennevaloIo, HIGH);

    // Liikenteen salliminen hetken aikaa
    delay(puominAukioloaika);

    // Liikennevalojen vaihtaminen punaiseksi
    digitalWrite(vihreaLiikennevaloIo, LOW);
    digitalWrite(punainenLiikennevaloIo, HIGH);

    // Puomin laskeminen alas (sulkeminen)
    for (int i = 90; i >= 0; i -= 1) {
      servo.write(i);
      delay(servoOhjausviive);
    }
  }
}

