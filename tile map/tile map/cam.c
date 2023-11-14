#include "cam.h"
#include "tools.h"
#include "SFML/Graphics.h"
#include "map.h"

sfView* cam;
sfVector2f camrect = {640 ,360 };


void initCam()
{
	cam = sfView_create();
	sfView_setSize(cam ,camrect);
}


void updateCam(sfVector2f _playerpos)
{
	sfView_setCenter(cam, _playerpos);
	
}

void displayCam(sfRenderWindow* _window, int _t)
{ 
	sfRenderWindow_setView(_window, cam); 
	displayMap(_window, _t, cam);
}

void godlink()
{
	camrect.x = 3840;
	camrect.y = 2160;
	sfView_setSize(cam, camrect);
}

void nogodlink()
{
	camrect.x = 640;
	camrect.y = 360;
	sfView_setSize(cam, camrect);
}
