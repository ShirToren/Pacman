#pragma once
#include "Util.h"


enum class Game_colors { BLUE=1 , GREEN, AQUA, RED, PURPLE, WHITE, LIGHTBLUE, LIGHTGREEN, LIGHTAQUA, LIGHTYELLOW, LIGHTPURPLE, BRIGHTWHITE, CREATURECOLOR };

class Color
{
private:

	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	bool isColorFul;
	Game_colors color;

public:
	//C'tor
	Color(Game_colors _color = Game_colors::WHITE, bool _colorful = false) :color(_color), isColorFul(_colorful) {};

	//Set
	void setColorFul(bool _colorFul)
	{
		isColorFul = _colorFul;
	}
	void setColor(Game_colors _color)
	{
		color = _color;
	}

	//Get
	bool getColorful()const
	{
		return isColorFul;
	}

	void setConsulColor(Game_colors _color);
};