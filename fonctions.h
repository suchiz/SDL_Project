#ifndef FONCTION_POUR_MAIN
#define FONCTION_POUR_MAIN

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
 

#include <SDL/SDL.h>
#include <SDL/SDL_keysym.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#define MAX_VOISIN 6

typedef struct coordonnee_s
{
	int ligne;
	int colonne;
}coordonnee;

typedef struct hex_s 
{
	SDL_Rect posPions;
	int player;
	coordonnee coordinates;
	int voisins[MAX_VOISIN];
	int bord;
}hex;


typedef struct dimension_s
{
    int h, w;
}Dimensions;

void hover (SDL_Surface *ecran, SDL_Surface *texte, TTF_Font *font, char string[], SDL_Color color, SDL_Rect pos);
void extern_init();
void maj_voisins(int test);
int detection_gagnant(int test);
int parcours_voisins(int j, int test, int bord_player, int venu,int tab_visite[],int indice);
int coup_valide(int test, int t, int c);


#endif