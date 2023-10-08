#include "Arduino.h"
#include "edge.h"

uint32_t value=0;

Edge<uint32_t> test;

void setup() {
  Serial.begin(115200);
  Serial.println("test de détection de transition d'une variable");
  test.init(value);
}

void loop() {
  uint8_t rnd = rand()*100;
  value=( rnd > 50);
  Serial.print("new rnd : ");Serial.print(rnd);
  Serial.print("     test value : ");Serial.println(value);
  if(test.rising(value)) {
    Serial.println("value goes from 0 to 1");
  }
  if(test.falling(value)) {
    Serial.println("value goes from 1 to 0");
  }
  if(test.changing(value)) {
    Serial.print("value has changed to ");
    Serial.println(value);
  }
  delay(1000);
}