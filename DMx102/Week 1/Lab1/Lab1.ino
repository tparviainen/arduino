/*
 * Lab 1 - liikennevalojen ohjaus
 */

// I/O pinnit johon LEDit on kytketty
const int vLed = 4; // Vihreä LED
const int oLed = 3; // Oranssi LED
const int pLed = 2; // Punainen LED

// LED:n ohjaaminen päälle halutuksi ajaksi (sekunteina)
void ledinVilkutus(int led, int aikaSekunteina) {
    digitalWrite(led, HIGH);
    delay(aikaSekunteina * 1000);
    digitalWrite(led, LOW);
}

// Mikrokontrollerin ja ohjelman alustaminen, suoritetaan kerran
// kontrollerin käynnistämisen yhteydessä.
void setup() {
    pinMode(vLed, OUTPUT);
    pinMode(oLed, OUTPUT);
    pinMode(pLed, OUTPUT);
}

// Pääsilmukka jota kutsutaan loputtomasti
void loop() {
    ledinVilkutus(vLed, 3);
    ledinVilkutus(oLed, 1);
    ledinVilkutus(pLed, 3);
}

