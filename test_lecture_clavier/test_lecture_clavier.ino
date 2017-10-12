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
Wire.beginTransmission(0x20);
Wire.write(0xFD);
Wire.endTransmission();
 
}
