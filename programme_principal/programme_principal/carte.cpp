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

char* lectureCarte(){
  short lecture;
  char valeurPuce[4];
  int i=0;
  Wire.requestFrom(0x21, 1);
  while (Wire.available()){
    lecture=Wire.read();
    lecture=lecture|0x02;     
  }
  
  Wire.beginTransmission(0x21);
  Wire.write(lecture);
  Wire.endTransmission();
  
    Wire.requestFrom(0x50, 4);
    while (Wire.available()){
      valeurPuce[i]=Wire.read();
      Serial.println(valeurPuce[i]);
      i++;
    }
  while (presenceCarte()==0);
  return valeurPuce; 
}

int validation (char* tbl){
  int validation=0;
  char adresseRef[4]={'3','4','5','6'};
  for(int i=0;i<4;i++){
      if(tbl[i]==adresseRef[i]){
        validation=1;
        Serial.println(tbl[i]);
      }
      else{
        validation=0;
      }
  }
  return validation;
}

