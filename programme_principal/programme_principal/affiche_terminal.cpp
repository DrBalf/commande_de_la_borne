#include <terminal.h>
#include "Arduino.h" 


void afficheTerminal(int nombreVoiture, int nombrePlace){
  
    terminalCouleur(31, 40);
    terminalPosition(10,58);
    Serial3.println(nombreVoiture, DEC);
    
    terminalCouleur(31, 40);
    terminalPosition(12,55);
    Serial3.println(nombrePlace, DEC);

    if (nombreVoiture==nombreVoiture+1){
        terminalCouleur(31, 40);
        terminalPosition(12,57);
        Serial3.println("Entre");
    }
    if (nombreVoiture==nombreVoiture-1){
        terminalCouleur(31, 40);
        terminalPosition(12,57);
        Serial3.println("Sorti");
    }
     
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
    terminalPosition(14,59);
    Serial3.print("  *");

    terminalCouleur(31, 40);
    terminalPosition(15,30);
    Serial3.print("*                                 *");
   
    terminalCouleur(31, 40);
    terminalPosition(16,30);
    Serial3.print("***********************************");
    
}

