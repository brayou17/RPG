#pragma once
#include <SFML/Graphics/Types.h>

void initCam();

void updateCam(_playerpos);

void displayCam(sfRenderWindow* _window, int _t);
void godlink();
void nogodlink();