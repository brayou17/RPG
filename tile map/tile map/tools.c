#include "tools.h"

sfTime sftime;
sfClock* sfclock;



void initTools()
{
	sfclock = sfClock_create();
	srand(time(NULL));
}

float GetDeltaTime()
{
	return sfTime_asSeconds(sftime);
}

sfVector2f vector2f(float _x, float _y)
{
	sfVector2f tmp = { _x, _y };
	return tmp;
}


void restartClock()
{
	sftime = sfClock_restart(sfclock);
}
