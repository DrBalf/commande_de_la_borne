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
    boucle=(boucle &0x20)>>5;
    if (boucle==0){
      Serial.print("ok_");
    }
    Serial.print(boucle, BIN); 
    Serial.print("_"); 
  }
  delay(5000);
}
