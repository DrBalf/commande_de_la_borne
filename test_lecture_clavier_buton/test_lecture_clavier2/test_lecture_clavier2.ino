#include  <Wire.h>
#include  "i2c.h"
#include "Arduino.h"

void setup() {
  // put your setup code here, to run once:
  Wire.begin();
initI2C(122);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Wire.requestFrom(0x22, 1);
  while(Wire.available()){
  short lecture = Wire.read();
  while( lecture != 0xFF){
    Serial.println(lecture);
    Serial.println("bravo!");
  }
  }
}
