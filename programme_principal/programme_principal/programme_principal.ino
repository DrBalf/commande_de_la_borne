#include <Wire.h>
#include "i2c.h"
#include "Arduino.h"
#include "fonction.h"

void setup() {
  Wire.begin();
  initI2C(122);
  Serial.begin(9600);
}

void loop() {//début du programme
  //initialization nombre de voiture
    int tempo=0, testTempo=1;
    static int nombreVoiture=0;
    static int nombrePlace=200;

   if (testBoucleAmont()==0 && testBoucleAval()==1){ //selection d'entrée
          ouvrir(); 
          while (testBoucleAmont()==0 && testBoucleAval()==1 && testTempo==1){
              tempo++;
              delay(30);
              if(tempo==1000){
                  testTempo=0;
              }
          }
          if (testBoucleAval()==0 || testBoucleAmont()==1){
                  if(testBoucleAval()==0 || testBoucleAmont()==0){
                      while(testBoucleAval()==0 || testBoucleAmont()==0);
                      nombreVoiture++;
                      nombrePlace--;
                  }  
          }
        fermer();  
     }//fin du sous programme    
     
    
      

 
   if (testBoucleAval()==0 && testBoucleAmont()==1){//selection de sortie
    
      ouvrir();//début du sous programme d'ouverture de la barriére pour véhicule sortant 
      while (testBoucleAval()==0 && testBoucleAmont()==1);
      if(testBoucleAval()==0 || testBoucleAmont()==0){
        
          while(testBoucleAmont()==0 || testBoucleAval()==0);
          nombreVoiture--;
          nombrePlace++;
      } 
      fermer();//fin du sous programme 
   }//fin de la selection de sortie   
}
