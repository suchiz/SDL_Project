#include "../fonctions.h"
#include "../global.h"


void default_choix_difficulte (SDL_Surface *ecran)
{
	SDL_BlitSurface(background,NULL,ecran,&posBackground);
	SDL_BlitSurface(difficulte,NULL,ecran,&posDifficulte);
	SDL_BlitSurface(ia1,NULL,ecran,&posIA1);
	SDL_BlitSurface(ia2,NULL,ecran,&posIA2);
	retour = TTF_RenderText_Blended(fontMenu,"Retour",fontBlack);
	SDL_BlitSurface(retour,NULL,ecran,&posRetour);
}
	
void hover_choix_difficulte (SDL_Surface *ecran, SDL_Event event)
{
	if(event.button.x >=329 && event.button.x<=477 && event.button.y >= 191 && event.button.y <=231)
		hover(ecran,ia1,fontMenu,"Facile",fontOrange,posIA1);
	else if(event.button.x >=244 && event.button.x<=588 && event.button.y >= 291 && event.button.y <=333)	
		hover(ecran,ia2,fontMenu,"Intermediaire",fontOrange,posIA2);
	else if(event.button.x >=313 && event.button.x<=496 && event.button.y >= 391 && event.button.y <=441)	
		hover(ecran,retour,fontMenu,"Retour",fontOrange,posRetour);
	else
	{	
		hover(ecran,ia1,fontMenu,"Facile",fontBlack,posIA1);
		hover(ecran,ia2,fontMenu,"Intermediaire",fontBlack,posIA2);
		hover(ecran,retour,fontMenu,"Retour",fontBlack,posRetour);
	}
}
void button_choix_difficulte (int *menu,int clicX, int clicY,int *contre_IA)
{
	if(clicX >=329 && clicX<=477 && clicY >= 191 && clicY <=231)
	{
		*menu = 4;
		contre_IA = 1;
	}
	else if(clicX >=244 && clicX<=588 && clicY >= 291 && clicY <=333)		
		*menu = 4;
	else if(clicX >=313 && clicX<=496 && clicY >= 391 && clicY <=441)
    		*menu = 2;
}


