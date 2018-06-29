/*
 * Lab 2 - liikennevalojen sekä jalankulkijan valojen ohjaus
 */

// I/O pinnit johon autojen liikennevalot on kytketty
const int autoilijaVihrea = 10;
const int autoilijaOranssi = 11;
const int autoilijaPunainen = 12;

// I/O pinnit johon jalankulkijoiden liikennevalot on kytketty
const int jalankulkijaPunainen = 9;
const int jalankulkijaVihrea = 8;

// I/O pinni jalankulkijan liikennevalojen vaihtamiseen
const int jalankulkijaPainike = 2;

// Mikrokontrollerin ja ohjelman alustaminen, suoritetaan kerran
// kontrollerin käynnistämisen yhteydessä.
void setup() {
  // Autojen liikennevalojen I/O pinnien alustaminen
  pinMode(autoilijaVihrea, OUTPUT);
  pinMode(autoilijaOranssi, OUTPUT);
  pinMode(autoilijaPunainen, OUTPUT);

  // Jalankulkijoiden I/O pinnien alustaminen
  pinMode(jalankulkijaPunainen, OUTPUT);
  pinMode(jalankulkijaVihrea, OUTPUT);
  pinMode(jalankulkijaPainike, INPUT);

  // Oletuksena jalankulkijalla on punainen valo
  digitalWrite(jalankulkijaPunainen, HIGH);
}

// Pääsilmukka jota kutsutaan loputtomasti
void loop() {
  // Vihreä ledi ON/OFF
  digitalWrite(autoilijaVihrea, HIGH);
  delay(3000);
  digitalWrite(autoilijaVihrea, LOW);

  // Luetaan painonapin tila jonka perusteella päätetään sytytetäänkö
  // jalankulkijoille valoja.
  int painikkeenTila = digitalRead(jalankulkijaPainike);

  // Oranssi ledi ON/OFF
  digitalWrite(autoilijaOranssi, HIGH);
  delay(1000);
  digitalWrite(autoilijaOranssi, LOW);

  // Autoilijoille punaiset valot
  digitalWrite(autoilijaPunainen, HIGH);

  // Tarkistetaan onko jalankulkija painanut painonappia
  if (painikkeenTila == HIGH) {
    // Jalankulkija haluaa ylittää tien, vaihdetaan jalankulkijoille vihreät
    digitalWrite(jalankulkijaPunainen, LOW);
    digitalWrite(jalankulkijaVihrea, HIGH);

    delay(5000);

    // Vaihdetaan jalankulkijoille punaiset valot
    digitalWrite(jalankulkijaVihrea, LOW);
    digitalWrite(jalankulkijaPunainen, HIGH);
  }
  else {
    // Normaalitilanteessa pidetään autoilijoilla punaiset valot 3 sekuntia
    delay(3000);
  }

  // Sammutetaan autoilijoiden punaiset valot
  digitalWrite(autoilijaPunainen, LOW);
}

