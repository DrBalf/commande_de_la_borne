#include  <Wire.h>
#include "Arduino.h"
#include "fonction.h"

int pushButon(){
  short lecture=NULL;
  short i=1;
  Wire.beginTransmission(0x38);
  Wire.write(0xF0);
  Wire.endTransmission();
  while(i==1){
    Wire.requestFrom(0x38, 1);
    while(Wire.available()){
      lecture=Wire.read(); 
    }
    if (lecture!=0xF0){
      i=0;
    }
  }
}

int lectureLigne(){
  short lectureL;
  short ligne=NULL;
  Wire.beginTransmission(0x38);
  Wire.write(0xF0);
  Wire.endTransmission();
  Wire.requestFrom(0x38, 1);
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
  short colonne=NULL;
  Wire.beginTransmission(0x38);
  Wire.write(0x0F);
  Wire.endTransmission();
  Wire.requestFrom(0x38, 1);
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
  char clavier[4][4] = {{'1','2','3',NULL},{'4','5','6',NULL},{'7','8','9','G'},{'*','0','#',NULL}};
  char caractere = clavier[ligne][colonne];
  Serial.print("caractere:");
  Serial.println(caractere);
  return caractere;
}










char* saisieCode(){
  char* code[4]; 
  code= new char[4]
  for(i=0;i<3;i++){
    pushButton();
    char colonne = lectureColonne();
    char ligne = lectureLigne();
    code[i]=traductionClavier(ligne,colonne);
    delete[] code;
  }
}
  

