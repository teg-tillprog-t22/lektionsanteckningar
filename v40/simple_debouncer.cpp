#include <Arduino.h>

const int BUTTON_PIN = 10;
const int LED_PIN = 12;
int lastState = LOW;
int ledState = HIGH;

void setup() {
  Serial.begin(115200);

  pinMode(BUTTON_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  int reading = digitalRead(BUTTON_PIN);
  
  if (reading!=lastState) {
    // Här har programmet detekterat en förändring i knappen
    // Då väntar vi 50 ms
    delay(50);
    // Sedan gör vi en ny avläsning av pinnen
    reading = digitalRead(BUTTON_PIN);
    // Och kollar återigen om knappen är i samma läge som nyss
    if (reading!=lastState) {
      // Om den är det så känner vi oss nöjda
      lastState = reading;

      if (lastState==LOW) {
        ledState = !ledState;
        digitalWrite(LED_PIN, ledState);
      }
      
      Serial.print(" State Changed to ");
      Serial.println(lastState);
    }
  }
  
  // Vi bör inte använda någon delay när vi ska testa debounce-kod
  // delay(10); // this speeds up the simulation
}
