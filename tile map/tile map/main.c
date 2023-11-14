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
	float animTime = 0.0f;
	int test = 0;

	//init
	initTools();
	sfVideoMode mode = { 800, 600, 32 };
	sfRenderWindow* window;
	window = sfRenderWindow_create(mode, "Window", sfDefaultStyle, NULL);

	

	sfEvent event;
	initMap();
	initPlayer();
	initCam();
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
		updatePlayer(window);
		//affichage
		if (timer > 0.8f)
		{
			timer = 0.0f;
			test = (test + 1) % 4;
		}
	
		sfRenderWindow_clear(window, sfBlack);
		
		displayCam(window, test);
		displayPlayer(window);
		
		sfRenderWindow_display(window);
		if (sfKeyboard_isKeyPressed(sfKeyL))
		{
	 		sfRenderWindow_close(window);
		}
	}
	return 0;
}

 
