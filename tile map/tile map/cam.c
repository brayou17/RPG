#include "cam.h"
#include "tools.h"
#include "SFML/Graphics.h"
#include "map.h"

sfView* cam;
sfVector2f camrect = {800 ,600 };


void initCam()
{
	// Initialisation de la view
	cam = sfView_create();
	sfView_setSize(cam ,camrect);
}


void updateCam(sfVector2f _playerpos)
{

	// Update de la view
	sfView_setCenter(cam, _playerpos);
	
}

void displayCam(sfRenderWindow* _window, int _animCoffre)
{ 
	// Affichage de la view
	sfRenderWindow_setView(_window, cam); 
	displayMap(_window, _animCoffre, cam);
}

void EditorMod_cam()
{
	// Passage en mode �dition de map
	camrect.x = 3840;
	camrect.y = 2160;
	sfView_setSize(cam, camrect);
}

void GameMod_cam()
{
	// Passage en mode jeu 
	camrect.x = 800;
	camrect.y = 600;
	sfView_setSize(cam, camrect);
}
