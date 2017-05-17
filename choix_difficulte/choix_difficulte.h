#ifndef CHOIX_DIFFICULTE
#define CHOIX_DIFFICULTE

#include "fonctions.h"

void default_choix_difficulte (SDL_Surface *ecran);
void hover_choix_difficulte (SDL_Surface *ecran, SDL_Event event);
void button_choix_difficulte (int *menu,int clicX, int clicY,int* contre_IA);

#endif
