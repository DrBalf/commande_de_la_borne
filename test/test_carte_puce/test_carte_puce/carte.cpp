#include "carte.h"
#include <Wire.h>
#include <arduino.h>


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
  char code[5]={'3','4','5','6','\0'};
  Serial.print("_");
  if (presenceCarte()==0){
      Serial.print("-");
      accesCarteOn();
           
      Wire.beginTransmission(0x50);
        Wire.write(0x00);
      while((*(code+i))!='\0'){
        *(valeurPuce+i)=Wire.write(*(code+i));
        Serial.print(*(code+i));
        Serial.print(*(valeurPuce+i));
        i++;
      }
      Wire.write('\0');
      Wire.endTransmission();

      accesCarteOff();
  }
  return valeurPuce; 
}

int validationCarte (){
  int validation=0;
  char adresseRef[4]={'3','4','5','6'};
  char valeurPuce[4]={'0','0','0','0'};
  char* adresseValeur;
  Serial.print("go");
  adresseValeur=lectureCarte(valeurPuce);
  for(int i=0;i<4;i++){
      if(adresseValeur[i]==adresseRef[i]){
        validation=1;
      }
      else{
        validation=0;        
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


