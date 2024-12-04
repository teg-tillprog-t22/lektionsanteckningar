#include <Arduino.h>

const int BUTTON_PIN = 41; // Vilken pin knappen ska vara på
const int LED_PIN = 4; // Vilken pin LED:en ska vara på

const unsigned long debounceDelay = 20; // Hur länge vi ska vänta för en debounce

int ledState = LOW; // LED:en börjar vara släckt
bool debouncing = false;
int lastButtonState = HIGH;
unsigned long lastChangeTime = 0;

void setup() {
  Serial.begin(115200);

  pinMode(BUTTON_PIN, INPUT_PULLUP); // Vilken slags pin det ska vara för knappen
  pinMode(LED_PIN, OUTPUT); // Vilken slags pin det ska vara för LED:en
}

void loop() {

  int reading = digitalRead(BUTTON_PIN); // Läser av knappen varje gång i loopen

  // Loopen har två states
  // Debouncing som innebär att det håller på att vänta ut studsar
  if (debouncing)
  {
    if ((millis() - lastChangeTime) > debounceDelay)
    {
      // Bara giltig förändring om vi fortfarande är i ett nytt läge
      if (reading!=lastButtonState)
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
      else 
      {
        Serial.print(millis()); // För felsökning
        Serial.print(": Byte EJ bekräftat, kvarstår i "); // För felsökning
        Serial.println(reading); // För felsökning
      }

      debouncing = false;
    }
  }
  else
  {
    // Loopens andra state
    // Inte debouncing som innebär att programmet väntar på en knapptryckning

    if (reading!=lastButtonState)
    {
      lastChangeTime = millis();
      debouncing = true;
      
      Serial.print(millis()); // För felsökning
      Serial.print(": Väntar på studsar innan byte till läge "); // För felsökning
      Serial.println(reading); // För felsökning
    } 
  }
}
