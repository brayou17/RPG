#pragma once
#include "SFML/Graphics.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include"cam.h"


void initTools();
void restartClock();
float GetDeltaTime();

sfVector2f vector2f(float _x, float _y);
