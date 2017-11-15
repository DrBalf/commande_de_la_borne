#include "digicode.h"
#include <Wire.h>
#include <arduino.h>

int pushButon(){
  short lecture;
  short i=1;

  while(i==1){
    Wire.requestFrom(0x22, 1);
    while(Wire.available()){
      lecture=Wire.read(); 
    }
    if(lecture!=0xF0){
     i=0;
    }
  }
}

int lectureLigne(){
  short lectureL;
  short ligne;
  Wire.beginTransmission(0x22);
  Wire.write(0xF0);
  Wire.endTransmission();
  Wire.requestFrom(0x22, 1);
  while(Wire.available()){
    lectureL = Wire.read();
    //Serial.print("ligne:");
    //Serial.println(lectureL,HEX);
     switch(lectureL){
       case 0xE0:
       ligne=0;
      break;
       case 0xD0:
       ligne=1;
      break;
       case 0xB0:
       ligne=2;
      break;
       case 0x70:
       ligne=3;
      break;
    }
    //Serial.print("ligne:");
    //Serial.println(ligne);
  }
  return ligne;
}

int lectureColonne(){
  short lectureC;
  short colonne;
  Wire.beginTransmission(0x22);
  Wire.write(0x0F);
  Wire.endTransmission();
  Wire.requestFrom(0x22, 1);
  while(Wire.available()){
    lectureC = Wire.read();
    //Serial.print("colonne:");
    //Serial.println(lectureC,HEX);
    switch(lectureC){
       case 0xE:
       colonne=0;
      break;
       case 0xD:
       colonne=1;
      break;
       case 0xB:
       colonne=2;
      break;
       case 0x7:
       colonne=3;
      break;
    }
    //Serial.print("colonne:");
    //Serial.println(colonne);
  }
  return colonne;
}

char traductionClavier(int ligne, int colonne){
  char clavier[4][4] = {{'1','2','3','r'},{'4','5','6','r'},{'7','8','9','G'},{'*','0','#','r'}};
  char caractere = clavier[ligne][colonne];
  return caractere;
}

int validationCode(char* code){
  int i=0;
  int validation=0;
  char codeRef[4]={'1','4','7','2'};
  for(i=0;i<=3;i++){
    if(code[i]==codeRef[i]){
      validation=1;
    }
    else{
      validation=0;
    }  
  }
  return validation;
}

char* saisieCode(){
  int i;
  char* ptrCode; 
  ptrCode = new char[4];
  for(i=0;i<=3;i++){
    pushButon();
    char colonne = lectureColonne();
    char ligne = lectureLigne();
    ptrCode[i]=traductionClavier(ligne,colonne);
    delay(250);
  }
  Serial.print(ptrCode);
  return ptrCode;
}
