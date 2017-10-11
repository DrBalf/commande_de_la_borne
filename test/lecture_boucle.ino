#include <Wire.h>
#include "i2c.h"
#include "Arduino.h"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Wire.begin();
  initI2C(122);
}

void loop() {
  // put your main code here, to run repeatedly:
    
   Wire.requestFrom(0x20,1);
   while(Wire.available()){
    short boucle = Wire.read();
   
    Serial.print(boucle & 0x60, BIN); 
    Serial.print("_"); 
  }
  delay(5000);
}
