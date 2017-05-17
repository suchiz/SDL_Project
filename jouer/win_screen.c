#include "win_screen.h"

#include "areusure.h"

void default_winner (SDL_Surface *ecran, int qui_commence,int i)
{
	SDL_Surface* text_Winner;
	SDL_Rect posWinner;
	int winner;
	char string[MAX_STRING];
	
	text_Winner = TTF_RenderText_Blended(fontMenu,"init",fontBlack);
	
	posWinner.x=85;
	posWinner.y=130;
	
	if (qui_commence)
		if (i % 2)
			winner =1;
		else 
			winner = 0;
	else
		if (i % 2)
			winner = 0;
		else 
			winner = 1;

	sprintf(string, "Le joueur %d a gagne la partie",winner+1);
	
	SDL_BlitSurface(background2,NULL,ecran,&posBackground);
	hover(ecran,text_Winner,fontSousMenu,string,fontBlack,posWinner);
	hover(ecran,retour,fontSousMenu,"Retour",fontBlack,posRetour3);
	
	
	SDL_FreeSurface(text_Winner);
}

void button_winner (int *menu, int clicX, int clicY, int i)
{
	if(clicX >=670 && clicX<=782 && clicY >= 555 && clicY <=583)
		*menu=1;
}

void hover_winner (SDL_Surface *ecran, SDL_Event event)
{
	
	if(event.button.x >=670 && event.button.x<=782 && event.button.y >= 555 && event.button.y <=583)	
		hover(ecran,retour,fontSousMenu,"Retour",fontOrange,posRetour3);
	else
		hover(ecran,retour,fontSousMenu,"Retour",fontBlack,posRetour3);
}





