#pragma once
#include <SFML/Graphics/Types.h>

void initCam();

void updateCam(_playerpos);

sfView* cam;

void displayCam(sfRenderWindow* _window);
void EditorMod_cam();
void GameMod_cam();