# Edge detector
This libarary will detect any kind of transition on variable.

Exported class :
    
    Edge

3 methods :
 - rising : return true when variable goes from 0 to 1
 - falling : return true when variable goes from 1 to 0
 - changing : return true when variable goes from 0 to 1 or 1 to 0

 - init : set the initial value

 As the library is using template, you must specify the datatype in declaration :
 
    uint32_t sampled_variable;
    Edge<uint32_t> my_variable( sampled_variable );

# Basic example

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