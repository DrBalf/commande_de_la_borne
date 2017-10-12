#include <Wire.h>
#include "Arduino.h"
#include "fonction.h"


int testBoucleAmont (){
  short boucle;
  Wire.requestFrom(0x20,1);
  while(Wire.available()){
      boucle = Wire.read();
      }
  boucle=(boucle & 0x20)>>5;
  return boucle;
}


int testBoucleAval (){
  short boucle;
  Wire.requestFrom(0x20,1);
  while(Wire.available()){
      boucle = Wire.read();
      }
  boucle=(boucle & 0x40)>>6;
  return boucle;
}

void ouvrir (){
  Wire.beginTransmission(0x20);
  Wire.write(0xFD);
  delay(1000);
  Wire.endTransmission();
}

void fermer (){
  Wire.beginTransmission(0x20);
  Wire.write(0xFE);
  delay(1000);
  Wire.endTransmission();
}
