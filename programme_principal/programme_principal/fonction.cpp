#include <Wire.h>
#include "Arduino.h"
#include "fonction.h"


int testBoucleAmont (){
  short boucle; //déclaration d'un entier cour
  Wire.requestFrom(0x20,1); //on fait un requette de lesclave vere le maitre 
                            //a l'adresse 0X20 de 1 octet a lui envoyer
  while(Wire.available()){
      boucle = Wire.read(); //on lie la boucle amont que l'on intégre a la variable boucle 
      }
  boucle=(boucle & 0x20)>>5; //on crée un mask pour selectionner le bit de detection de la boucle
                              //amont que l'on décale ensuite de 5 bit pour avoir une seul valeur 
  return boucle;            //on renvoie la valeur de la boucle don 1(rien sur la boucle) ou
                            //0 (voiture sur la boucle) 
}


int testBoucleAval (){
  short boucle;
  Wire.requestFrom(0x20,1);
  while(Wire.available()){
      boucle = Wire.read();
      }
  boucle=(boucle & 0x40)>>6; //on crée un mask pour selectionner le bit de detection de la boucle
                              //amont que l'on décale ensuite de 6 bit pour avoir une seul valeur 
  return boucle;
}

void ouvrir (){
  Wire.beginTransmission(0x20); //on demare la transmission sur l'adresse 0x20
  Wire.write(0xFD);           //on ecrit sur l'adresse 0x20 la valeur 0xFD qui 
                              //correspond a la valeur d'ouvertur de barriere 
  Wire.endTransmission();     //fin de transmission
}

void fermer (){
  Wire.beginTransmission(0x20);
  Wire.write(0xFE);         //on ecrit sur l'adresse 0x20 la valeur 0xFE qui 
                            //correspond a la valeur de fermeture de barriere 
  Wire.endTransmission();
}
