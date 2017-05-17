#ifndef WINSCREEN
#define WINSCREEN

#include "../fonctions.h"
#include "../global.h"


void button_winner (int *menu, int clicX, int clicY, int i);
void hover_winner (SDL_Surface *ecran, SDL_Event event);
void default_winner (SDL_Surface *ecran, int qui_commence,int i);

#endif