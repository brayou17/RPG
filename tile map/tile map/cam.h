#pragma once
#include <SFML/Graphics/Types.h>

void initCam();

void updateCam(_playerpos);

void displayCam(sfRenderWindow* _window, int _animCoffre);
void EditorMod_cam();
void GameMod_cam();