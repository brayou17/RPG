#include "menu.h"
#include "SFML/Graphics.h"

#define TEXTURE_PATH "../Ressources/Textures/"

sfVector2f poslogo = { -10.f, -170.0f };
sfVector2f posjouer = { 300.f, 270.f };
sfVector2f posedit = { 340.0f, 340.0f };
sfVector2f posquit = { 340.0f, 400.0f };
sfVector2f posbackground = { -150.0f,0.0f };
sfVector2f scaleback = { 0.185f,0.185f };
sfVector2f scalelogo = { 0.185f,0.185f };
sfVector2f scalejouer = { 0.5f,0.5f };
sfFloatRect rectjouer;
sfVector2i mousepos;

sfSprite* Logo;
sfSprite* Background;
sfSprite* Bouton_Jouer;
sfSprite* Bouton_Editeur;
sfSprite* Bouton_Quitter;

sfTexture* LogoTexture;
sfTexture* Bouton_JouerTexture;
sfTexture* Bouton_EditeurTexture;
sfTexture* Bouton_QuitterTexture;
sfTexture* Background_Texture;




void initMenu()
{

	Logo = sfSprite_create();
	Bouton_Jouer = sfSprite_create();
	Bouton_Editeur = sfSprite_create();
	Bouton_Quitter = sfSprite_create();
	Background = sfSprite_create();

	LogoTexture = sfTexture_createFromFile(TEXTURE_PATH"logolinkquest.png", NULL);
	Bouton_JouerTexture = sfTexture_createFromFile(TEXTURE_PATH"Jouer.png", NULL);
	Bouton_EditeurTexture = sfTexture_createFromFile(TEXTURE_PATH"EDITER.png", NULL);
	Bouton_QuitterTexture = sfTexture_createFromFile(TEXTURE_PATH"QUITTER.png", NULL);
	Background_Texture = sfTexture_createFromFile(TEXTURE_PATH"background2.jpg", NULL);

	sfSprite_setTexture(Logo, LogoTexture, sfTrue);
	sfSprite_setTexture(Bouton_Jouer, Bouton_JouerTexture, sfTrue);
	sfSprite_setTexture(Bouton_Editeur, Bouton_EditeurTexture, sfTrue);
	sfSprite_setTexture(Bouton_Quitter, Bouton_QuitterTexture, sfTrue);
	sfSprite_setTexture(Background, Background_Texture, sfTrue);


	sfSprite_setOrigin(Bouton_Jouer, vector2f(sfSprite_getGlobalBounds(Bouton_Jouer).width / 2, sfSprite_getGlobalBounds(Bouton_Jouer).height / 2));

	sfSprite_setPosition(Logo, poslogo);
	sfSprite_setPosition(Bouton_Jouer, posjouer);
	sfSprite_setPosition(Bouton_Editeur, posedit);
	sfSprite_setPosition(Bouton_Quitter, posquit);
	sfSprite_setPosition(Background, posbackground);
	sfSprite_setScale(Background, scaleback);
	sfSprite_setScale(Bouton_Jouer, scalejouer);

	rectjouer = sfSprite_getGlobalBounds(Bouton_Jouer);

}
float direction_logo = 1;
void updateMenu(sfRenderWindow* _window)
{
	poslogo.y += direction_logo;
	if (poslogo.y > -160.0f) direction_logo = -0.003f;
	if (poslogo.y < -170.0f) direction_logo = 0.003f;


	mousepos = sfMouse_getPositionRenderWindow(_window);

	

	if (sfFloatRect_contains(&rectjouer, mousepos.x, mousepos.y))
	{
		sfSprite_setColor(Bouton_Jouer, sfColor_fromRGBA(255, 255, 255, 200));
		if (sfMouse_isButtonPressed(sfMouseLeft))
		{
			actualState = JOUER;
		}
	}
	else
	{
		sfSprite_setColor(Bouton_Jouer, sfColor_fromRGBA(255, 255, 255, 255));
	}
	
	

}

void DisplayMenu(sfRenderWindow* _window)
{
	sfRenderWindow_drawSprite(_window, Background, NULL);
	sfRenderWindow_drawSprite(_window, Logo, NULL);
	sfRenderWindow_drawSprite(_window, Bouton_Jouer, NULL);
	sfRenderWindow_drawSprite(_window, Bouton_Editeur, NULL);
	sfRenderWindow_drawSprite(_window, Bouton_Quitter, NULL);
	

}
