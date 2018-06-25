#pragma once

// https://www.arduino.cc/en/Reference/APIStyleGuide
// https://www.arduino.cc/en/Reference/StyleGuide
class Sarjaportti
{
  public:
    Sarjaportti();
    void alusta(int pituus, int nopeus = 9600);
    void tyhjenna();
    bool onkoMerkkijonoLuettu();
    char* merkkijono();

  private:
    int _sijainti;
    int _maksimiPituus;
    char* _merkkijono;
};

