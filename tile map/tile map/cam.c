#include "cam.h"
#include "tools.h"
#include "SFML/Graphics.h"
#include "map.h"


sfVector2f camrect = {200.f ,150.f };
int Editor = 0;

void initCam()
{
	// Initialisation de la view
	cam = sfView_create();
	sfView_setSize(cam ,camrect);
}

sfVector2f sicam = { 2000.f ,1500.f };
float timer;
void updateCam(sfVector2f _playerpos)
{
	if (Editor == 1)
	{
		timer += GetDeltaTime();
		if (sfKeyboard_isKeyPressed(sfKeyUp) && timer > 0.1f)
		{
			timer = 0.0f;
			sicam.y = sicam.y*0.9f ;
			sicam.x = sicam.x*0.9f;
		}
		if (sfKeyboard_isKeyPressed(sfKeyDown) && timer > 0.1f)
		{
			timer = 0.0f;
			sicam.y = sicam.y * 1.1f;
			sicam.x = sicam.x * 1.1f;
		}	
		camrect.x = sicam.x;
		camrect.y = sicam.y;
		sfView_setSize(cam, camrect);
	}
	
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
	Editor = 1;

	// Passage en mode �dition de map

}

void GameMod_cam()
{
	// Passage en mode jeu 
	Editor = 0;
	camrect.x = 200.f;
	camrect.y = 150.f;
	sfView_setSize(cam, camrect);
}
