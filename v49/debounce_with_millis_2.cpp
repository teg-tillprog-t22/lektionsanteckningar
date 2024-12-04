#include <Arduino.h>

const int BUTTON_PIN = 41; // Vilken pin knappen ska vara på
const int LED_PIN = 4; // Vilken pin LED:en ska vara på

const unsigned long debounceDelay = 20; // Hur länge vi ska vänta för en debounce

int ledState = LOW; // LED:en börjar vara släckt
int lastButtonState = HIGH;
unsigned long lastChangeTime = 0;

void setup() {
  Serial.begin(115200);

  pinMode(BUTTON_PIN, INPUT_PULLUP); // Vilken slags pin det ska vara för knappen
  pinMode(LED_PIN, OUTPUT); // Vilken slags pin det ska vara för LED:en
}

void loop() {

  int reading = digitalRead(BUTTON_PIN); // Läser av knappen varje gång i loopen

  if (reading==lastButtonState)
  {
      lastChangeTime = millis();
  }
  else 
  {
    if (millis() - lastChangeTime > debounceDelay)
    {
      lastButtonState = reading;
      Serial.print(millis()); // För felsökning
      Serial.print(": Byte bekräftat till läge "); // För felsökning
      Serial.println(reading); // För felsökning

      // HÄR KAN VI UTFÖRA KOD SOM SKER VID ÖVERGÅNGEN
      if (lastButtonState==LOW) { 
        ledState = !ledState;
        digitalWrite(LED_PIN, ledState);
      }
    }
  }
}
