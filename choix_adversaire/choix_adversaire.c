#include "../fonctions.h"
#include "../global.h"

void default_choix_adversaire (SDL_Surface *ecran)
{
	SDL_BlitSurface(background,NULL,ecran,&posBackground);
	SDL_BlitSurface(adversaire,NULL,ecran,&posAdversaire);
	SDL_BlitSurface(human,NULL,ecran,&posHuman);
	SDL_BlitSurface(ia,NULL,ecran,&posIA);
	retour = TTF_RenderText_Blended(fontMenu,"Retour",fontBlack);
	SDL_BlitSurface(retour,NULL,ecran,&posRetour);		
}
	
void hover_choix_adversaire (SDL_Surface *ecran, SDL_Event event)
{
	if(event.button.x >=329 && event.button.x<=503 && event.button.y >= 191 && event.button.y <=234)
		hover(ecran,human,fontMenu,"Joueur",fontOrange,posHuman);
	else if(event.button.x >=284 && event.button.x<=562 && event.button.y >= 291 && event.button.y <=333)	
		hover(ecran,ia,fontMenu,"Ordinateur",fontOrange,posIA);
	else if(event.button.x >=313 && event.button.x<=496 && event.button.y >= 391 && event.button.y <=441)	
		hover(ecran,retour,fontMenu,"Retour",fontOrange,posRetour);
	else
	{				
		hover(ecran,human,fontMenu,"Joueur",fontBlack,posHuman);
		hover(ecran,ia,fontMenu,"Ordinateur",fontBlack,posIA);
		hover(ecran,retour,fontMenu,"Retour",fontBlack,posRetour);
	}
}

void button_choix_adversaire (int *menu, bool *continuer,int clicX, int clicY, int *i, int *p_roll, int *p_res, int *p_val, int *b_ret, int* a_IA, int *q_c)
{
	if(clicX >=329 && clicX<=503 && clicY >= 191 && clicY<=234)
	{
		*menu = 4;
		*i=0;
		*p_roll=0;
		*p_res=0;
		*p_val=0;
		*b_ret=0;
		*a_IA=0;
		*q_c=0;
	}else if(clicX >=284 && clicX<=562 && clicY >= 291 && clicY <=333)
	{		
		*menu = 3;
		*i=0;
		*p_roll=0;
		*p_res=0;
		*p_val=0;
		*b_ret=0;
		*a_IA=1;
		*q_c=0;
	}
	else if(clicX >=313 && clicX<=496 && clicY >= 391 && clicY <=441)
    		*menu = 1;
}
