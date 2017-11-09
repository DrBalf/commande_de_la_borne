#include "barriere.h"
#include <Wire.h>
#include <arduino.h>

void ouvrir (){
  Wire.beginTransmission(0x20); //on demare la transmission sur l'adresse 0x20
  Wire.write(0xFD);           //on ecrit sur l'adresse 0x20 la valeur 0xFD qui 
                              //correspond a la valeur d'ouvertur de barriere 
  Wire.endTransmission();     //fin de transmission
}

void fermer (){
  Wire.beginTransmission(0x20);
  Wire.write(0xFE);         //on ecrit sur l'adresse 0x20 la valeur 0xFE qui 
  delay(50);                          //correspond a la valeur de fermeture de barriere 
  Wire.endTransmission();
}
