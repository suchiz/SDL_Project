#ifndef CHARGER
#define CHARGER

#include "../global.h"
#include "../fonctions.h"
#include <string.h>

void default_charger(SDL_Surface *ecran);
void hover_charger (SDL_Surface *ecran, SDL_Event event);
void button_charger (int *menu, int clicX,int clicY,int *indice, int *afficher_rolldice, int *afficher_resultat, int * afficher_valider);
void charger();
#endif