#include <Wire.h>
#include "i2c.h"
#include "Arduino.h"


void setup() {
  Wire.begin(); //on indique que la transmision cera en I2C
  initI2C(122); //on initialise la vitesse de transmission 

}

void loop() {
  
  Wire.beginTransmission(0x20); //Permet de commencer la transmission 
                                //a l'adresse 0x20
  Wire.write(0xFE);             //Permet d'écrire sur l'adresse 0x20
                                //la valeur 0xFE qui correspond a la 
  delay(1000);                  //fermeture de la barrière.
  Wire.endTransmission();       //Permet de mettre fin a la transmission

}
