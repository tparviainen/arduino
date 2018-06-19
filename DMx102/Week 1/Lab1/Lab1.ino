int green = 4;
int orange = 3;
int red = 2;

void blinkLed(int led, int delayInSeconds) {
    digitalWrite(led, HIGH);
    delay(delayInSeconds * 1000);
    digitalWrite(led, LOW);
}

void setup() {
    pinMode(green, OUTPUT);
    pinMode(orange, OUTPUT);
    pinMode(red, OUTPUT);
}

void loop() {
    blinkLed(green, 3);
    blinkLed(orange, 1);
    blinkLed(red, 3);
}

