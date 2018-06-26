# Akselikulma
Tämän ohjelman avulla voi asettaa servon akselin haluttuun kulmaan antamalla kulman asteina sarjamonitorin kautta. Ohessa kuvaruutukaappaus missä servon akselikulmaksi on asetettu 180 astetta, tällöin PWM pulssin leveys on 2.5ms ohjausperiodin pysyessä 20ms:ssa.

<p align="center">
  <img alt="Akselikulma" src="https://user-images.githubusercontent.com/25169598/41929118-e6549240-797f-11e8-9524-b281ca588ce1.jpg">
</p>

**Huom!** Normaalisti servon ohjauksessa PWM:n reuna-arvot ovat 1ms sekä 2ms mutta koska useat valmistajat eivät noudata tarkasti annettuja arvoja pitää PWM:n pulssinleveyksiä muuttaa sopiviksi omalle servolle. Tämä asia on mainittu Arduinon Servo kirjaston [dokumentaatiossa](https://www.arduino.cc/en/Reference/ServoWriteMicroseconds).
