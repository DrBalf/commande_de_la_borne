#include <terminal.h>
#include "Arduino.h" 


void afficheTerminal(int nombreVoiture, int nombrePlace){
    
    
    terminalCouleur(31, 40); //terminalCouleur permet de changer les couleurs du terminal 
                              //l'écriture et le fond. terminalCouleur(couleurEcriture, couleurFond). 

    terminalPosition(10,58);  //terminalPosition permet de positionner le curseur avec en premier 
                              //paramètre la ligne (10) puis la colonne(58).
    Serial3.println(nombreVoiture, DEC);
    
    terminalCouleur(31, 40);
    terminalPosition(12,55);
    Serial3.println(nombrePlace, DEC);
     
}

void formeTerminal (void){
  
    terminalCouleur(31, 40);
    terminalPosition(8,30);
    Serial3.print("***********************************");
    
    terminalCouleur(31, 40);
    terminalPosition(9,30);
    Serial3.print("*                                 *");
    
    terminalCouleur(31, 40);
    terminalPosition(10,30);
    Serial3.print("*      Nombre de voiture : ");
    terminalCouleur(31, 40);
    terminalPosition(10,59);
    Serial3.print("     *");
    
    terminalCouleur(31, 40);
    terminalPosition(11,30);
    Serial3.print("*                                 *");
    
    terminalCouleur(31, 40);
    terminalPosition(12,30);
    Serial3.print("*      Nombre de place : ");
    terminalCouleur(31, 40);
    terminalPosition(12,59);
    Serial3.print("     *");
    
    terminalCouleur(31, 40);
    terminalPosition(13,30);
    Serial3.print("*                                 *");

    terminalCouleur(31, 40);
    terminalPosition(14,30);
    Serial3.print("*  Le dernier vehicule est ");
    terminalCouleur(31, 40);
    terminalPosition(14,64);
    Serial3.print("*");

    terminalCouleur(31, 40);
    terminalPosition(15,30);
    Serial3.print("*                                 *");
   
    terminalCouleur(31, 40);
    terminalPosition(16,30);
    Serial3.print("***********************************");
    
}

void vehiculeEntre (void){
  
   terminalCouleur(31, 40);
   terminalPosition(14,57);
   Serial3.println("Entre");
   
}

void vehiculeSorti (void){
  
   terminalCouleur(31, 40);
   terminalPosition(14,57);
   Serial3.println("Sorti");
   
}


