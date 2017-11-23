#include "carte.h"
#include <Wire.h>
#include <arduino.h>


int presenceCarte (){
  short carteIn;
  Serial.println("presenceCarte");
  Wire.requestFrom(0x21, 1);
  while(Wire.available()){
    carteIn=Wire.read();
    carteIn=(carteIn & 0x01);
    Serial.println("valeur carteIn : ");
    Serial.println(carteIn, BIN);
  }
  Serial.println("presenceCarte return");
  return carteIn;  
}

char* lectureCarte(char* valeurPuce){
  int i=0;
  Serial.println("lectureCarte");
  if (presenceCarte()==0){
           
      Wire.beginTransmission(0x21);
      Wire.write(0x06);
      Wire.endTransmission();

      Wire.beginTransmission(0x50);
      Wire.write(0x00);
      Wire.endTransmission();
      
      Wire.requestFrom(0x50, 4);
      while (Wire.available()){
        valeurPuce[i]=Wire.read();
        Serial.println(valeurPuce[i]);
        i++;
        Serial.print("valeurPuce ");
        Serial.println(i);
      }
      while (presenceCarte()==0);        
  }
  Serial.println("lectureCarte retrun");
  return valeurPuce; 
}

int validationCarte (){
  int validation=0;
  char adresseRef[4]={'3','4','5','6'};
  char valeurPuce[4]={'0','0','0','0'};
  char* adresseValeur;
  Serial.println("validationCarte");
  adresseValeur=lectureCarte(valeurPuce);
  for(int i=0;i<4;i++){
      if(adresseValeur[i]==adresseRef[i]){
        validation=1;
        Serial.println(adresseValeur[i]);
        Serial.println("=");
        Serial.println(adresseRef[i]);
      }
      else{
        validation=0;
        
      }
  }
  Serial.println("validationCarte return");
  return validation;
}

