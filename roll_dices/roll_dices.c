#include "roll_dices.h"


int roll_dice()
{
	int n;
	n=rand()%6+1;
	return n;
}


void hover_roll_dice (SDL_Surface *ecran,  SDL_Event event)
{
	SDL_Surface *lancer;
	SDL_Rect poslancer;
	
	poslancer.x=220;
    	poslancer.y=260;
    
   	lancer= TTF_RenderText_Blended(fontMenu,"Lancer les des",fontRed);

	
	if(event.button.x >=poslancer.x && event.button.x<= poslancer.x + lancer->w && event.button.y >= poslancer.y && event.button.y <= poslancer.y+lancer->h)
		hover(ecran,lancer,fontMenu,"Lancer les des ",fontOrange,poslancer);
	else
		hover(ecran,lancer,fontMenu,"Lancer les des ",fontBlack,poslancer);
	
	
	SDL_FreeSurface(lancer);

}


void button_roll_dice (int clicX, int clicY,int *de1,int *de2, int *afficher_roll)
{
	
	if(clicX >=203 && clicX<=573 && clicY >= 261 && clicY <=303)
	{
		srand(time(NULL));
		*de1=roll_dice();
		srand(time(NULL)+20);
		*de2=roll_dice();
		*afficher_roll+=1;
	}
	
	
}

void default_roll_dice(SDL_Surface *ecran)
{
	SDL_Surface *lancer;
	SDL_Rect posde1,posde2,poslancer;
	
	lancer= TTF_RenderText_Blended(fontMenu,"Lancer les des",fontRed);
	SDL_BlitSurface(background,NULL,ecran,&posBackground);
	poslancer.x=220;
   	poslancer.y=260;
	hover(ecran,lancer,fontMenu,"Lancer les des ",fontBlack,poslancer);
	
	SDL_FreeSurface(lancer);
}

void default_roll_resultat(SDL_Surface *ecran,int de1,int de2)	
{
	
	SDL_Surface *tirage1,*tirage2,*face1,*face2,*face3,*face4,*face5,*face6;
	SDL_Rect posde1,posde2,posface1,posface2;
	
	face1=IMG_Load("Images/de1.png");
	face2=IMG_Load("Images/de2.png");
	face3=IMG_Load("Images/de3.png");
	face4=IMG_Load("Images/de4.png");
	face5=IMG_Load("Images/de5.png");
	face6=IMG_Load("Images/de6.png");
	
	
	posface1.x=520;
	posface1.y=130;
	
	posface2.x=520;
	posface2.y=357;
	
	posde1.x=200;
	posde1.y=200;
	
	posde2.x=200;
	posde2.y=400;
	
	tirage2= TTF_RenderText_Blended(fontSousMenu,"Le joueur 2 a Tire",fontBlue);
	tirage1= TTF_RenderText_Blended(fontSousMenu,"Le joueur 1 a Tire",fontRed);
	SDL_BlitSurface(background,NULL,ecran,&posBackground);
	SDL_BlitSurface(tirage1,NULL,ecran,&posde1);
	SDL_BlitSurface(tirage2,NULL,ecran,&posde2);
	default_valider(ecran,de1,de2);
	
	switch(de1)
	{
		case 1:
			SDL_BlitSurface(face1,NULL,ecran,&posface1);
			break;
		case 2:
			SDL_BlitSurface(face2,NULL,ecran,&posface1);
			break;
		case 3:
			SDL_BlitSurface(face3,NULL,ecran,&posface1);
			break;
		case 4:
			SDL_BlitSurface(face4,NULL,ecran,&posface1);
			break;
		case 5:
			SDL_BlitSurface(face5,NULL,ecran,&posface1);
			break;
		default:
			SDL_BlitSurface(face6,NULL,ecran,&posface1);
			break;
	}
		
	
	switch(de2)
	{
		case 1:
			SDL_BlitSurface(face1,NULL,ecran,&posface2);
			break;
		case 2:
			SDL_BlitSurface(face2,NULL,ecran,&posface2);
			break;
		case 3:
			SDL_BlitSurface(face3,NULL,ecran,&posface2);
			break;
		case 4:
			SDL_BlitSurface(face4,NULL,ecran,&posface2);
			break;
		case 5:
			SDL_BlitSurface(face5,NULL,ecran,&posface2);
			break;
		default:
			SDL_BlitSurface(face6,NULL,ecran,&posface2);
			break;
	}
	
        SDL_FreeSurface(tirage1);
        SDL_FreeSurface(tirage2);
        SDL_FreeSurface(face1);
        SDL_FreeSurface(face2);
        SDL_FreeSurface(face3);
        SDL_FreeSurface(face4);
        SDL_FreeSurface(face5);
        SDL_FreeSurface(face6);

}


void hover_valider(SDL_Surface *ecran,  SDL_Event event)
{
	SDL_Surface *valider2;
	SDL_Rect posvalider;
		
	posvalider.x=620;
	posvalider.y=550;

	valider2=TTF_RenderText_Blended(fontSousMenu2,"Valider",fontOrange);
		
	if(event.button.x >=posvalider.x && event.button.x<= posvalider.x + valider->w && event.button.y >= posvalider.y && event.button.y <= posvalider.y+valider->h)
		hover(ecran,valider2,fontSousMenu2,"Valider",fontOrange,posvalider);
	else
		hover(ecran,valider2,fontSousMenu2,"Valider",fontBlack,posvalider);
			
	SDL_FreeSurface(valider2);
	
}

	
				
void default_valider(SDL_Surface *ecran, int de1, int de2)
{
	SDL_Surface *valider2;
	SDL_Rect posvalider;
	posvalider.x=620;
	posvalider.y=550;
	valider2=TTF_RenderText_Blended(fontSousMenu2,"Valider",fontOrange);
	
	if(de1!=de2)
		SDL_BlitSurface(valider2,NULL,ecran,&posvalider);
	
	SDL_FreeSurface(valider2);
}


void button_valider(int *afficher_valider,int clicX,int clicY)
{
	if(clicX >=620 && clicX<=702 && clicY >= 551 && clicY <=570)
		*afficher_valider=1;

}
