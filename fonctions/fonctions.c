#include "../fonctions.h"
#include "../global.h"

void hover (SDL_Surface *ecran, SDL_Surface *texte, TTF_Font *font, char string[], SDL_Color color, SDL_Rect pos)
{
	texte = TTF_RenderText_Blended(font,string,color);
	SDL_BlitSurface(texte,NULL,ecran,&pos);
}

void extern_init()
{
	f_in=fopen("./save/names.txt","a+");
	background = IMG_Load("Images/rsz_background2.png");
	background2 = IMG_Load("Images/background3.jpg");
	board = IMG_Load("Images/hex.png");
	pionRouge = IMG_Load("Images/button-red22.png");
	pionBleu = IMG_Load("Images/button-blue22.png");
	fontMenu=  TTF_OpenFont("mechanik/mechanik-Regular.ttf",55);
	fontSousMenu = TTF_OpenFont("mechanik/mechanik-Regular.ttf",35);
	fontSousMenu2 = TTF_OpenFont("mechanik/mechanik-Regular.ttf",25);
  	bienvenue = TTF_RenderText_Blended(fontMenu,"Bienvenue dans HEX",fontBlack);
    	texte_Jouer = TTF_RenderText_Blended(fontMenu,"Jouer",fontBlack);
    	texte_Quitter = TTF_RenderText_Blended(fontMenu,"Quitter",fontBlack);
    	texte_Charger = TTF_RenderText_Blended(fontMenu,"Charger",fontBlack);
    	ia=TTF_RenderText_Blended(fontMenu,"Ordinateur",fontBlack);
    	ia1=TTF_RenderText_Blended(fontMenu,"Facile",fontBlack);
    	ia2=TTF_RenderText_Blended(fontMenu,"Intermediaire",fontBlack);
    	difficulte=TTF_RenderText_Blended(fontMenu,"Choisissez une difficulte",fontBlack);
    	adversaire=TTF_RenderText_Blended(fontMenu,"Choisissez un adversaire",fontBlack);
    	human=TTF_RenderText_Blended(fontMenu,"Joueur",fontBlack);
    	retour=TTF_RenderText_Blended(fontMenu,"Retour",fontBlack);
    	sauvegarder=TTF_RenderText_Blended(fontSousMenu,"Sauvegarder",fontBlack);
    	historique=TTF_RenderText_Blended(fontSousMenu,"Historique",fontBlack);
    	valider=TTF_RenderText_Blended(fontSousMenu2,"valider",fontBlack);
    	undo=TTF_RenderText_Blended(fontSousMenu2,"undo",fontBlack);
    	stringHist=TTF_RenderText_Blended(fontSousMenu2,"init",fontBlack);
	joueur1=TTF_RenderText_Blended(fontSousMenu2,"Joueur1",fontRed);
    	joueur2=TTF_RenderText_Blended(fontSousMenu2,"Joueur2",fontBlue);
	names =TTF_RenderText_Blended(fontSousMenu2,"init",fontBlue);
    
    	posRetour3.x = 668;
    	posRetour3.y = 555;

   	posHistorique.x = 35;
    	posHistorique.y = 100;
    
    	posStringHist.x = 35;
    	posStringHist.y = 50;
    
    
    	posQuitter2.x = 45;
    	posQuitter2.y = 400;
    
    	posValider.x = 600;
    	posValider.y = 500;
   
    	posUndo.x = 400;
    	posUndo.y = 500;
   
    	posSauvegarder.x = 20;
    	posSauvegarder.y = 200;
   
    	posRetour2.x = 50;
    	posRetour2.y = 300;
    
    	posHuman.x = 330;
    	posHuman.y = 190;
	
    	posRetour.x = 310;
    	posRetour.y = 390;
    
    	posBackground.x = 0;
    	posBackground.y = 0;
    
    	posIA.x = 280;
    	posIA.y = 290;

    	posIA1.x = 330;
    	posIA1.y = 190;
    
    	posIA2.x = 240;
    	posIA2.y = 290;
    
    	posAdversaire.x = 75;
    	posAdversaire.y = 50;
    
    	posDifficulte.x = 75;
    	posDifficulte.y = 50;

    	posBienvenue.x = 130;
    	posBienvenue.y = 40;
    
    	posTexte_Jouer.x = 330;
    	posTexte_Jouer.y = 190;
    
    	posTexte_Charger.x = 300;
    	posTexte_Charger.y = 290;
    
    	posTexte_Quitter.x = 310;
    	posTexte_Quitter.y = 390;

    	posBoard.x = 255;
    	posBoard.y = 135;
    
    	posjoueur1.x=360;
   	posjoueur1.y=80;
    
    	posjoueur2.x=360;
    	posjoueur2.y=80;
	
	nb_charger = 0;
	
	
	
	
	
}


void maj_voisins(int test)
{
	int j,k;

	for (k=0; k < test; k++)
		for (j=0; j < test; j++)
			if (plateau[j].player == plateau[k].player)
				if (plateau[j].coordinates.ligne == plateau[k].coordinates.ligne && plateau[j].coordinates.colonne == plateau[k].coordinates.colonne+1)
					plateau[k].voisins[4]=1;
				else if (plateau[j].coordinates.ligne == plateau[k].coordinates.ligne && plateau[j].coordinates.colonne == plateau[k].coordinates.colonne-1)
					plateau[k].voisins[1]=1;
				else if (plateau[j].coordinates.ligne == plateau[k].coordinates.ligne-1 && plateau[j].coordinates.colonne == plateau[k].coordinates.colonne+1)
					plateau[k].voisins[3]=1;
				else if (plateau[j].coordinates.ligne == plateau[k].coordinates.ligne-1 && plateau[j].coordinates.colonne == plateau[k].coordinates.colonne)
					plateau[k].voisins[2]=1;
				else if (plateau[j].coordinates.ligne == plateau[k].coordinates.ligne+1 && plateau[j].coordinates.colonne == plateau[k].coordinates.colonne)
					plateau[k].voisins[5]=1;
				else if (plateau[j].coordinates.ligne == plateau[k].coordinates.ligne+1 && plateau[j].coordinates.colonne == plateau[k].coordinates.colonne-1)
					plateau[k].voisins[0]=1;

}


int parcours_voisins(int j, int test, int bord_player, int venu,int tab_visite[],int indice){

	int i,k,found=0,var_retour=0,m,found2=0;
	for (k =0; k < 6 && plateau[j].bord != bord_player; k++)
	{
	
		found=0;
		found2=0;
		if (plateau[j].voisins[k] && k != venu)
		{
			var_retour=0;	
			if (k == 0)
			{
				for (i=0; i < test && !found; i++)
					if (plateau[i].coordinates.ligne == plateau[j].coordinates.ligne+1 && plateau[i].coordinates.colonne == plateau[j].coordinates.colonne-1)
						found++;
				
				tab_visite[indice]=i-1;
				for (m=0; m < indice && !found2; m++)
					if (tab_visite[m]==i-1)
						found2++;
				if (!found2)
					var_retour=parcours_voisins(i-1,test,bord_player,3,tab_visite,indice+1);
				
			}else if (k == 1)
			{
				for (i=0; i < test && !found; i++)
					if (plateau[i].coordinates.ligne == plateau[j].coordinates.ligne && plateau[i].coordinates.colonne == plateau[j].coordinates.colonne-1)
						found++;
				
				tab_visite[indice]=i-1;
				for (m=0; m < indice && !found2; m++)
					if (tab_visite[m]==i-1)
						found2++;
				if (!found2)
					var_retour=parcours_voisins(i-1,test,bord_player,4,tab_visite,indice+1);
				
			}else if (k == 2)
			{
				for (i=0; i < test && !found; i++)
					if (plateau[i].coordinates.ligne == plateau[j].coordinates.ligne-1 && plateau[i].coordinates.colonne == plateau[j].coordinates.colonne)
						found++;
				tab_visite[indice]=i-1;
				for (m=0; m < indice && !found2; m++)
					if (tab_visite[m]==i-1)
						found2++;
				if (!found2)
					var_retour=parcours_voisins(i-1,test,bord_player,5,tab_visite,indice+1);
				
			}
			else if (k == 3)
			{
				for (i=0; i < test && !found; i++)
					if (plateau[i].coordinates.ligne == plateau[j].coordinates.ligne-1 && plateau[i].coordinates.colonne == plateau[j].coordinates.colonne+1)
						found++;
				tab_visite[indice]=i-1;
				for (m=0; m < indice && !found2; m++)
					if (tab_visite[m]==i-1)
						found2++;
				if (!found2)
					var_retour=parcours_voisins(i-1,test,bord_player,0,tab_visite,indice+1);
				
			}
			else if (k == 4)
			{
				for (i=0; i < test && !found; i++)
					if (plateau[i].coordinates.ligne == plateau[j].coordinates.ligne && plateau[i].coordinates.colonne == plateau[j].coordinates.colonne+1)
						found++;
				tab_visite[indice]=i-1;
				for (m=0; m < indice && !found2; m++)
					if (tab_visite[m]==i-1)
						found2++;
				if (!found2)
					var_retour=parcours_voisins(i-1,test,bord_player,1,tab_visite,indice+1);
				
			}
			else if (k == 5)
			{
				for (i=0; i< test && !found; i++)
					if (plateau[i].coordinates.ligne == plateau[j].coordinates.ligne+1 && plateau[i].coordinates.colonne == plateau[j].coordinates.colonne)
						found++;
				tab_visite[indice]=i-1;
				for (m=0; m < indice && !found2; m++)
					if (tab_visite[m]==i-1)
						found2++;
				if (!found2)
					var_retour=parcours_voisins(i-1,test,bord_player,2,tab_visite,indice+1);
				
			}
			if (var_retour)
				return 1;
		}
	}
	if (plateau[j].bord == bord_player)
		return 1;
	else 
		return 0;
}

int detection_gagnant(int test)
{
	int i,winner =0,indice=0;
	int tab_visite[MAX_HEX];
	
	for(i=0 ; i< test; i++) 
		tab_visite[i]=0;
	
	for (i=0; i < test && !winner; i++)
		if (plateau[i].bord == 1)
			winner = parcours_voisins(i,test,3,-1,tab_visite,indice);
		else if (plateau[i].bord == 2)
			winner = parcours_voisins(i,test,4,-1,tab_visite,indice);
	return winner;
}
			
					
int coup_valide(int test, int l, int c)
{
	int j,empty=1;
	for(j=0 ; j< test && empty; j++)
		if (plateau[j].coordinates.ligne == l && plateau[j].coordinates.colonne == c)
			empty--;
		
	return empty;
}












