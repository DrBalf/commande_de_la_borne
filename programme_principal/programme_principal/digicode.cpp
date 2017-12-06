#include "digicode.h"
#include <Wire.h>
#include <arduino.h>
#include "affiche.h"
#define PCF8574CLAVIER 0x22
#define PCF8582EEPROM 0x57
#define PCF2119LCD 0x3B


int lectureLigne(){
  short lectureL;
  short ligne;
  Wire.beginTransmission(PCF8574CLAVIER);      //On initialise la communication avec l'adresse du PCF8574
  Wire.write(0xF0);                     // On mets tous les bits correspondant aux lignes a 1, et le reste a 0.
  Wire.endTransmission();
  Wire.requestFrom(PCF8574CLAVIER, 1);         // Preparer lecture de 1 octet a l'adresse 0x22.
  while(Wire.available()){
    lectureL = Wire.read();             // On affecte la valeur lue a lectureL

            /* En fonction de la valeur de "lectureL", on peut en deduire quel bit est passe a 0,
            et on affecte a "ligne" la valeur correspondant a la ligne
            sur laquelle se trouve la touche appuyee */

     switch(lectureL){
       case 0xE0:
       ligne=0;
      break;
       case 0xD0:
       ligne=1;
      break;
       case 0xB0:
       ligne=2;
      break;
       case 0x70:
       ligne=3;
      break;
    }
  }
  return ligne;         // retourne la ligne en question.
}

int lectureColonne(){
  short lectureC;
  short colonne;
  Wire.beginTransmission(PCF8574CLAVIER);      //On initialise la communication avec l'adresse du PCF8574
  Wire.write(0x0F);                     // On mets tous les bits correspondant aux colonnes a 1, et le reste a 0.
  Wire.endTransmission();
  Wire.requestFrom(PCF8574CLAVIER, 1);         // Preparer lecture de 1 octet a l'adresse 0x22.
  while(Wire.available()){
    lectureC = Wire.read();             // On affecte la valeur lue a lectureL

        /* En fonction de la valeur de "lectureC", on peut en deduire quel bit est passe a 0,
            et on affecte a "colonne" la valeur correspondant a la colonne
            sur laquelle se trouve la touche appuyee */

    switch(lectureC){
       case 0xE:
       colonne=0;
      break;
       case 0xD:
       colonne=1;
      break;
       case 0xB:
       colonne=2;
      break;
       case 0x7:
       colonne=3;
      break;
    }
  }
  return colonne;           // retourne la colonne en question.
}

char traductionClavier(int ligne, int colonne){

        /* Initialisation d'un tableau a deux dimension, contenant les caracteres inscrit sur le clavier
                - le 'G' represente le bouton d'appel du gardien.
                - les 'r' representent les liaisons non-utilisees */
char clavier[4][4] = {{'1','2','3','r'},{'4','5','6','r'},{'7','8','9','G'},{'*','0','#','r'}};

        /* Declaration d'un caractere apppele "caractere" grace au tableau precedent,
            Et affectation au caractere correspondant a la ligne
            et a la colonne passees en parametre plus tot. */
  char caractere = clavier[colonne][ligne];

  return caractere;         // retourne le caractere saisi.
}
int validationCode(){
  int validation=0;
  char* code;               // déclaration d'un pointeur sur caractere, qui contiendra le code saisi par l'utilisateur.
        /* Initialisation d'un pointeur sur caracteres qui contient le code valide 
            a comparer avec celui saisi par l'utilisateur */
  char codeRef[4]={'1','2','3','4'};    

        /*  Si une touche est appuyee sur le clavier, on appelle la fonction "saisieCode()" 
         *   qui permettra de stocker dans "code" les caracteres saisis par l'utilisateur */
  if (pushButon()==0){
    code=saisieCode();
        /*  On compare un a un les caracteres stockes dans "code"
              aux caracteres stockes dans "codeRef" 
              s'ils correspondent tous, on affecte 1 a "validation", 
                  on affiche un message de succes puis on retourne "validation",
              sinon, des qu'un caractere ne corresponds pas, 
                  on affecte 0 a "validation", on affiche un message d'erreur,
                  puis on retourne "validation."*/
    for(int i=0;i<=3;i++){
      if(code[i]==codeRef[i]){
        validation=1;
      }
      else{
        validation=0;
        setEclairage(0x21, 1);
        envoyerMessage(0x3B, MESSAGE7, LIGNE1);
        envoyerMessage(0x3B, MESSAGE8, LIGNE2);
        return validation;
      }  
    }
  }
  return validation;
}

char* saisieCode(){
  char code[4]={'0','0','0','0'};   // on initialise un tableau de 4 caractere a 0.
  char* ptrCode;                    // On declare un pointeur sur caractere
  ptrCode=code;                     // On l'affecte a "code".

  for(int i=0;i<=3;i++){            // Boucle permettant de saisir 4 chiffres.

    while(pushButon()==1);          // On attends tant que l'on a pas appuy� sur une touche.
    char colonne = lectureColonne();        // On affecte a "colonne" la valeur renvoy�e par la fonction lectureColonne().
    char ligne = lectureLigne();            // On affecte a "ligne" la valeur renvoy�e par la fonction lectureLigne().

        /*  On affecte au tableau de caractere l'indice donn�,
            le caractere retourn� par la fonction traductionPCF8574CLAVIER(). */
    ptrCode[i]=traductionClavier(ligne,colonne);

    delay(20);
    while(pushButon()==0);          // On attends tant que l'on appuie toujours sur la touche.
  }
  return ptrCode;                   // On retourne les 4 caracteres composant le code a 4 chiffres
}

int pushButon(){
  short lecture;        // declaration d'une variable "lecture"
  short toucheAppuyee=1;       // Initialisation a 1 de la variable "toucheAppuyer".

        /* On commence la communication avec le clavier
            puis on ecrit 0xF0 a son adresse */

  Wire.beginTransmission(PCF8574CLAVIER);
  Wire.write(0xF0);
  Wire.endTransmission();

        /* Lecture de la meme adresse et affectation a la variable "lecture".
            affectation de "toucheAppuyee" a 0 lorsque cette valeur change. */

    Wire.requestFrom(PCF8574CLAVIER, 1);
    while(Wire.available()){
      lecture=Wire.read();
    }
    if(lecture!=0xF0){
     toucheAppuyee=0;
    }
  return toucheAppuyee; // retourne "touche".
}

