#include "../fonctions.h"
#include "../global.h"


#ifndef ROLL_DICES
#define ROLL_DICES



int roll_dice();
void default_roll_dice (SDL_Surface *ecran);
void hover_roll_dice (SDL_Surface *ecran,  SDL_Event event);
void button_roll_dice (int clicX, int clicY,int *de1, int *de2, int *afficher_roll);
void default_roll_resultat(SDL_Surface *ecran,int de1,int de2);

void button_valider (int *afficher_valider,int clicX,int clicY);
void default_valider(SDL_Surface *ecran,int de1, int de2);
void hover_valider(SDL_Surface *ecran,  SDL_Event event);


#endif
