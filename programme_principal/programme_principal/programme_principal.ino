/*  DIRECTIVES PREPROCESSEUR
    Inclusion des différentes bbliotheques necessaires au bon fonctionnement du Programme */
#include <Wire.h>       // bibliotheque permettant la gestion des commandes de transmission en i2c.
#include "i2c.h"        // bibliotheque permettant de gerer la vitesse de transmission de la connexion i2c.
#include "Boucle.h"     // bibliotheque contenant les fonction de lecture des boucles Amont et Aval
#include "barriere.h"   // bibliotheque contenant les fonctions d'ouverture et de fermeture de la barriere.
#include "digicode.h"   // bibliotheque contenant les fonctions permettants a l'utilisateur de saisir son code
#include "carte.h"      // bibliotheque contenant les fonctions permettant de detecter la presence de la carte, y acceder, la lire, et tester si elle est valide.
#include "affiche.h"    // bibliotheque contenant les fonctions permettant de controler l'afficheur LCD.
#include "affiche_terminal.h" // bibliotheque contenant les fonctions permettant de controler l'affiche sur le moniteur du gardien
#include "EEPROM.h" // bibliotheque contenant les fonctions permettant de sauvegarder des donner


void setup() {
  Wire.begin();
  initI2C(60);
  Serial3.begin(9600);
  initAfficheur(0x3B);
  formeTerminal();
}

void loop() {//début du programme
    int tempo=0, testTempo=1; //initialisation des variable de tempo
    int nombreVoiture; //initialisation du nombre de voiture
    int nombrePlace; //initialisation de la variable nombre de place

    
    static int drapeau=0; //initialisation d'un drapeau

    nombreVoiture=lectureEEPROM(0x57, 0xFC, nombreVoiture);
   
   if (testBoucleAmont()==0 && testBoucleAval()==1){ //selection d'entrée
    if (drapeau==0){
          setEclairage(0x21, 1);    //on utilise un drapeau pour n'afficher q'une seul fois   
          envoyerMessage(0x3B, MESSAGE1, LIGNE1);//le message de bienvenue par passage sur la boucle.
          envoyerMessage(0x3B, MESSAGE2, LIGNE2);//Sans cela le message se réécrie consatment est se met donc a clignoter.
          drapeau=1;      
    }
    if (validation()==1){
          ouvrir(); //appel de la fonction d'ouverture de la barriere
          while (testBoucleAmont()==0 && testBoucleAval()==1 && testTempo==1){ // test de position sur la boucle aval
              tempo++; //depart de la tempo.
              delay(3); // si la voiture rest plus de 30 sec 
              if(tempo==500){ // testTempo=0 donc le test d'ouverture n'est plus valid 
                  testTempo=0; // la barriere se ferme
                  setEclairage(0x21, 1);
                  envoyerMessage(0x3B, MESSAGE8, LIGNE1);
              }
          }    
          if (testBoucleAval()==0 || testBoucleAmont()==1){  //si la voiture avance 
                  if(testBoucleAval()==0 || testBoucleAmont()==0){  //on empeche la barriere de se refermer 
                      while(testBoucleAval()==0 || testBoucleAmont()==0); //temps qu'elle na pas quite les boucle
                      nombreVoiture++; // on incrémente le nombre de voiture sur le parking si la voiture rentre
                      ecritureEEPROM(0x57, 0xFC, nombreVoiture); //on écrie sur l'eeprom de la barrière le nombre de voiture
                      delay(200); //le delay laisse le temps a l'eeprom de sauvegarder la valeur
                      nombreVoiture=lectureEEPROM(0x57, 0xFC, nombreVoiture); //on récupère la valeur stocker dans l'eeprom
                      nombrePlace=200-nombreVoiture;                                      
                      afficheTerminal(nombreVoiture,nombrePlace); //on affiche sur le moniteur du gardien 
                      vehiculeEntre();                      
                  }
          }
      }        
        fermer(); //appel de la fonction de fermeture de la barriere
    }//fin du sous programme    
   else{
        drapeau=0;
        effacerAfficheur(0x3B); 
        setEclairage(0x21, 0);
   }



   

   if (testBoucleAval()==0 && testBoucleAmont()==1){//selection de sortie
      ouvrir();//ouverture de la barriére
      setEclairage(0x21, 1);
      envoyerMessage(0x3B, MESSAGE5, LIGNE1);
      envoyerMessage(0x3B, MESSAGE6, LIGNE2);
      while (testBoucleAval()==0 && testBoucleAmont()==1); //si la voiture avance 
      if(testBoucleAval()==0 || testBoucleAmont()==0){    //on empeche la barriere de se refermer
        
          while(testBoucleAmont()==0 || testBoucleAval()==0);//temps qu'elle na pas quite les boucle
          nombreVoiture--;
          ecritureEEPROM(0x57, 0xFC, nombreVoiture);// on incrémente le nombre de voiture sur le parking si la voiture rentre
          nombrePlace++;
          delay(200);;
          nombreVoiture=lectureEEPROM(0x57, 0xFC, nombreVoiture);                                        
          afficheTerminal(nombreVoiture,nombrePlace);
          nombrePlace=200-nombreVoiture; 
          vehiculeSorti();        
      } 
      fermer();
      effacerAfficheur(0x3B);
      setEclairage(0x21, 0);
   }//fin de la selection de sortie  
}
