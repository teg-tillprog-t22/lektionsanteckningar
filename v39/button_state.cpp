#include <Arduino.h>

const int BUTTON_PIN = 10;
const int LED_PIN = 12;
int lastState = LOW;

void setup() {
  Serial.begin(115200);

  pinMode(BUTTON_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
}


void loop() {
  int state = digitalRead(BUTTON_PIN);
  
  if (state!=lastState) {
    lastState = state;
    digitalWrite(LED_PIN, state);
    
    Serial.print(" State Changed to ");
    Serial.println(state);
    
  }
  
  delay(10); // this speeds up the simulation
}
