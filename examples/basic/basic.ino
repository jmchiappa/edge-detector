#include "Arduino.h"
#include "edge.h"

uint32_t value=0;

Edge<uint32_t> test;

void setup() {
  Serial.begin(230400);
  Serial.println("test de détection de transition d'une variable");
  test.init(value);
}

void loop() {
  value=(rand()*100 > 50);
  Serial.print("value : ");Serial.println(value);
  if(test.changing(value)) {
    Serial.print("value has changed to ");
    Serial.println(value);
  }
  delay(100);
}