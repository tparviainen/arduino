
#include "Sarjaportti.h"

Sarjaportti::Sarjaportti() {
  _sijainti = 0;
  _maksimiPituus = 0;
  _merkkijono = NULL;
}

// Alustaa vastaanotettavalle merkkijonolle maksimipituuden ja sarjaportille
// halutun kommunikointinopeuden.
void Sarjaportti::alusta(int pituus, int nopeus) {
  Serial.begin(nopeus);
  Serial.println("Muista asettaa sarjaportti lähettämään rivinvaihto (NL)!");

  _maksimiPituus = pituus;
  _merkkijono = (char*)malloc(_maksimiPituus + 1);
}

void Sarjaportti::tyhjenna() {
  memset(_merkkijono, 0, _sijainti);
  _sijainti = 0;
}

// Lukee merkkijonon sarjaportista ja palauttaa true kun merkkijono
// on kokonaan luettu, muutoin false.
bool Sarjaportti::onkoMerkkijonoLuettu() {
  while (Serial.available() > 0) {
    char merkki = Serial.read();

    if (merkki == '\n') {      
      return true;
    } else {
      if (_sijainti < _maksimiPituus) {
        _merkkijono[_sijainti++] = merkki;
      }
    }
  }

  return false;
}

char* Sarjaportti::merkkijono() {
  return _merkkijono;
}

