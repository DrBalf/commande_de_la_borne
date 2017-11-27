#include <Wire.h>
#include "i2c.h"
#include "Boucle.h"
#include "barriere.h"
#include "digicode.h"
#include "carte.h"

void setup() {
  Wire.begin();
  initI2C(122);
  Serial.begin(9600);
}

void loop() {//début du programme
    int tempo=0, testTempo=1; //initialisation des variable de tempo
    static int nombreVoiture=0; //initialisation du nombre de voiture
    static int nombrePlace=200; //initialisation du nombre de place

   
   if (testBoucleAmont()==0 && testBoucleAval()==1){ //selection d'entrée
    if(validationCarte()==1 || validationCode()==1){
          ouvrir(); //appel de la fonction d'ouverture de la barriere
          while (testBoucleAmont()==0 && testBoucleAval()==1 && testTempo==1){ // test de position sur la boucle aval
              tempo++; //depart de la tempo.
              delay(3); // si la voiture rest plus de 30 sec 
              if(tempo==500){ // testTempo=0 donc le test d'ouverture n'est plus valid 
                  testTempo=0; // la barriere se ferme
              }
          }    
          if (testBoucleAval()==0 || testBoucleAmont()==1){  //si la voiture avance 
                  if(testBoucleAval()==0 || testBoucleAmont()==0){  //on empeche la barriere de se refermer 
                      while(testBoucleAval()==0 || testBoucleAmont()==0); //temps qu'elle na pas quite les boucle
                      nombreVoiture++; // on incrémente le nombre de voiture sur le parking si la voiture rentre
                      nombrePlace--;
                  }
          }
      }
        fermer(); //appel de la fonction de fermeture de la barriere  
    }//fin du sous programme    
     
    
      

 
   if (testBoucleAval()==0 && testBoucleAmont()==1){//selection de sortie
    
      ouvrir();//ouverture de la barriére
      while (testBoucleAval()==0 && testBoucleAmont()==1); //si la voiture avance 
      if(testBoucleAval()==0 || testBoucleAmont()==0){    //on empeche la barriere de se refermer
        
          while(testBoucleAmont()==0 || testBoucleAval()==0);//temps qu'elle na pas quite les boucle
          nombreVoiture--;
          nombrePlace++;
      } 
      fermer();
   }//fin de la selection de sortie   
}
