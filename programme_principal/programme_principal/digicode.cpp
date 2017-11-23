#include "digicode.h"
#include <Wire.h>
#include <arduino.h>

int pushButon(){
  short lecture;
  short i=1;
  Wire.beginTransmission(0x22);
  Wire.write(0xF0);
  Wire.endTransmission();
  Wire.requestFrom(0x22, 1);
  while(Wire.available()){
    lecture=Wire.read(); 
    if(lecture!=0xF0){
     i=0;
    }
  }
  return i;
}

int lectureColonne(){
  short lectureC;
  short colonne;
  Wire.beginTransmission(0x22);
  Wire.write(0xF0);
  Wire.endTransmission();
  Wire.requestFrom(0x22, 1);
  while(Wire.available()){
    lectureC = Wire.read();
    //Serial.print("ligne:");
    //Serial.println(lectureL,HEX);
     switch(lectureC){
       case 0xE0:
       colonne=0;
      break;
       case 0xD0:
       colonne=1;
      break;
       case 0xB0:
       colonne=2;
      break;
       case 0x70:
       colonne=3;
      break;
    }
    Serial.print("ligne_:");
    Serial.println(colonne);
  }
  return colonne;
}

int lectureLigne(){
  short lectureL;
  short ligne;
  Wire.beginTransmission(0x22);
  Wire.write(0x0F);
  Wire.endTransmission();
  Wire.requestFrom(0x22, 1);
  while(Wire.available()){
    lectureL = Wire.read();
    //Serial.print("colonne:");
    //Serial.println(lectureC,HEX);
    switch(lectureL){
       case 0xE:
       ligne=0;
      break;
       case 0xD:
       ligne=1;
      break;
       case 0xB:
       ligne=2;
      break;
       case 0x7:
       ligne=3;
      break;
    }
    Serial.print("colonne_:");
    Serial.println(ligne);
  }
  return ligne;
}

char traductionClavier(int ligne, int colonne){
  char clavier[4][4] = {{'1','2','3','r'},{'4','5','6','r'},{'7','8','9','G'},{'*','0','#','r'}};
  char caractere = clavier[ligne][colonne];
  return caractere;
}

int validationCode(){
  int i=0;
  int validation=0;
  char codeRef[4]={'1','2','3','4'};
  char* code;
  if (pushButon()==0){
    code=saisieCode();
    for(i=0;i<=3;i++){
      Serial.print(code[i]);
      if(code[i]==codeRef[i]){
        validation=1;
      }
      else{
        validation=0;
        Serial.println("code errone");
      }  
    }
  }
  return validation;
}

char* saisieCode(){
  int i;
  char ptrCode=; 
  for(i=0;i<=3;i++){
    while (pushButon()==1);
    char colonne = lectureColonne();
    char ligne = lectureLigne();
    ptrCode[i]=traductionClavier(ligne,colonne);
    Serial.print(traductionClavier(ligne,colonne));
    delay(20);
    while (pushButon()==0);
  }
  return ptrCode;
}
