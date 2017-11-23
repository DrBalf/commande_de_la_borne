#include <Wire.h>
#include "i2c.h"
#include "Arduino.h"
#include "carte.h"


void setup() {
  Wire.begin();
  initI2C(122);
  Serial.begin(9600);
}

void loop() { 
   
      if (validationCarte()==1){
        Serial.println("bravo");
      }
      else{
        Serial.println("pas bravo");
      }
      delay(5000);
}

