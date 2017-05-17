#include "../global.h"
#include "sauvegarder.h"

void save (int i)
{
	int j;
	char time_string[MAX_STRING];
	char directory[MAX_STRING]= "./save/";
	time_t t= time(NULL);
	struct tm * tm = localtime(&t);
	
	sprintf(time_string,"save_%02u-%02u-%04u_%02u:%02u:%02u.txt",tm->tm_mday,tm->tm_mon+1,1900+tm->tm_year,tm->tm_hour,tm->tm_min,tm->tm_sec);
	strcat(directory,time_string);
	
	FILE *names;
	FILE * f_out;
	f_out = fopen(directory,"a");
	names = fopen("./save/names.txt","a");
	fprintf(names,"%s\n",time_string);
	
	for (j=0; j < i; ++j)
		fprintf(f_out,"%d %d %d %d %d %d %d %d %d %d %d %d\n",
			plateau[j].posPions.x,plateau[j].posPions.y,
	  		plateau[j].player,
	  		plateau[j].coordinates.ligne,plateau[j].coordinates.colonne,
	  		plateau[j].bord,
	  		plateau[j].voisins[0],plateau[j].voisins[1],plateau[j].voisins[2],
	  		plateau[j].voisins[3],plateau[j].voisins[4],plateau[j].voisins[5]);
	
	printf("Partie sauvegardée ! \n");
	
	fclose(f_out);
	fclose(names);
}