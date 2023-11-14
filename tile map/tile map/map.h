#pragma once
#include"SFML/Graphics.h"
#include"tools.h"
#include"player.h"

sfSprite* chest;
sfTexture* chesttexture;
sfIntRect chestrect[4];
sfVector2f chestpos;


void initMap();

sfBool collision(sfFloatRect _sprite, Direction _direction, sfVector2f _vitesse);

void displayMap(sfRenderWindow* _window, int _t, sfView* _cam);
