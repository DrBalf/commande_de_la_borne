//fichier d'entete
#ifndef AFFICHE_H
#define AFFICHE_H

#include "Arduino.h"

#define LIGNE1 0x00
#define LIGNE2 0x40

#define MESSAGE1 "    Bonjour     "
#define MESSAGE2 "Entrez code SVP "
#define MESSAGE3 " Identite valide"
#define MESSAGE4 "   bienvenue    "
#define MESSAGE5 "   Au revoir    "
#define MESSAGE6 " et a bientot   "
#define MESSAGE7 " Identite errone"
#define MESSAGE8 "quittez la place"




void initAfficheur(int adress);
void effacerAfficheur (int adress);
void setEclairage(int adress,int valeur);

void activerAfficheur (int adress);
void desactiverAfficheur (int adress);

void envoyerCommande(int adress,int valeur);
void envoyerDonnee(int adress,int valeur);
void envoyerMessage(int adress,const char* maChaine,int ligne);
void blinkAfficheur(int adress,int nombre,unsigned long duree);
void shiftAfficheur(int adress, int valeur);

#endif
