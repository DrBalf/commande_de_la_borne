#include <Wire.h>
#include "EEPROM.h"

/*cette macro permet de placer \u00e0 1 le bit d'un registre*/
#ifndef sbi
#define sbi(sfr,bit) (_SFR_BYTE(sfr)|=_BV(bit))
#endif
/*cette macro permet de placer \u00e0 0 le bit d'un registre*/
#ifndef cbi
#define cbi(sfr,bit) (_SFR_BYTE(sfr)&=~_BV(bit))
#endif

char valeurEEPROM[5]={'0','0','0','0','\0'};
char valeurCodeEEPROM[5]={'7','8','3','6','\0'};

void setup() {
  Wire.begin();
  Serial.begin(9600);
  sbi(TWSR, TWPS0);  //reduction de la vitesse de transmission sur le
  cbi(TWSR, TWPS1);  //bus I2C (vitesse de 489Hz)
  TWBR=255;
   Serial.println("===============");
}

void loop() {

  
  ecritureCodeEEPROM(0x57, 0x00, valeurCodeEEPROM);
  delay(200); //Le delai de 200ms permet a l' 
  lectureEEPROM(0x57, 0x00, valeurEEPROM);
  Serial.println("===============");
  Serial.println(valeurEEPROM);
 
  
  delay(5000);

}
