#include "map.h"
#include "tools.h"
#include "player.h"
#define TEXTURE_PATH "../Ressources/Textures/"


sfIntRect chestrect[4] = { {0, 0, 32 ,32},{32, 0, 32 ,32},{64, 0, 32 ,32},{96, 0, 32 ,32} };
sfVector2f chestpos = { 0.0f ,0.0f };

sfSprite* tileSprite;

sfTexture* tileTexture;

sfIntRect tileRect;
sfVector2f position = { 0.0f ,0.0f };
sfVector2i Tposition = { 0 ,0 };
int ntile;

FILE* fichier;

char map[60][200];

void initMap()
{
	/*for (int y = 0; y < 60; y++)
	{
		for (int x = 0; x < 200; x++)
		{
			 if (y == 0)
			{
	 			map[y][x] == 3;
			}
 			if (x == 0)
 			 {
	 			 map[y][x] == 3;
	 		}
			else if (x == 199)
	 		{
	 			map[y][x] == 3;
			}
	 		else if (y == 199)
			{
		 		map[y][x] == 3;
			}
			else 
			 {
				map[y][x] =  rand() % 11;
			 }
		}
	}*/

	fichier = fopen("MAP.bin", "r");
	fread(map, sizeof(char), 12000, fichier);
	fclose(fichier);


 	
	chesttexture = sfTexture_createFromFile(TEXTURE_PATH"coffre32.png", NULL);
	chest = sfSprite_create();
	sfSprite_setTexture(chest, chesttexture, sfTrue);
	

	tileTexture = sfTexture_createFromFile(TEXTURE_PATH"tileset.png", NULL);
	tileSprite = sfSprite_create();
	sfSprite_setTexture(tileSprite, tileTexture, sfTrue);
	tileRect.left = 32;
	tileRect.top = 0;
	tileRect.width = 32;
	tileRect.height = 32;
}
float timer2 = 0;
int i = 0;
sfBool updateMap(sfFloatRect _sprite, Direction _direction, sfVector2f _vitesse)
{
	
	sfVector2i fpos;
	sfVector2i fpos2;
	if (i == 0)
	{ 
		switch (_direction)
		{

		case HAUT:
			fpos.y = (_sprite.top - 2 + _vitesse.y * GetDeltaTime()) / 32;
			fpos.x = (_sprite.left + _vitesse.x * GetDeltaTime()) / 32;
			fpos2.y = (_sprite.top - 2 + _vitesse.y * GetDeltaTime()) / 32;
			fpos2.x = (_sprite.width + _sprite.left + _vitesse.x * GetDeltaTime()) / 32;
			if ((map[fpos.y][fpos.x] < 6 && map[fpos.y][fpos.x] >2) || (map[fpos2.y][fpos2.x] == 9 || map[fpos.y][fpos.x] == 9))
			{
				return sfTrue;
			}
			else if (map[fpos.y][fpos.x] == 2 || map[fpos2.y][fpos2.x] == 2)
			{
				return sfTrue + 1;
			}
			else return sfFalse;
			break;
		case BAS:
			fpos.y = (_sprite.top + _sprite.height + 2 + _vitesse.y * GetDeltaTime()) / 32;
			fpos.x = (_sprite.left + _vitesse.x * GetDeltaTime()) / 32;
			fpos2.y = (_sprite.top + _sprite.height + 2 + _vitesse.y * GetDeltaTime()) / 32;
			fpos2.x = (_sprite.left + _sprite.width + _vitesse.x * GetDeltaTime()) / 32;
			if ((map[fpos.y][fpos.x] < 6 && map[fpos.y][fpos.x] >2) || (map[fpos2.y][fpos2.x] < 6 && map[fpos2.y][fpos2.x] > 2) || (map[fpos2.y][fpos2.x] == 7 || map[fpos.y][fpos.x] == 7))
			{
				return sfTrue;
			}
			else if (map[fpos.y][fpos.x] == 2 || map[fpos2.y][fpos2.x] == 2)
			{
				return sfTrue + 1;
			}
			else return sfFalse;
			break;
		case DROITE:
			fpos.y = (_sprite.top + _vitesse.y * GetDeltaTime()) / 32;
			fpos.x = (_sprite.left + _sprite.width + 2 + _vitesse.x * GetDeltaTime()) / 32;
			fpos2.y = (_sprite.top + _sprite.height + _vitesse.y * GetDeltaTime()) / 32;
			fpos2.x = (_sprite.left + _sprite.width + 2 + _vitesse.x * GetDeltaTime()) / 32;
			if ((map[fpos.y][fpos.x] < 6 && map[fpos.y][fpos.x] >2) || (map[fpos2.y][fpos2.x] < 6 && map[fpos2.y][fpos2.x] > 2) || (map[fpos2.y][fpos2.x] == 10 || map[fpos.y][fpos.x] == 10))
			{
				return sfTrue;
			}
			else if (map[fpos.y][fpos.x] == 2 || map[fpos2.y][fpos2.x] == 2)
			{
				return sfTrue + 1;
			}
			else return sfFalse;

			break;
		case GAUCHE:
			fpos.y = (_sprite.top + _sprite.height + _vitesse.y * GetDeltaTime()) / 32;
			fpos.x = (_sprite.left - 2 + _vitesse.x * GetDeltaTime()) / 32;
			fpos2.y = (_sprite.top + _vitesse.y * GetDeltaTime()) / 32;
			fpos2.x = (_sprite.left - 2 + _vitesse.x * GetDeltaTime()) / 32;
			if ((map[fpos.y][fpos.x] < 6 && map[fpos.y][fpos.x] >2) || (map[fpos2.y][fpos2.x] < 6 && map[fpos2.y][fpos2.x] > 2) || (map[fpos2.y][fpos2.x] == 8 || map[fpos.y][fpos.x] == 8))
			{
				return sfTrue;
			}
			else if (map[fpos.y][fpos.x] == 2 || map[fpos2.y][fpos2.x] == 2)
			{
				return sfTrue + 1;
			}
			else return sfFalse;
			break;
		}
	
	}
	if (i == 1)
	{
		return sfFalse;
	}

}


float timer = 0.0f;
int up = 0;

void displayMap(sfRenderWindow * _window, int _t, sfView * _cam)
{
	timer2 += GetDeltaTime();
	if (sfKeyboard_isKeyPressed(sfKeySpace) && timer2 > 0.3f)
	{
		timer2 = 0;
		i++;
		if (i > 1)
			i = 0;
		if (i == 1)
		{

			godlink2();
			godlink();
		}
		if (i == 0)
		{
			nogodlink2();
			nogodlink();
		}

	}
 	sfVector2i mousePosition;
	sfVector2i pixelPos = sfMouse_getPositionRenderWindow(_window);
	sfVector2f worldPos = sfRenderWindow_mapPixelToCoords(_window, pixelPos, _cam);
	mousePosition = sfMouse_getPosition(_window);
	Tposition.x = (float)worldPos.x/32 ;
	Tposition.y = (float)worldPos.y/32 ;
	timer += GetDeltaTime();
	if (i == 1)
	{
		sfRenderWindow_setMouseCursorVisible(_window, sfTrue);
	 	if (mousePosition.x < 1920 && mousePosition.y < 1080 && mousePosition.x>0 && mousePosition.y>0)
		{
			if (sfMouse_isButtonPressed(sfMouseLeft))
			{
				if (up == 0)
				{
					map[Tposition.y][Tposition.x] = ntile;
				}
				if (up == 1)
				{
					map[Tposition.y+1][Tposition.x] = ntile;
				 	map[Tposition.y-1][Tposition.x] = ntile;
		 			map[Tposition.y][Tposition.x+1] = ntile;
	 				map[Tposition.y][Tposition.x-1] = ntile;
		 			map[Tposition.y+1][Tposition.x+1] = ntile;
		 			map[Tposition.y+1][Tposition.x-1] = ntile;
		 			map[Tposition.y-1][Tposition.x+1] = ntile;
					map[Tposition.y-1][Tposition.x-1] = ntile;
		 			map[Tposition.y][Tposition.x] = ntile;
				}
			}
		}
		if (sfMouse_isButtonPressed(sfMouseRight) && timer > 0.3f)
		{
			timer = 0.0f;
			ntile++;
			if (ntile > 15)
				ntile = 0;
		}
		if (sfKeyboard_isKeyPressed(sfKeyI) && timer > 1)
		{
			timer = 0.0f;
			up = (1 + up) % 2;
		}
 	  	if (sfKeyboard_isKeyPressed(sfKeyM) && timer > 1)
		{

	 		fichier = fopen("MAP.bin", "w");
 			fwrite(map, sizeof(char), 12000, fichier);
 			fclose(fichier);

			/*timer = 0.0f;
			for (int y = 0; y < 60; y++)
			{
				for (int x = 0; x < 200; x++)
				{
					if (x == 0)
					{
						printf("{%d,", map[y][x]);
					}
					else if (x == 199)
					{
						printf("%d},\n", map[y][x]);
					}
					else {
						printf("%d,", map[y][x]);
					}
				}

			}*/
		}
	}
	if (i == 0)
	{
		sfRenderWindow_setMouseCursorVisible(_window, sfFalse);
	}
	for (int y = 0; y < 60; y++)
	{
		for (int x = 0; x < 200; x++)
		{
			switch (map[y][x])
			{
			case 0:
				tileRect.left = 32;
				position.x = x * 32;
				position.y = y * 32;
				sfSprite_setPosition(tileSprite, position);
				sfSprite_setTextureRect(tileSprite, tileRect);
				sfRenderWindow_drawSprite(_window, tileSprite, NULL);
				break;
			case 1:
				tileRect.left = 64;
				position.x = x * 32;
				position.y = y * 32;
				sfSprite_setPosition(tileSprite, position);
				sfSprite_setTextureRect(tileSprite, tileRect);
				sfRenderWindow_drawSprite(_window, tileSprite, NULL);
				break;
			case 2:
				tileRect.left = 96;
				position.x = x * 32;
				position.y = y * 32;
				sfSprite_setPosition(tileSprite, position);
				sfSprite_setTextureRect(tileSprite, tileRect);
				sfRenderWindow_drawSprite(_window, tileSprite, NULL);
				break;
			case 3:
				tileRect.left = 128;
				position.x = x * 32;
				position.y = y * 32;
				sfSprite_setPosition(tileSprite, position);
				sfSprite_setTextureRect(tileSprite, tileRect);
				sfRenderWindow_drawSprite(_window, tileSprite, NULL);
				break;
			case 4:
				tileRect.left = 160;
				position.x = x * 32;
				position.y = y * 32;
				sfSprite_setPosition(tileSprite, position);
				sfSprite_setTextureRect(tileSprite, tileRect);
				sfRenderWindow_drawSprite(_window, tileSprite, NULL);
				break;
			case 5:
				chestpos.x = x * 32;
				chestpos.y = y * 32;
				sfSprite_setPosition(chest, chestpos);
				sfSprite_setTextureRect(chest, chestrect[_t]);
				sfRenderWindow_drawSprite(_window, chest, NULL);
				break;
			case 6:
				tileRect.left = 32*7;
				position.x = x * 32;
				position.y = y * 32;
				sfSprite_setPosition(tileSprite, position);
				sfSprite_setTextureRect(tileSprite, tileRect);
				sfRenderWindow_drawSprite(_window, tileSprite, NULL);
				break;
			case 7:
				tileRect.left = 32 * 8;
				position.x = x * 32;
				position.y = y * 32;
				sfSprite_setPosition(tileSprite, position);
				sfSprite_setTextureRect(tileSprite, tileRect);
				sfRenderWindow_drawSprite(_window, tileSprite, NULL);
				break;
			case 8:
				tileRect.left = 32 * 9;
				position.x = x * 32;
				position.y = y * 32;
				sfSprite_setPosition(tileSprite, position);
				sfSprite_setTextureRect(tileSprite, tileRect);
				sfRenderWindow_drawSprite(_window, tileSprite, NULL);
				break;
			case 9:
				tileRect.left = 32 * 10;
				position.x = x * 32;
				position.y = y * 32;
				sfSprite_setPosition(tileSprite, position);
				sfSprite_setTextureRect(tileSprite, tileRect);
				sfRenderWindow_drawSprite(_window, tileSprite, NULL);
				break;
			case 10:
				tileRect.left = 32 * 11;
				position.x = x * 32;
				position.y = y * 32;
				sfSprite_setPosition(tileSprite, position);
				sfSprite_setTextureRect(tileSprite, tileRect);
				sfRenderWindow_drawSprite(_window, tileSprite, NULL);
				break;
			case 11:
				tileRect.left = 32 * 12;
				position.x = x * 32;
				position.y = y * 32;
				sfSprite_setPosition(tileSprite, position);
				sfSprite_setTextureRect(tileSprite, tileRect);
				sfRenderWindow_drawSprite(_window, tileSprite, NULL);
				break;
			case 12:
				tileRect.left = 32 * 13;
				position.x = x * 32;
				position.y = y * 32;
				sfSprite_setPosition(tileSprite, position);
				sfSprite_setTextureRect(tileSprite, tileRect);
				sfRenderWindow_drawSprite(_window, tileSprite, NULL);
				break;
			case 13:
				tileRect.left = 32 * 14;
				position.x = x * 32;
				position.y = y * 32;
				sfSprite_setPosition(tileSprite, position);
				sfSprite_setTextureRect(tileSprite, tileRect);
				sfRenderWindow_drawSprite(_window, tileSprite, NULL);
				break;
			case 14:
				tileRect.left = 32 * 15;
				position.x = x * 32;
				position.y = y * 32;
				sfSprite_setPosition(tileSprite, position);
				sfSprite_setTextureRect(tileSprite, tileRect);
				sfRenderWindow_drawSprite(_window, tileSprite, NULL);
				break;
			case 15:
				tileRect.left = 32 * 16;
				position.x = x * 32;
				position.y = y * 32;
				sfSprite_setPosition(tileSprite, position);
				sfSprite_setTextureRect(tileSprite, tileRect);
				sfRenderWindow_drawSprite(_window, tileSprite, NULL);
				break;
			}
		}
	}
	if (i == 1)
	{
		switch (ntile)
		{
		case 0:
			tileRect.left = 32;
			position.x = worldPos.x;
			position.y = worldPos.y;
			sfSprite_setPosition(tileSprite, position);
			sfSprite_setTextureRect(tileSprite, tileRect);
			sfRenderWindow_drawSprite(_window, tileSprite, NULL);
			break;
		case 1:
			tileRect.left = 32 * 2;
			position.x = worldPos.x;
			position.y = worldPos.y;
			sfSprite_setPosition(tileSprite, position);
			sfSprite_setTextureRect(tileSprite, tileRect);
			sfRenderWindow_drawSprite(_window, tileSprite, NULL);
			break;
		case 2:
			tileRect.left = 32 * 3;
			position.x = worldPos.x;
			position.y = worldPos.y;
			sfSprite_setPosition(tileSprite, position);
			sfSprite_setTextureRect(tileSprite, tileRect);
			sfRenderWindow_drawSprite(_window, tileSprite, NULL);
			break;
		case 3:
			tileRect.left = 32 * 4;
			position.x = worldPos.x;
			position.y = worldPos.y;
			sfSprite_setPosition(tileSprite, position);
			sfSprite_setTextureRect(tileSprite, tileRect);
			sfRenderWindow_drawSprite(_window, tileSprite, NULL);
			break;
		case 4:
			tileRect.left = 32 * 5;
			position.x = worldPos.x;
			position.y = worldPos.y;
			sfSprite_setPosition(tileSprite, position);
			sfSprite_setTextureRect(tileSprite, tileRect);
			sfRenderWindow_drawSprite(_window, tileSprite, NULL);
			break;
		case 5:
			tileRect.left = 32 * 6;
			position.x = worldPos.x;
			position.y = worldPos.y;
			sfSprite_setPosition(tileSprite, position);
			sfSprite_setTextureRect(tileSprite, tileRect);
			sfRenderWindow_drawSprite(_window, tileSprite, NULL);
			break;
		case 6:
			tileRect.left = 32 * 7;
			position.x = worldPos.x;
			position.y = worldPos.y;
			sfSprite_setPosition(tileSprite, position);
			sfSprite_setTextureRect(tileSprite, tileRect);
			sfRenderWindow_drawSprite(_window, tileSprite, NULL);
			break;
		case 7:
			tileRect.left = 32 * 8;
			position.x = worldPos.x;
			position.y = worldPos.y;
			sfSprite_setPosition(tileSprite, position);
			sfSprite_setTextureRect(tileSprite, tileRect);
			sfRenderWindow_drawSprite(_window, tileSprite, NULL);
			break;
		case 8:
			tileRect.left = 32 * 9;
			position.x = worldPos.x;
			position.y = worldPos.y;
			sfSprite_setPosition(tileSprite, position);
			sfSprite_setTextureRect(tileSprite, tileRect);
			sfRenderWindow_drawSprite(_window, tileSprite, NULL);
			break;
		case 9:
			tileRect.left = 32 * 10;
			position.x = worldPos.x;
			position.y = worldPos.y;
			sfSprite_setPosition(tileSprite, position);
			sfSprite_setTextureRect(tileSprite, tileRect);
			sfRenderWindow_drawSprite(_window, tileSprite, NULL);
			break;
		case 10:
			tileRect.left = 32 * 11;
			position.x = worldPos.x;
			position.y = worldPos.y;
			sfSprite_setPosition(tileSprite, position);
			sfSprite_setTextureRect(tileSprite, tileRect);
			sfRenderWindow_drawSprite(_window, tileSprite, NULL);
			break;
		case 11:
			tileRect.left = 32 * 12;
			position.x = worldPos.x;
			position.y = worldPos.y;
			sfSprite_setPosition(tileSprite, position);
			sfSprite_setTextureRect(tileSprite, tileRect);
			sfRenderWindow_drawSprite(_window, tileSprite, NULL);
			break;
		case 12:
			tileRect.left = 32 * 13;
			position.x = worldPos.x;
			position.y = worldPos.y;
			sfSprite_setPosition(tileSprite, position);
			sfSprite_setTextureRect(tileSprite, tileRect);
			sfRenderWindow_drawSprite(_window, tileSprite, NULL);
			break;
		case 13:
			tileRect.left = 32 * 14;
			position.x = worldPos.x;
			position.y = worldPos.y;
			sfSprite_setPosition(tileSprite, position);
			sfSprite_setTextureRect(tileSprite, tileRect);
			sfRenderWindow_drawSprite(_window, tileSprite, NULL);
			break;
		case 14:
			tileRect.left = 32 * 15;
			position.x = worldPos.x;
			position.y = worldPos.y;
			sfSprite_setPosition(tileSprite, position);
			sfSprite_setTextureRect(tileSprite, tileRect);
			sfRenderWindow_drawSprite(_window, tileSprite, NULL);
			break;
		case 15:
			tileRect.left = 32 * 16;
			position.x = worldPos.x;
			position.y = worldPos.y;
			sfSprite_setPosition(tileSprite, position);
			sfSprite_setTextureRect(tileSprite, tileRect);
			sfRenderWindow_drawSprite(_window, tileSprite, NULL);
			break;
		}
	}





}

