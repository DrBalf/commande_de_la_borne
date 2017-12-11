#include <Wire.h>
#include "i2c.h"
#include "EEPROM.h"

void setup() {
  Wire.begin();
  initI2C(60);
  Serial.begin(9600);

}

void loop() {
  char* valeurEEPROM;
  
  ecritureCodeEEPROM();
  valeurEEPROM=lectureEEPROM(0x00);
  Serial.println(valeurEEPROM);
  delay(5000);

}
