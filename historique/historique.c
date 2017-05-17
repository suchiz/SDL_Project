#include "historique.h"

void default_historique (SDL_Surface *ecran, int i)
{
	int j,k;
	char hist[MAX_STRING];
	
	posStringHist.y = 50;
	SDL_BlitSurface(background2,NULL,ecran,&posBackground);
	SDL_BlitSurface(retour,NULL,ecran,&posRetour3);
	if (i>11)
		k=i-11;
	else
		k=0;
	for(j=k;j<i;j++){
		sprintf(hist,"Le joueur %d a joue en  (%c,%d)  au tour %d.",plateau[j].player+1,plateau[j].coordinates.colonne+65,plateau[j].coordinates.ligne+1,j+1);
		stringHist=TTF_RenderText_Blended(fontSousMenu2,hist,fontBlack);
		SDL_BlitSurface(stringHist,NULL,ecran,&posStringHist);
		posStringHist.y+=50;
	}
}

void button_historique (int *menu, int clicX, int clicY)
{
	if(clicX >=670 && clicX<=782 && clicY >= 555 && clicY <=583)
		*menu=4;
}

void hover_historique (SDL_Surface *ecran, SDL_Event event)
{
	if(event.button.x >=670 && event.button.x<=782 && event.button.y >= 555 && event.button.y <=583)	
		hover(ecran,retour,fontSousMenu,"Retour",fontOrange,posRetour3);
	else
		hover(ecran,retour,fontSousMenu,"Retour",fontBlack,posRetour3);
}