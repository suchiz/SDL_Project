#include "../fonctions.h"
#include "../global.h"
#include "menu1.h"

void hover_menu1 (SDL_Surface *ecran, SDL_Event event)
{
	if(event.button.x >=posTexte_Jouer.x && event.button.x<=posTexte_Jouer.x+texte_Jouer->w && event.button.y >= posTexte_Jouer.y && event.button.y <=posTexte_Jouer.y+texte_Jouer->h)
		hover(ecran,texte_Jouer,fontMenu,"Jouer",fontOrange,posTexte_Jouer);
	else if(event.button.x >=284 && event.button.x<=562 && event.button.y >= 291 && event.button.y <=333)	
		hover(ecran,texte_Charger,fontMenu,"Charger",fontOrange,posTexte_Charger);
	else if(event.button.x >=313 && event.button.x<=496 && event.button.y >= 391 && event.button.y <=441)	
		hover(ecran,texte_Quitter,fontMenu,"Quitter",fontOrange,posTexte_Quitter);
	else
	{	
		hover(ecran,texte_Jouer,fontMenu,"Jouer",fontBlack,posTexte_Jouer);
		hover(ecran,texte_Charger,fontMenu,"Charger",fontBlack,posTexte_Charger);
		hover(ecran,texte_Quitter,fontMenu,"Quitter",fontBlack,posTexte_Quitter);
	}

}

void button_menu1 (int *menu, bool *continuer,int clicX, int clicY)
{
	
	
	if(clicX >=330 && clicX<=471 && clicY >= 191 && clicY<=231)
		*menu = 2;
	else if(clicX >=302 && clicX<=508 && clicY >= 291 && clicY <=346)
	{
		*menu = 6;
		charger();
	}
	else if(clicX >=313 && clicX<=496 && clicY >= 391 && clicY <=441)
    		*continuer=0;
}

void default_menu1 (SDL_Surface *ecran)
{
	SDL_BlitSurface(background,NULL,ecran,&posBackground);
	SDL_BlitSurface(bienvenue,NULL,ecran,&posBienvenue);
     	SDL_BlitSurface(texte_Jouer,NULL,ecran,&posTexte_Jouer);
 	SDL_BlitSurface(texte_Charger,NULL,ecran,&posTexte_Charger);
	texte_Quitter = TTF_RenderText_Blended(fontMenu,"Quitter",fontBlack);
     	SDL_BlitSurface(texte_Quitter,NULL,ecran,&posTexte_Quitter);
}