#include <Wire.h>
#include "i2c.h"
#include "Arduino.h"

void setup() {
  // put your setup code here, to run once:
  Wire.begin();
  initI2C(122);
}

void loop() {
  // put your main code here, to run repeatedly:
    Wire.beginTransmission(0x20);
    Wire.write(0xFF);
    Wire.endTransmission(); 
}
