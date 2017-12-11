#include <Wire.h>
#include "EEPROM.h"
#include <arduino.h>

void ecritureCodeEEPROM (){

  char valeurCodeEEPROM[4]={'3','4','5','6'};

  Wire.beginTransmission(0x57);
  Wire.write(0x00);
  Wire.endTransmission();
  
  Wire.beginTransmission(0x57);
  Wire.write(valeurCodeEEPROM, 4);
  Wire.endTransmission();
  
}

char* lectureEEPROM(int adresse){

  char valeurEEPROM[4]={'9','9','9','9'};
  char* adresseValeurEEPROM;
  int i=0;
  
  Serial.print("valeurEEPROM : ");
  Serial.println(valeurEEPROM);
  
  Wire.beginTransmission(0x57);
  Wire.write(adresse);
  Wire.endTransmission();

  Wire.requestFrom(0x57, 4); // on lit les 4 premier octet
      while (Wire.available()){
        valeurEEPROM[i]=Wire.read(); //on enregistres chaque valeur a une  
        i++;                       //adresse la première étant valeurPuce[0]
      }
      
  adresseValeurEEPROM=valeurEEPROM;
  Serial.print("adresse valeur 1: ");
  Serial.println(&valeurEEPROM[0]);
  Serial.print("adresse valeur 2: ");
  Serial.println(&valeurEEPROM[1]);
  Serial.print("adresse valeur 3: ");
  Serial.println(&valeurEEPROM[2]);
  Serial.print("adresse valeur 4: ");
  Serial.println(&valeurEEPROM[3]);
  Serial.print("adresse valeur 5: ");
  Serial.println(&valeurEEPROM[4]);
  Serial.print("adresse valeur 6: ");
  Serial.println(&valeurEEPROM[5]); 
  Serial.print("adresse valeur 7: ");
  Serial.println(&valeurEEPROM[6]);
  Serial.print("adresse valeur 8: ");
  Serial.println(&valeurEEPROM[7]);
  Serial.print("adresseValeurEEPROM : ");
  Serial.println(adresseValeurEEPROM);
  return adresseValeurEEPROM;
}

