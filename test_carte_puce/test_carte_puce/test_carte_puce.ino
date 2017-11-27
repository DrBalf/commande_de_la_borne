#include <Wire.h>
#include "i2c.h"
#include "Arduino.h"
#include "carte.h"


void setup() {
  Wire.begin();
  initI2C(122);
  Serial.begin(9600);
  initEEPROM();
}

void loop() { 

      
      
      if (validationCarte()==1){
          Serial.println("bravo");
      }
      delay(2000);
}

