#include "affiche.h"
#include <Wire.h>
#include "i2c.h"

void setup() {
  Wire.begin();
  initI2C(122);
  initAfficheur(0x3B);
}

void loop() {
   setEclairage(0x3B, 1);
   envoyerMessage(0x3B, MESSAGE1, LIGNE1);
   envoyerMessage(0x3B, MESSAGE2, LIGNE2);
   delay(5000);
   envoyerMessage(0x3B, MESSAGE3, LIGNE1);
   envoyerMessage(0x3B, MESSAGE4, LIGNE2);
   delay(5000);
   
}
