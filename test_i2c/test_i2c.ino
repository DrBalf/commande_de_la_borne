#include <Wire.h>
#include "i2c.h"
#include "Arduino.h"


void setup() {
  Wire.begin();
  initI2C(122);

}

void loop() {
  
  Wire.beginTransmission(0x20);
  Wire.write(0xFD);
  delay(1000);
  Wire.endTransmission();

}
