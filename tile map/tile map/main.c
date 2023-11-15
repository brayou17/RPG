#include "SFML/graphics.h"
#include <stdlib.h>
#include <stdio.h>
#include "map.h"
#include "tools.h"
#include <math.h>
#include <time.h>
#include "player.h"
#include "menu.h"

#define TEXTURE_PATH "../Ressources/Textures/"


// Enum pour les statues du jeu
enum statue
{
	MENU = 0,
	JOUER = 1,
	EDITEUR = 2,
	QUITTER = 3
};

typedef statue statue;

statue statueActuelle = MENU;

int main()
{
	float animTime = 0.0f;
	int animCoffre = 0;

	//init
	initTools();
	sfVideoMode mode = { 800, 600, 32 };
	sfRenderWindow* window;
	window = sfRenderWindow_create(mode, "Window", sfDefaultStyle, NULL);

	

	sfEvent event;
	initMap();
	initPlayer();
	initCam();
	initMenu();
	
	float timer = 0.0f;

	//boucle de jeu
	while (sfRenderWindow_isOpen(window))
	{
		//timer
		restartClock();
		timer += GetDeltaTime();

		//update
		while (sfRenderWindow_pollEvent(window, &event))
		{
			if (event.type == sfEvtClosed)
			{
				sfRenderWindow_close(window);
			}
		}
		if (statueActuelle == MENU)
			updateMenu();
		else if (statueActuelle == JOUER)
		{	updatePlayer(window);
		updateMap(window, animCoffre, cam);
		}
		else if (statueActuelle == EDITEUR)
			updateMap(window, animCoffre, cam);
		else if (statueActuelle == QUITTER)
			sfRenderWindow_close(window);

		updatePlayer(window);
		updateMap(window, animCoffre, cam);
		//affichage
		if (timer > 0.8f)
		{
			timer = 0.0f;
			animCoffre = (animCoffre + 1) % 4;
		}
		
		if (statueActuelle == MENU)
			DisplayMenu(window);
		else if (statueActuelle == JOUER)
		{
			displayMap(window, animCoffre, cam);
			displayCam(window, animCoffre);
			displayPlayer(window);
		}
		else if (statueActuelle == EDITEUR)
		{
			displayMap(window, animCoffre, cam);
			displayCam(window, animCoffre);
		}
	
		sfRenderWindow_clear(window, sfBlack);
		
		displayMap(window, animCoffre, cam);
		displayCam(window, animCoffre);
		displayPlayer(window);
		
		sfRenderWindow_display(window);
		if (sfKeyboard_isKeyPressed(sfKeyL))
		{
	 		sfRenderWindow_close(window);
		}
	}
	return 0;
}

 
