#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
 
#include <SDL/SDL.h>
#include <SDL/SDL_keysym.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

#include "fonctions.h"
#include "global.h" 

SDL_Surface *ecran, *bienvenue, *texte_Jouer, *texte_Charger, *texte_Quitter,*background,
    		*ia, *ia1, *ia2, *human, *difficulte, *adversaire, *retour, *background2,*names,
		*historique, *sauvegarder, *undo, *valider, *stringHist, *board, *joueur1, *joueur2;
		
SDL_Surface *pionRouge;
SDL_Surface *pionBleu;
SDL_Rect posBienvenue, posTexte_Jouer, posTexte_Charger, posTexte_Quitter,posRetour,posBoard,
    	     posHuman, posIA, posIA1, posIA2, posDifficulte, posAdversaire, posRetour2, posBackground,
	     posSauvegarder, posUndo, posHistorique, posQuitter2, posValider, posRetour3, posStringHist, posjoueur1, posjoueur2;

TTF_Font *fontMenu;
TTF_Font *fontSousMenu;
TTF_Font *fontSousMenu2;

SDL_Rect posBackground;
SDL_Rect posBoard;

SDL_Color fontBlack = {223,62,1};	
SDL_Color fontOrange = {223,150,1};
SDL_Color fontRed = {166,24,10};
SDL_Color fontBlue = {11,48,165};

hex plateau[MAX_HEX];
char tab_charger[MAX_STRING][MAX_STRING];
char ligne[MAX_STRING];
int nb_charger;
FILE * f_in;
 
int main(int argc, char *argv[])
{
    Uint32 initflags = SDL_INIT_VIDEO;
    SDL_Surface *ecran;
    Dimensions fenetre; // main window
   	
    fenetre.h = WINHI;  // en pixels
    fenetre.w = WINWI;   

    Uint8  video_bpp = 32; // 32 bits de couleur
    Uint32 videoflags = SDL_HWSURFACE; // utiliser la mémoire vidéo
    
    bool continuer; // pour la boucle principale des évènements 
    SDL_Event event; // aussi
 
    /* Initialize the SDL library */
    if ( SDL_Init(initflags) < 0 )
    {
        fprintf(stderr, "N'arrive pas a` initialiser la SDL : %s\n", SDL_GetError());
        exit(1);
    }
 
    /* Set video mode */
    ecran = SDL_SetVideoMode(fenetre.w, fenetre.h, video_bpp, videoflags); // surface principale

    if (ecran == NULL)
    {
        fprintf(stderr, "N'arrive pas a` etablir mode video%dx%dx%d : %s\n", fenetre.w, fenetre.h, video_bpp, SDL_GetError());
        SDL_Quit();
        exit(2);
    }
       
    SDL_WM_SetCaption("Hexcaliba", NULL); // legende de la fenêtre

    TTF_Init();
    
	extern_init();
      
     SDL_Rect posPionTemp;
	
	SDLKey key_pressed ;
    int coup_valide =0 ,menu=1,j,nb_tour=0, i=0,afficher_rolldice=0,afficher_resultat=0,de1,de2,afficher_valider=0,retour_bouton=0;
    int qui_commence = 0,contre_IA=0;
    continuer = true; // un furieux du c ferait plutôt une boucle infinie. Je préfère rester correct.
    int now=105, before=100, interval=50,k;
    default_menu1(ecran);
    while (continuer)
    {
	now = SDL_GetTicks();
        while ( SDL_PollEvent(&event))
        {
            switch (event.type)
            {
                case SDL_MOUSEMOTION:
			if(menu==1)
				hover_menu1(ecran,event);
			else if(menu==2)
				hover_choix_adversaire(ecran,event);
			else if(menu==3)
				hover_choix_difficulte(ecran,event);
			else if(menu==4)
			{
				if(!afficher_rolldice)
					hover_roll_dice(ecran,event);
				if((afficher_resultat)&&(afficher_rolldice)&&(!afficher_valider))
					hover_valider(ecran,event);
				if((afficher_resultat)&&(afficher_rolldice)&&(afficher_valider))
					hover_jouer(ecran,event);
			}
			else if( menu == 5)
			{
				hover_historique(ecran, event);
			}
			else if (menu == 6)
				hover_charger(ecran,event);
			else if (menu ==7)
				hover_quitter(ecran,event);
			else if (menu == 8)
				hover_winner(ecran,event);
				
			
                    break;
		    
                case SDL_MOUSEBUTTONDOWN:
                    if (event.button.button == SDL_BUTTON_LEFT)
                    {   
                        int clicX = event.motion.x;
                        int clicY = event.motion.y;

			if (menu==1)
				button_menu1(&menu,&continuer,clicX,clicY);
			else if (menu==2)
				button_choix_adversaire(&menu,&continuer,clicX,clicY,&i,&afficher_resultat,&afficher_rolldice,&afficher_valider,&retour_bouton,&contre_IA,&qui_commence);
			else if (menu==3)
				button_choix_difficulte(&menu,clicX,clicY,&contre_IA);
			else if (menu==4)
			{
				if(!afficher_rolldice)
				{
					button_roll_dice(clicX,clicY,&de1,&de2,&afficher_rolldice);
					if(de1==de2)
					{
						afficher_rolldice=0;
						afficher_resultat=0;
					}else if (de1<de2)
						qui_commence++;
				}
				if((afficher_rolldice)&&(afficher_resultat))
					button_valider(&afficher_valider,clicX,clicY);
				if((afficher_rolldice)&&(afficher_resultat)&&(afficher_valider))
					button_jouer(&menu,&continuer,clicX,clicY,&i, &nb_tour, &retour_bouton,qui_commence,contre_IA);
			}
			else if (menu == 5 )
			{
				button_historique(&menu, clicX, clicY);
			}else if (menu == 6)
				button_charger(&menu,clicX,clicY,&i,&afficher_rolldice,&afficher_resultat,&afficher_valider);
			else if (menu == 7 && retour_bouton)
					button_quitter_2(&menu,clicX,clicY,i);
			else if (menu == 7 && !retour_bouton)
					button_quitter(&menu,&continuer,clicX,clicY,i);
			else if (menu == 8)
				button_winner(&menu, clicX,clicY,i);
				    
                    }
                    break;
                case SDL_KEYDOWN:
                    key_pressed = event.key.keysym.sym; // on récupère la touche
                    switch (key_pressed)
                    {
                    	case SDLK_ESCAPE: /* Esc keypress quits the app... */
                     		if (menu == 4)
					menu = 7;
				else
					continuer=0;
                        break;
                    }
                    break;
                case SDL_QUIT:
                    	if (menu == 4)
				menu = 7;
			else
				continuer=0;
                    break;
                default:
			if(menu==1)
				default_menu1(ecran);
			else if(menu==2)
				default_choix_adversaire(ecran);
			else if(menu==3)
				default_choix_difficulte(ecran);
			else if(menu==4)
			{
				if(!afficher_rolldice)
					default_roll_dice(ecran);
				if((!afficher_resultat)&&(afficher_rolldice))
				{
					default_roll_resultat(ecran,de1,de2);
					afficher_resultat++;
				}
				if((afficher_resultat)&&(afficher_rolldice)&&(!afficher_valider))
					default_valider(ecran,de1,de2);
				if((afficher_resultat)&&(afficher_rolldice)&&(afficher_valider))
					default_jouer(ecran,i, qui_commence, &menu);
			}
			else if(menu == 5)
			{
				default_historique(ecran,i);
			}
			else if (menu == 6)
				default_charger(ecran);
			else if (menu == 7)
				default_quitter(ecran);
			else if (menu == 8)
				default_winner(ecran,qui_commence,i);
                    break;
            }
        }
        if (now-before<interval)
		SDL_Delay(interval-(now-before));
        // refresh screen
        // mettre ici tous les blit utiles s'il y a des changements dans les surfaces, board, nouveaux pions
        SDL_Flip(ecran); //maj des surfaces pour affichage
	before=now;
    }
    
    /* Clean up the SDL library */
    SDL_FreeSurface(pionBleu);
    SDL_FreeSurface(pionRouge);
    SDL_FreeSurface(ecran);
    SDL_FreeSurface(board);
    SDL_FreeSurface(background);
    SDL_FreeSurface(bienvenue);
    SDL_FreeSurface(texte_Charger);
    SDL_FreeSurface(texte_Jouer);
    SDL_FreeSurface(texte_Quitter);
    SDL_FreeSurface(ia);
    SDL_FreeSurface(ia1);
    SDL_FreeSurface(retour);
    SDL_FreeSurface(ia2);
    SDL_FreeSurface(human);
    SDL_FreeSurface(difficulte);
    SDL_FreeSurface(adversaire);
    SDL_FreeSurface(background2);
    SDL_FreeSurface(historique);
    SDL_FreeSurface(sauvegarder);
    SDL_FreeSurface(undo);
    SDL_FreeSurface(valider);
    SDL_FreeSurface(stringHist);
    SDL_FreeSurface(names);
    TTF_CloseFont(fontMenu);
    TTF_CloseFont(fontSousMenu);
    TTF_CloseFont(fontSousMenu2);
    TTF_Quit();
    SDL_Quit();
    fclose(f_in);
    return(0);
}
