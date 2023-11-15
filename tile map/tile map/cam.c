#include "cam.h"
#include "tools.h"
#include "SFML/Graphics.h"
#include "map.h"


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

void displayCam(sfRenderWindow* _window)
{ 
	// Affichage de la view
	sfRenderWindow_setView(_window, cam); 
	
}

void EditorMod_cam()
{
	// Passage en mode édition de map
	camrect.x = 2400;
	camrect.y = 1800;
	sfView_setSize(cam, camrect);
}

void GameMod_cam()
{
	// Passage en mode jeu 
	camrect.x = 800;
	camrect.y = 600;
	sfView_setSize(cam, camrect);
}
