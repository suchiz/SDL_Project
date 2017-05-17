CC=gcc
CFLAGS= `sdl-config --cflags --libs` -lSDL_image -lSDL_ttf 
LDFLAGS=
EXEC=hexcaliba

DIFDIR= choix_difficulte
ADVDIR= choix_adversaire
MENDIR= menu1
FONDIR= fonctions
JOUDIR= jouer
SAVDIR= save
CHADIR= charger
ROLDIR= roll_dices
HISDIR= historique



all:$(EXEC)

main.o: main.c
	$(CC) -o main.o -c main.c  $(CFLAGS)
	
fonctions.o: $(FONDIR)/fonctions.c
	$(CC) -o fonctions.o -c $(FONDIR)/fonctions.c  $(CFLAGS)

menu1.o: $(MENDIR)/menu1.c 
	$(CC) -o menu1.o -c $(MENDIR)/menu1.c  $(CFLAGS)

choix_adversaire.o: $(ADVDIR)/choix_adversaire.c
	$(CC) -o choix_adversaire.o -c $(ADVDIR)/choix_adversaire.c  $(CFLAGS)
	
choix_difficulte.o: $(DIFDIR)/choix_difficulte.c
	$(CC) -o choix_difficulte.o -c $(DIFDIR)/choix_difficulte.c  $(CFLAGS)
	
jouer.o: $(JOUDIR)/jouer.c
	$(CC) -o jouer.o -c $(JOUDIR)/jouer.c $(CFLAGS)
	
areusure.o: $(JOUDIR)/areusure.c
	$(CC) -o areusure.o -c $(JOUDIR)/areusure.c $(CFLAGS)
	
sauvegarder.o: $(SAVDIR)/sauvegarder.c
	$(CC) -o sauvegarder.o -c $(SAVDIR)/sauvegarder.c $(CFLAGS)

historique.o: $(HISDIR)/historique.c
	$(CC) -o historique.o -c $(HISDIR)/historique.c $(CFLAGS)
	
charger.o: $(CHADIR)/charger.c 
	$(CC) -o charger.o -c $(CHADIR)/charger.c  $(CFLAGS)
	
win_screen.o: $(JOUDIR)/win_screen.c 
	$(CC) -o win_screen.o -c $(JOUDIR)/win_screen.c  $(CFLAGS)	

roll_dices.o: $(ROLDIR)/roll_dices.c
	$(CC) -o roll_dices.o -c $(ROLDIR)/roll_dices.c  $(CFLAGS)
	
$(EXEC): main.o fonctions.o menu1.o choix_adversaire.o choix_difficulte.o jouer.o sauvegarder.o charger.o roll_dices.o historique.o areusure.o win_screen.o
	$(CC) main.o menu1.o fonctions.o choix_adversaire.o choix_difficulte.o jouer.o sauvegarder.o charger.o roll_dices.o historique.o areusure.o win_screen.o -o $(EXEC) $(CFLAGS)
	
clean:
	rm -rf *.o $(EXEC)
	
clean_save: 
	rm -rf $(SAVDIR)/*.txt
	

