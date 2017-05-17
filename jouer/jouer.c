#include "../fonctions.h"
#include "../global.h"
#include "jouer.h"



void default_jouer (SDL_Surface *ecran, int i, int qui_commence, int *menu)
{
	int j;
	
	texte_Quitter = TTF_RenderText_Blended(fontSousMenu,"Quitter",fontBlack);
	retour = TTF_RenderText_Blended(fontSousMenu,"Retour",fontBlack);
	SDL_BlitSurface(background2,NULL,ecran,&posBackground);
	SDL_BlitSurface(board,NULL,ecran,&posBoard);
	SDL_BlitSurface(texte_Quitter,NULL,ecran,&posQuitter2);
	SDL_BlitSurface(retour,NULL,ecran,&posRetour2);
	SDL_BlitSurface(sauvegarder,NULL,ecran,&posSauvegarder);
	SDL_BlitSurface(historique,NULL,ecran,&posHistorique);
	//SDL_BlitSurface(valider,NULL,ecran,&posValider);
	SDL_BlitSurface(undo,NULL,ecran,&posUndo);
	
	if(!qui_commence)
	{
	for(j=0;j<i;j++){
		if(plateau[j].player)
			SDL_BlitSurface(pionBleu,NULL,ecran,&plateau[j].posPions);
		else
			SDL_BlitSurface(pionRouge,NULL,ecran,&plateau[j].posPions);
	}
		if ((i % 2))
			SDL_BlitSurface(joueur2,NULL,ecran,&posjoueur1);
		else		
			SDL_BlitSurface(joueur1,NULL,ecran,&posjoueur2);
	}else
	{
		for(j=0;j<i;j++)
		{
			if(plateau[j].player)
				SDL_BlitSurface(pionBleu,NULL,ecran,&plateau[j].posPions);
			else
			SDL_BlitSurface(pionRouge,NULL,ecran,&plateau[j].posPions);
		}	
		if ((i % 2))
			SDL_BlitSurface(joueur1,NULL,ecran,&posjoueur1);
		else		
			SDL_BlitSurface(joueur2,NULL,ecran,&posjoueur2);
	}
	maj_voisins(i);
	if (detection_gagnant(i))
	{
		*menu=8;
		default_winner(ecran,qui_commence,i);
	}
	
}

void hover_jouer (SDL_Surface *ecran, SDL_Event event)
{
	
	if(event.button.x >=38 && event.button.x<=204 && event.button.y >= 100 && event.button.y <=135)
		hover(ecran,historique,fontSousMenu,"Historique",fontOrange,posHistorique);
	else if(event.button.x >=21 && event.button.x<=228 && event.button.y >= 200 && event.button.y <=235)	
		hover(ecran,sauvegarder,fontSousMenu,"Sauvegarder",fontOrange,posSauvegarder);	
	else if(event.button.x >=51 && event.button.x<=164 && event.button.y >= 300 && event.button.y <=327)	
		hover(ecran,retour,fontSousMenu,"Retour",fontOrange,posRetour2);
	else if(event.button.x >=47 && event.button.x<=162 && event.button.y >= 400 && event.button.y <=432)
		hover(ecran,texte_Quitter,fontSousMenu,"Quitter",fontOrange,posQuitter2);
	else if(event.button.x >=601 && event.button.x<=678 && event.button.y >= 501 && event.button.y <=519)
	{
		//hover(ecran,valider,fontSousMenu2,"valider",fontOrange,posValider);
	}else if(event.button.x >=401 && event.button.x<=455 && event.button.y >= 501 && event.button.y <=521)
		hover(ecran,undo,fontSousMenu2,"undo",fontOrange,posUndo);
	else
	{								
		hover(ecran,historique,fontSousMenu,"Historique",fontBlack,posHistorique);
		hover(ecran,sauvegarder,fontSousMenu,"Sauvegarder",fontBlack,posSauvegarder);
		hover(ecran,retour,fontSousMenu,"Retour",fontBlack,posRetour2);
		hover(ecran,texte_Quitter,fontSousMenu,"Quitter",fontBlack,posQuitter2);
		//hover(ecran,valider,fontSousMenu2,"valider",fontBlack,posValider);
		hover(ecran,undo,fontSousMenu2,"undo",fontBlack,posUndo);
	}
}
	
void button_jouer (int *menu, bool *continuer,int clicX, int clicY,int *i, int *nb_tour, int *retour_bouton, int qui_commence,int contre_IA)
{
	static SDL_Rect posPionTemp;
	static int t,l,j;
	static int l_bot=0,c_bot=0;
	
	int r=15,h=5,s=20;
	int test=*i;
	
	if(clicX >=38 && clicX<=204 && clicY >= 100 && clicY <=135)
		*menu=5;
		/*historique*/
	else if(clicX >=21 && clicX<=228 && clicY >= 200 && clicY <=235)		
	{
		save(test);
		/*Save*/
	}else if(clicX >=51 && clicX<=164 && clicY >= 300 && clicY <=327)
	{
		*menu = 7;
		*retour_bouton=1;
		/*retour*/
	}
	else if(clicX >=47 && clicX<=162 && clicY >= 400 && clicY <=432)
    		*menu = 7;
    		/*quitter*/
	else if(clicX >=601 && clicX<=678 && clicY >= 501 && clicY <=519)
	{
					/*valider*/
					//coup_valide=1;	
	}else if(clicX >=401 && clicX<=455 && clicY >= 501 && clicY <=521)
	{
		if (test>0)
			*i-=1;
		/*undo*/
	}
	else 
	{				
		l=(clicY-154)/(h+s);
		t=((clicX-274-(l*r)))/(2*r);
		
		if (t >= 0 && t <= 10 && l >= 0 && l <= 10 && coup_valide(test,l,t))
		{
			if (l % 2)
				posPionTemp.x=274+(t+l/2)*2*r+2*r-11;
			else
				posPionTemp.x=274+(t+l/2)*2*r+r-11;
						
			posPionTemp.y=154+l*(h+s)+h+(s/2)-11;
			plateau[test].posPions=posPionTemp;
			
			if (!qui_commence)
				if (test % 2)
					plateau[test].player=1;
				else
					plateau[test].player=0;
			else
				if (test % 2)
					plateau[test].player=0;
				else
					plateau[test].player=1;
					
			plateau[test].coordinates.ligne=l;
			plateau[test].coordinates.colonne=t;
			
			if (plateau[test].player)
				if (t == 0)
					plateau[test].bord=2;
				else if (t == 10)
					plateau[test].bord=4;
				else
					plateau[test].bord=0;
			else
				if (l == 0)
					plateau[test].bord=1;
				else if (l == 10 )
					plateau[test].bord=3;
				else
					plateau[test].bord=0;
				printf("test =%d\n",test);
			*i+=1;
			*nb_tour+=1;
			if(contre_IA)
			{
				if (test == 0)
				{
					l_bot =0;
					c_bot =0;
				}
				test=*i;
				l=l_bot;
				t=c_bot;
				if (!qui_commence)
				if (test % 2)
					plateau[test].player=1;
				else
					plateau[test].player=0;
			else
				if (test % 2)
					plateau[test].player=0;
				else
					plateau[test].player=1;
				
				if(!coup_valide(test,l,t))
					if (!plateau[test].player)
					{
						c_bot++; l_bot--;
					}else
					{
						l_bot++; c_bot--;
					}
				l=l_bot;
				t=c_bot;
				
				
				if (t >= 0 && t <= 10 && l >= 0 && l <= 10 && coup_valide(test,l,t))
				{
					printf("normal\n");
					if (l % 2)
						posPionTemp.x=274+(t+l/2)*2*r+2*r-11;
					else
						posPionTemp.x=274+(t+l/2)*2*r+r-11;
								
					posPionTemp.y=154+l*(h+s)+h+(s/2)-11;
					plateau[test].posPions=posPionTemp;
						
					if (!qui_commence)
						if (test % 2)
							plateau[test].player=1;
						else
							plateau[test].player=0;
					else		
						if (test % 2)
							plateau[test].player=0;
						else
							plateau[test].player=1;
					
					plateau[test].coordinates.ligne=l;
					plateau[test].coordinates.colonne=t;
			
					if (plateau[test].player)
						if (t == 0)
							plateau[test].bord=2;
						else if (t == 10)
							plateau[test].bord=4;
						else
							plateau[test].bord=0;
					else
						if (l == 0)
							plateau[test].bord=1;
						else if (l == 10 )
							plateau[test].bord=3;
						else
							plateau[test].bord=0;
					if (plateau[test].player)
						c_bot++;
					else
						l_bot++;
					*i+=1;
				
				}
				
			}
			
		}
	}
}
