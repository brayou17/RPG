#include "menu.h"
#include "SFML/Graphics.h"

#define TEXTURE_PATH "../Ressources/Textures/"

void initMenu()
{
	sfVector2f possMenu = { 340.0f, 340.0f };
	sfSprite* Logo;
	sfSprite* Bouton_Jouer;
	sfSprite* Bouton_Editeur;
	sfSprite* Bouton_Quitter;

	sfTexture* LogoTexture;
	sfTexture* Bouton_JouerTexture;
	sfTexture* Bouton_EditeurTexture;
	sfTexture* Bouton_QuitterTexture;

	Logo = sfSprite_create();
	Bouton_Jouer = sfSprite_create();
	Bouton_Editeur = sfSprite_create();
	Bouton_Quitter = sfSprite_create();

	LogoTexture = sfTexture_createFromFile(TEXTURE_PATH"Logo.png", NULL);
	Bouton_JouerTexture = sfTexture_createFromFile(TEXTURE_PATH"Bouton_Jouer.png", NULL);
	Bouton_EditeurTexture = sfTexture_createFromFile(TEXTURE_PATH"Bouton_Editeur.png", NULL);
	Bouton_QuitterTexture = sfTexture_createFromFile(TEXTURE_PATH"bouton_Quitter.png", NULL);

	sfSprite_setTexture(Logo, LogoTexture, sfTrue);
	sfSprite_setTexture(Bouton_Jouer, Bouton_JouerTexture, sfTrue);
	sfSprite_setTexture(Bouton_Editeur, Bouton_EditeurTexture, sfTrue);
	sfSprite_setTexture(Bouton_Quitter, Bouton_QuitterTexture, sfTrue);

}

void updateMenu()
{

}

void DisplayMenu(sfRenderWindow* _window)
{

}

void DestroyMenu()
{

}
