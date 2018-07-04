/*
 * Lab 3 - Summerin taajuuden muuttaminen LDR vastuksen arvon perusteella
 */

// I/O pinnit johon summeri sekä valovastus (LDR) on kytketty
const int summeri = 8;
const int valovastus = A2;

// Summerin minimi ja maksimitaajuudet (Hz)
const int minimiTaajuus = 50;
const int maksimiTaajuus = 20000;

// Mikrokontrollerin ja ohjelman alustaminen, suoritetaan kerran
// kontrollerin käynnistämisen yhteydessä.
void setup() {
}

// Pääsilmukka jota kutsutaan loputtomasti
void loop() {
  // Valovastuksen kirkkauden arvon muuttaminen summerin taajuudeksi
  int kirkkaus = analogRead(valovastus);
  int taajuus = map(kirkkaus, 0, 1023, minimiTaajuus, maksimiTaajuus);

  // Kanttiaallon tuottaminen summerille halutulla taajuudella
  tone(summeri, taajuus);
}

