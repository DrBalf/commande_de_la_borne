#include <Wire.h>
#include "i2c.h"
#include "Arduino.h"


void setup() {
  
  initI2C(122);

}

void loop() {
  
  Wire.beginTransmission(0x20);
  Wire.write(0x35);
  Wire.endTransmission();

}
