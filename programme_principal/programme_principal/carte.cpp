#include "carte.h"
#include <Wire.h>
#include <arduino.h>
#include "affiche.h"

int presenceCarte (){
  short carteIn;
  Wire.requestFrom(0x21, 1);
  while(Wire.available()){
    carteIn=Wire.read();
    carteIn=(carteIn & 0x01);
  }

  return carteIn;  
}

char* lectureCarte(char* valeurPuce){
  int i=0;
  if (presenceCarte()==0){

      accesCarteOn();
           
      Wire.beginTransmission(0x50);
      Wire.write(0x00);
      Wire.endTransmission();
      
      Wire.requestFrom(0x50, 4);
      while (Wire.available()){
        valeurPuce[i]=Wire.read();
        i++;
      }

      accesCarteOff();
  }
  return valeurPuce; 
}

int validationCarte (){
  int validation=0;
  char adresseRef[4]={'3','4','5','6'};
  char valeurPuce[4]={'0','0','0','0'};
  char* adresseValeur;
  if (presenceCarte()==0){
    adresseValeur=lectureCarte(valeurPuce);
    for(int i=0;i<4;i++){
        if(adresseValeur[i]==adresseRef[i]){
          validation=1;
        }
        else{
          validation=0;        
        }
    }
    if (validation==1){
        envoyerMessage(0x3B, MESSAGE3, LIGNE1);
        envoyerMessage(0x3B, MESSAGE4, LIGNE2);
    }
    else{
        envoyerMessage(0x3B, MESSAGE7, LIGNE1);
        envoyerMessage(0x3B, MESSAGE8, LIGNE2);
    }
  }
  return validation;
}

void accesCarteOn (void){
                  
      Wire.beginTransmission(0x21);
      Wire.write(0x06);
      Wire.endTransmission();
  
}

void accesCarteOff (void){

      Wire.beginTransmission(0x21);
      Wire.write(0x05);
      Wire.endTransmission();
  
}
