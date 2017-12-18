#include  <Wire.h>
#include  "i2c.h"
#include "Arduino.h"

void setup() {
  // put your setup code here, to run once:
Wire.begin();
initI2C(122);
}

void loop() {
  // put your main code here, to run repeatedly:
Wire.beginTransmission(0x21);
while(1){
Wire.write(0xF1);
delay(50);
Wire.write(0xF5);
delay(50);
}
Wire.endTransmission();

}
