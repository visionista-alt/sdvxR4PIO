#include "Arduino.h"
#include "Keyboard.h"

void setup() {
  // open the serial port:
  Serial.begin(9600);
  // initialize control over the keyboard:
  Keyboard.begin();
  pinMode(2, INPUT_PULLUP);
}

void loop() {
  // check for incoming serial data:
  if (digitalRead(2) == LOW) {
    Keyboard.press('a');
    Serial.println("pushed");
    while(digitalRead(2) == LOW){
    };
    Keyboard.release('a');
  }
  delay(20);
}
