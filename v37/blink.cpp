#include <arduino.h>

const int LED_PIN = 4;

void setup() {
    Serial.begin(115200);
    Serial.println("Startar!");

    pinMode(LED_PIN, OUTPUT);
}

void loop() {
    Serial.println("Tänder LED");
    digitalWrite(LED_PIN, HIGH);
    delay(500);

    Serial.println("Släcker LED");
    digitalWrite(LED_PIN, LOW);
    delay(1000);
}
