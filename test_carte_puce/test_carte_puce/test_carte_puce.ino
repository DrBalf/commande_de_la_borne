#include <Wire.h>
#include "i2c.h"
#include "Arduino.h"


void setup() {
  Wire.begin();
  initI2C(122);
  Serial.begin(9600);
}

void loop() {
  short valeurPuce;
  Wire.requestFrom(0x21, 1);
  while(Wire.available()){
    valeurPuce=Wire.read();
    valeurPuce=(valeurPuce & 0x01);
    Serial.println(valeurPuce, BIN);
  }
  if (valeurPuce==0){
      Serial.println("if");
      Wire.requestFrom(0x50, 1);
      while(Wire.available()){
        short numeroPuce=Wire.read();
        Serial.println(numeroPuce, HEX);  
      }
  }
  delay(1000);
}

