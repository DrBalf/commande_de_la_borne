#include <Wire.h>
#include "i2c.h"
#include "Arduino.h"


void setup() {
  Wire.begin();
  initI2C(122);
  Serial.begin(9600);
}

void loop() {
  Wire.requestFrom(0x21, 1);
  short valeurPuce=Wire.read();
  Serial.println(valeurPuce, BIN);
  delay(1000);
}
