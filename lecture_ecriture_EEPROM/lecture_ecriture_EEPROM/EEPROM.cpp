#include <Wire.h>
#include "EEPROM.h"
#include <arduino.h>

void ecritureCodeEEPROM (){

  char valeurCodeEEPROM[5]={'4','6','2','3','\0'};

  Wire.beginTransmission(0x57);
  Wire.write((char)(0x00));
  Wire.write(valeurCodeEEPROM,4);
  Wire.endTransmission();
  
  /*Wire.beginTransmission(0x57);
  Wire.write(valeurCodeEEPROM,1);
  Wire.endTransmission();*/

  Serial.println (valeurCodeEEPROM);
  
}

char* lectureEEPROM(int adresse){

  char valeurEEPROM[5]={'0','0','0','0','\0'};
  char* adresseValeurEEPROM=NULL;
  int i=0;
  
  Serial.print("valeurEEPROM : ");
  Serial.println(valeurEEPROM);
  
  Wire.beginTransmission(0x57);
  Wire.write(adresse);
  Wire.endTransmission();

  for (i=0;i<4;i++){
  Wire.requestFrom(0x57, 1); // on lit les 4 premier octet
  valeurEEPROM[i]=Wire.read(); //on enregistres chaque valeur a une  
                               //adresse la première étant valeurPuce[0]
  }
      
  adresseValeurEEPROM=valeurEEPROM;
  Serial.print("valeur 1: ");
  Serial.println(valeurEEPROM[0]);
  Serial.print("valeur 2: ");
  Serial.println(valeurEEPROM[1]);
  Serial.print("valeur 3: ");
  Serial.println(valeurEEPROM[2]);
  Serial.print("valeur 4: ");
  Serial.println(valeurEEPROM[3]);
  Serial.print("adresseValeurEEPROM : ");
  Serial.println(adresseValeurEEPROM);
  return adresseValeurEEPROM;
}

