#include "SFML/graphics.h"
#include <stdlib.h>
#include <stdio.h>
#include"map.h"
#include"tools.h"
#include<math.h>
#include<time.h>
#include"player.h"

#define TEXTURE_PATH "../Ressources/Textures/"

int main()
{
	

	//init
	initTools();
	sfVideoMode mode = { 800, 600, 32 };
	sfRenderWindow* window;
	window = sfRenderWindow_create(mode, "Window", sfDefaultStyle, NULL);

	int animCoffre = 0;


	sfEvent event;
	initMap();
	initPlayer();
	initCam();
	

	//boucle de jeu
	while (sfRenderWindow_isOpen(window))
	{
		
		restartClock();
		//update
		while (sfRenderWindow_pollEvent(window, &event))
		{
			if (event.type == sfEvtClosed)
			{
				sfRenderWindow_close(window);
			}
		}
		updatePlayer(window);
		updateMap(window, cam);
		//affichage
		
	
		sfRenderWindow_clear(window, sfBlack);
		
		displayMap(window,cam);
		displayCam(window);
		displayPlayer(window);
		
		sfRenderWindow_display(window);
		if (sfKeyboard_isKeyPressed(sfKeyL))
		{
	 		sfRenderWindow_close(window);
		}
	}
	return 0;
}

 
