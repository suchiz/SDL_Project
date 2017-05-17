#include "areusure.h"

void default_quitter (SDL_Surface *ecran)
{
	SDL_Surface* text_Rusure;
	SDL_Rect posRUsure,posPhrase2,posOui,posNon;
	
	text_Rusure = TTF_RenderText_Blended(fontMenu,"init",fontBlack);
	
	posRUsure.x=85;
	posRUsure.y=130;
	posPhrase2.x=250;
	posPhrase2.y=180;
	posOui.x=235;
	posOui.y=275;
	posNon.x=465;
	posNon.y=275;
	
	
	SDL_BlitSurface(background2,NULL,ecran,&posBackground);
	hover(ecran,text_Rusure,fontSousMenu,"Voulez-vous sauvegarder votre partie",fontBlack,posRUsure);
	hover(ecran,text_Rusure,fontSousMenu,"avant de quitter ?",fontBlack,posPhrase2);
	hover(ecran,text_Rusure,fontSousMenu,"oui",fontBlack,posOui);
	hover(ecran,text_Rusure,fontSousMenu,"non",fontBlack,posNon);
	hover(ecran,retour,fontSousMenu,"Retour",fontBlack,posRetour3);
	
	
	SDL_FreeSurface(text_Rusure);
}

void button_quitter (int *menu, bool *continuer, int clicX, int clicY, int i)
{
	if(clicX >=235 && clicX<=281 && clicY >= 275 && clicY <=302)
	{
		save(i);
		*continuer=0;
	}else if(clicX >=465 && clicX<=522 && clicY >= 275 && clicY <=302)
		*continuer=0;
	else if(clicX >=670 && clicX<=782 && clicY >= 555 && clicY <=583)
		*menu=4;
}

void button_quitter_2 (int *menu, int clicX, int clicY, int i)
{
	if(clicX >=235 && clicX<=281 && clicY >= 275 && clicY <=302)
	{
		save(i);
		*menu=2;
	}else if(clicX >=465 && clicX<=522 && clicY >= 275 && clicY <=302)
		*menu=2;
	else if(clicX >=670 && clicX<=782 && clicY >= 555 && clicY <=583)
		*menu=4;
}


void hover_quitter (SDL_Surface *ecran, SDL_Event event)
{
	
	SDL_Rect posOui,posNon;
	
	posOui.x=235;
	posOui.y=275;
	posNon.x=465;
	posNon.y=275;
	
	if(event.button.x >=235 && event.button.x<=281 && event.button.y >= 275 && event.button.y <=302)
		hover(ecran,retour,fontSousMenu,"oui",fontOrange,posOui);
	else if(event.button.x >=465 && event.button.x<=522 && event.button.y >= 275 && event.button.y <=302)
		hover(ecran,retour,fontSousMenu,"non",fontOrange,posNon);
	else if(event.button.x >=670 && event.button.x<=782 && event.button.y >= 555 && event.button.y <=583)	
		hover(ecran,retour,fontSousMenu,"Retour",fontOrange,posRetour3);
	else
	{								
		hover(ecran,retour,fontSousMenu,"oui",fontBlack,posOui);
		hover(ecran,retour,fontSousMenu,"non",fontBlack,posNon);
		hover(ecran,retour,fontSousMenu,"Retour",fontBlack,posRetour3);
	}
}





