#ifndef GLOBALS_H
#define GLOBALS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
 
#include <SDL/SDL.h>
#include <SDL/SDL_keysym.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include "fonctions.h"

#define WINHI 600 // window height
#define WINWI 800 // window width
#define MAX_STRING 100
#define MAX_HEX 121
#define MAX_CHARGER


extern SDL_Surface *ecran, *bienvenue, *texte_Jouer, *texte_Charger, *texte_Quitter,*background,
    		*ia, *ia1, *ia2, *human, *difficulte, *adversaire, *retour, *background2, *names,
		*historique, *sauvegarder, *undo, *valider, *stringHist, *board, *joueur1, *joueur2;
		
extern SDL_Surface *pionRouge;
extern SDL_Surface *pionBleu;
extern SDL_Rect posBienvenue, posTexte_Jouer, posTexte_Charger, posTexte_Quitter,posRetour,posBoard,
    	     posHuman, posIA, posIA1, posIA2, posDifficulte, posAdversaire, posRetour2, posBackground,
	     posSauvegarder, posUndo, posHistorique, posQuitter2, posValider, posRetour3, posStringHist, posjoueur1, posjoueur2;

extern TTF_Font *fontMenu;
extern TTF_Font *fontSousMenu;
extern TTF_Font *fontSousMenu2;

extern SDL_Color fontBlack;
extern SDL_Color fontOrange;
extern SDL_Color fontRed;
extern SDL_Color fontBlue;

extern hex plateau[MAX_HEX];
extern char tab_charger[MAX_STRING][MAX_STRING];
extern char ligne[MAX_STRING];
extern int nb_charger;
extern FILE *f_in;

#endif
