#include "carte.h"
#include <Wire.h>
#include <arduino.h>
#include "affiche.h"

int presenceCarte (){ //fonction permettant de détecter ou non un carte
  short carteIn;
  Wire.requestFrom(0x21, 1); 
  while(Wire.available()){
    carteIn=Wire.read();
    carteIn=(carteIn & 0x01); //on crée un mask pour 
                //récupérer le bit qui nous intéraisse
  }

  /*on lit a l'adresse 0x21 qui correspond a l'adresse
  du PCF8574. Ceci nous permettra de requpérer la trame
  qui nous indiquera si un carte a été detecter*/
  
  return carteIn; //on renvoie la valeur qui correspond 
            //a la présence (0) ou non (1) de carte. 
}

char* lectureCarte(char* valeurPuce){ //fonction permettant de lire le code de la carte
  int i=0;
  if (presenceCarte()==0){ // on exécute le programe que si la carte est detecter

      accesCarteOn(); //on autosrise la lecture de la carte
           
      Wire.beginTransmission(0x50); // ici on indique que l'on veux lire 
      Wire.write(0x00); // les valeurs a partire de l'adresse 0x00
      Wire.endTransmission();
        
      Wire.requestFrom(0x50, 4); // on lit les 4 premier octet
      while (Wire.available()){
        valeurPuce[i]=Wire.read(); //on enregistres chaque valeur a une  
        i++;                       //adresse la première étant valeurPuce[0]
      }

      accesCarteOff(); //on ferme l'acces a la carte
  }
  return valeurPuce; 
}

int validationCarte (){
  int validation=0;
  char adresseRef[4]={'3','4','5','6'}; //code de référence
  char valeurPuce[4]={'0','0','0','0'}; //le code de base qui sera rédiger par
  //l'utilisateur est initialiser a 0000 pour éviter que le bon code reste en mémoire
  char* adresseValeur;
  if (presenceCarte()==0){ // on exécute la suite du programme que si la carte est detecter
    adresseValeur=lectureCarte(valeurPuce);

/*On passe a la variable adresseValeur les valeur que retournera la fonction lectureCarte avec en  
 * paramétre le code de base 0000 (valeurPuce)*/
    
    for(int i=0;i<4;i++){
        if(adresseValeur[i]==adresseRef[i]){ //on compare les valeur entre elle
          validation=1; //si elle son bonne on continue de comparer 
        }
        else{
          validation=0;    //lorsque q'une comparaison échoue
          setEclairage(0x21, 1); // le prgramme renvoie directement 0 (FAUX).
          envoyerMessage(0x3B, MESSAGE7, LIGNE1);
          envoyerMessage(0x3B, MESSAGE8, LIGNE2);
          return validation;        
        }
    }
  }
  return validation; //si tout les caractére se corresponde on renvoie 1 (BON)
}

void accesCarteOn (void){
                  
      Wire.beginTransmission(0x21); 
      Wire.write(0x06);
      Wire.endTransmission();

      /*
       * ici on écrie sur le pic PCF8574 pour nous permettre 
       * d'autorise l'écriture ou la lecture sur la carte a puce
       */
  
}

void accesCarteOff (void){

      Wire.beginTransmission(0x21);
      Wire.write(0x05);
      Wire.endTransmission();

      /*
       * ici on écrie sur le pic PCF8574 pour nous permettre 
       * de fermer l'écriture ou la lecture sur la carte a puce
       */
      
  
}
