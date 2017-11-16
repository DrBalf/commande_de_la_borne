#include <Wire.h>
#include "i2c.h"
#include "Arduino.h"


void setup() {
  Wire.begin();
  initI2C(122);
  Serial.begin(9600);
}

void loop() {
  short valeurPuce;
  short lecture;
  short adressePuce;
  Wire.requestFrom(0x21, 1);
  while(Wire.available()){
    valeurPuce=Wire.read();
    valeurPuce=(valeurPuce & 0x01);
    Serial.print("valeurPuce :");
    Serial.println(valeurPuce);
    Serial.print("valeur 0x21 : ");
    Serial.println(0x21, BIN);
  }
  if (valeurPuce==0){
    Wire.requestFrom(0x21, 1);
    while (Wire.available()){
      Serial.print("lecture :");
      Serial.println(lecture, BIN);
      lecture=Wire.read();
      lecture=lecture|0x02;
      Serial.print("lecture masquer:");
      Serial.println(lecture, BIN);      
    }
    
    Wire.beginTransmission(0x21);
    Wire.write(lecture);
    Wire.endTransmission();
    
    Serial.print("distribution des signaux : ");
    Serial.println(0x21,BIN);
     
    Wire.requestFrom(0x50, 1);
    while (Wire.available()){
      adressePuce=Wire.read();
      Serial.print("adressePuce : ");
      Serial.println(adressePuce);
    }
  }
  delay(1000);
}

