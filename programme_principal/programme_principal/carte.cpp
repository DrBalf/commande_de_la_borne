#include "carte.h"
#include <Wire.h>
#include <arduino.h>

int validationCarte (){
  short valeurPuce;
  Wire.requestFrom(0x21, 1);
  while(Wire.available()){
    valeurPuce=Wire.read();
  }
  valeurPuce=(valeurPuce & 0x01);
  return valeurPuce;  
}
