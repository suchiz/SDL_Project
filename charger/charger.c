#include "charger.h"

void default_charger (SDL_Surface *ecran)
{

	
	int i;
	posStringHist.y=50;
	SDL_BlitSurface(background2,NULL,ecran,&posBackground);
	for(i = 0; i < nb_charger; i++)
	{
		hover(ecran,names,fontSousMenu,tab_charger[i],fontBlack,posStringHist);
		posStringHist.y+=50;
	}
	hover(ecran,retour,fontSousMenu,"Retour",fontBlack,posRetour3);
	
	
}

void hover_charger (SDL_Surface *ecran, SDL_Event event)
{
	int i;
	posStringHist.y=50;
	for(i = 0; i < nb_charger; i++)
	{
		names = TTF_RenderText_Blended(fontSousMenu,tab_charger[i],fontBlack);
		if (event.button.x >= posStringHist.x && event.button.x <= posStringHist.x + names->w 
			&& event.button.y >= posStringHist.y && event.button.y <= posStringHist.y+names->h)
			hover(ecran,names,fontSousMenu,tab_charger[i],fontOrange,posStringHist);
		else if(event.button.x >=670 && event.button.x<=782 && event.button.y >= 555 && event.button.y <=583)
			hover(ecran,retour,fontSousMenu,"Retour",fontOrange,posRetour3);
		else
		{
			hover(ecran,names,fontSousMenu,tab_charger[i],fontBlack,posStringHist);
			hover(ecran,retour,fontSousMenu,"Retour",fontBlack,posRetour3);
		}
		posStringHist.y+=50;
	}
}

void button_charger (int *menu, int clicX,int clicY,int *indice,int *afficher_rolldice, int *afficher_resultat, int *afficher_valider)
{
	int i = clicY/50 - 1;
	char temp[MAX_STRING]="./save/";
	FILE* f_temp=NULL;
	
	if (i>=0 && i<nb_charger)
	{
		names = TTF_RenderText_Blended(fontSousMenu,tab_charger[i],fontBlack);
		if (clicX >= posStringHist.x && clicX <= posStringHist.x + names->w && clicY >= 50 && clicY <= posStringHist.y+names->h)
		{
			*indice=0;
			strcat(temp,tab_charger[i]);
			temp[strlen(temp)-1]='\0';
			f_temp=fopen(temp,"r");
			if (f_temp == NULL){
				printf("Caca :::! !! \n");
				exit(5);
			}
			int j=0;
			while(!feof(f_temp))
			{
				
				fgets(temp,sizeof(temp),f_temp);
				if (feof(f_temp))
					break;
				//printf("temp %s", temp);
				sscanf(temp,"%d %d %d %d %d %d %d %d %d %d %d %d",
					&plateau[j].posPions.x,&plateau[j].posPions.y,
	  				&plateau[j].player,
	  				&plateau[j].coordinates.ligne,&plateau[j].coordinates.colonne,
	  				&plateau[j].bord,
	  				&plateau[j].voisins[0],&plateau[j].voisins[1],&plateau[j].voisins[2],
	  				&plateau[j].voisins[3],&plateau[j].voisins[4],&plateau[j].voisins[5]);
				j++;
				*indice+=1;
				
			}	
			*menu=4;
			*afficher_rolldice=1;
			*afficher_resultat=1;
			*afficher_valider=1;
		}
	}else if(clicX >=670 && clicX<=782 && clicY >= 555 && clicY <=583)
			*menu=1;
	
	if(f_temp != NULL)
		fclose(f_temp);
}
	
void charger()
{
	while(!feof(f_in))
	{
		fgets(ligne,sizeof(ligne),f_in);
		if (feof(f_in))
			break;
		
		strcpy(tab_charger[nb_charger],ligne);
		nb_charger++;
	}
}

