#include "carte.h"
#include <Wire.h>
#include <arduino.h>

int validationCarte (){
  short valeurPuce;
  Wire.requestFrom(0x21, 1);
  while(Wire.available()){
    valeurPuce=Wire.read();
    Serial.print("valeurPuce avant masque : ");
    Serial.println(valeurPuce, BIN);
    valeurPuce=(valeurPuce & 0x01);
    Serial.print("valeurPuce : ");
    Serial.println(valeurPuce, BIN);
  }
  return valeurPuce;  
}
