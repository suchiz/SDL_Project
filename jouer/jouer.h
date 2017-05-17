#ifndef JOUER_
#define JOUER_

#include "../fonctions.h"

void default_jouer (SDL_Surface *ecran,int i,int qui_commence, int *menu);
void hover_jouer (SDL_Surface *ecran, SDL_Event event);
void button_jouer (int *menu, bool *continuer,int clicX, int clicY ,int *i, int *nb_tour, int *retour_bouton, int qui_commence,int contre_IA);

#endif
