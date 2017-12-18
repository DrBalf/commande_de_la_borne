#include <Wire.h>
#include "EEPROM.h"
#include "arduino.h"

void ecritureCodeEEPROM (int adresseEEPROM, int adresseEcriture, const char* ptcCodeEEPROM){
  int i=0;
  Wire.beginTransmission(adresseEEPROM);
  Wire.write(adresseEcriture);
  while((*(ptcCodeEEPROM+i))!='\0'){
    Wire.write(*(ptcCodeEEPROM+i));
    i++;
  }
  Wire.write('\0');
  Wire.endTransmission();   
   
}


void lectureEEPROM(int adresseEEPROM, int adresseLecture, char* ptc){
  int i=0;
  Wire.beginTransmission(adresseEEPROM);
  Wire.write(adresseLecture);
  Wire.endTransmission();
  Wire.requestFrom(adresseEEPROM,5); 
  while((*(ptc+i)=Wire.read())!='\0'){
    i++;
  }
}




