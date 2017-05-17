#ifndef CHOIX_ADVERSAIRE
#define CHOIX_ADVERSAIRE

#include "fonctions.h"

void default_choix_adversaire (SDL_Surface *ecran);
void hover_choix_adversaire (SDL_Surface *ecran, SDL_Event event);
void button_choix_adversaire (int *menu, bool *continuer,int clicX, int clicY, int *i, int *p_roll, int *p_res, int *p_val, int *b_ret, int *a_IA,int *q_c);

#endif
