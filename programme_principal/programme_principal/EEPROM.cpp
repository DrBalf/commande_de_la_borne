#include <Wire.h>
#include "EEPROM.h"
#include "arduino.h"

void ecritureEEPROM (int adresseEEPROM, int adresseEcriture,  int valeurEEPROM){
  Wire.beginTransmission(adresseEEPROM); //on demare la transmission sur l'adresse EEPROM
                                         //passé en paramettre
  Wire.write(adresseEcriture);           //on ecrit sur l'adresse 0x20 la valeur adresseEcriture
                                         //qui presise a quelle adresse de l'EEPROM on veut écrire. 
                                        //on ecrie les donnée.
  Wire.write(valeurEEPROM);
  Wire.write('\0');
  Wire.endTransmission();  // fin de transmission 
   
}


int lectureEEPROM(int adresseEEPROM, int adresseLecture, int valeur){
  Wire.beginTransmission(adresseEEPROM); //on demare la transmission sur l'adresse EEPROM
                                         //passé en paramettre
  Wire.write(adresseLecture);            //on ecrit sur l'adresse 0x20 la valeur adresseLecture
                                         //qui presise a quelle adresse de l'EEPROM on veut lire
  Wire.endTransmission();
  Wire.requestFrom(adresseEEPROM,4);  //lecture des données 
  (valeur)=Wire.read();
    
  return valeur;
}
