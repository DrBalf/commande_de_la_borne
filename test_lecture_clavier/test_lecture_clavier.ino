#include  <Wire.h>
#include  "i2c.h"
#include "Arduino.h"
#include "fonction.h"

void setup() {
  // put your setup code here, to run once:
Wire.begin();
initI2C(122);
Serial.begin(9600);
}

void loop(){
 validationCode(saisieCode());
 }


