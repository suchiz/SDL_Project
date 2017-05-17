#ifndef MENU_1
#define MENU_1

#include "../fonctions.h"

void default_menu1 (SDL_Surface *ecran);
void hover_menu1 (SDL_Surface *ecran, SDL_Event event);
void button_menu1 (int *menu, bool *continuer,int clicX, int clicY);

#endif