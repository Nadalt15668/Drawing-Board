#pragma once
#define _USE_MATH_DEFINES
#include <conio.h>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Constants.h"

using namespace sf;
using namespace std;

class Brush
{
public:
	Brush();
	float CalculateLength();
	float CalculateAngle();
	void ResetPositions();
	void NewPosition(Vector2f newPos);
	Vector2f prevPos;
	Vector2f curPos;
};

