#ifndef AREUSURE
#define AREUSURE

#include "../fonctions.h"
#include "../global.h"



void default_quitter (SDL_Surface *ecran);
void button_quitter (int *menu, bool *continuer, int clicX, int clicY, int i);
void button_quitter_2 (int *menu, int clicX, int clicY, int i);
void hover_quitter (SDL_Surface *ecran, SDL_Event event);

#endif