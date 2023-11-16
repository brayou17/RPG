#include "SFML/graphics.h"
#include <stdlib.h>
#include <stdio.h>
<<<<<<< Updated upstream
#include "map.h"
#include "tools.h"
#include <math.h>
#include <time.h>
#include "player.h"
#include "menu.h"
#include "NPC.h"
=======
#include"map.h"
#include"tools.h"
#include<math.h>
#include<time.h>
#include"player.h"
>>>>>>> Stashed changes

#define TEXTURE_PATH "../Ressources/Textures/"

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
<<<<<<< Updated upstream
	initMenu();
   	initNPC();

=======
>>>>>>> Stashed changes
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
<<<<<<< Updated upstream
		if (actualState == MENU)
		{
			updateMenu(window);
			updateMenu(window);
		}
		else if (actualState == JOUER)
		{
			updateNPC(window);
			updatePlayer(window);
			updateMap(window, cam);
		}
		else if (actualState == EDITEUR)
			updateMap(window, cam);

		else if (actualState == QUITTER)
			sfRenderWindow_close(window);



=======
		updatePlayer(window);
>>>>>>> Stashed changes
		//affichage
		if (timer > 0.8f)
		{
			timer = 0.0f;
			animCoffre = (animCoffre + 1) % 4;
		}
	
		sfRenderWindow_clear(window, sfBlack);
<<<<<<< Updated upstream

		if (actualState == MENU)
		{
			DisplayMenu(window);
		}
		else if (actualState == JOUER)
		{
			displayMap(window, cam);
			displayCam(window);
			displayPlayer(window);
			DisplayNPC(window);
		}
		else if (actualState == EDITEUR)
		{
			displayMap(window, cam);
			displayCam(window);
		}

=======
		
		displayCam(window, animCoffre);
		displayPlayer(window);
>>>>>>> Stashed changes
		
		sfRenderWindow_display(window);
		if (sfKeyboard_isKeyPressed(sfKeyL))
		{
	 		sfRenderWindow_close(window);
		}
	}
	return 0;
}

 
