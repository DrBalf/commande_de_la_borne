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

  lectureEEPROM(0x00);
  Serial.println("----------------------");
  ecritureCodeEEPROM();
  valeurEEPROM=lectureEEPROM(0x00);
  for(int i=0;i<4;i++){
  Serial.println(valeurEEPROM[i]);
  }
  Serial.println("======================");
  lectureEEPROM(0x00);
  Serial.println("**********************");
  delay(5000);

}
