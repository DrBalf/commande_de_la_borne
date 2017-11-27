#ifndef CARTE_H
#define CARTE_H

void initEEPROM(void);

int presenceCarte (void);

int validationCarte(void);

char* lectureCarte(char*);

void accesCarteOn(void);

void accesCarteOff(void);

#endif 
