#include "Color.h"


void Color::setConsulColor(Game_colors _color)
{
	if (isColorFul)
	{
		if (_color == Game_colors::CREATURECOLOR) /*set consol by a certain creature*/
			_color = color;
		switch (_color)
		{
		case Game_colors::BLUE:
			SetConsoleTextAttribute(h, 0x01);
			break;
		case Game_colors::WHITE:
			SetConsoleTextAttribute(h, 0x0f);
			break;
		case Game_colors::RED:
			SetConsoleTextAttribute(h, 0x04);
			break;
		case Game_colors::GREEN:
			SetConsoleTextAttribute(h, 0x02);
			break;
		case Game_colors::AQUA:
			SetConsoleTextAttribute(h, 0x03);
			break;
		case Game_colors::PURPLE:
			SetConsoleTextAttribute(h, 0x05);
			break;
		case Game_colors::LIGHTBLUE:
			SetConsoleTextAttribute(h, 0x09);
			break;
		case Game_colors::LIGHTGREEN:
			SetConsoleTextAttribute(h, 0x0a);
			break;
		case Game_colors::LIGHTYELLOW:
			SetConsoleTextAttribute(h, 0x0e);
			break;
		case Game_colors::LIGHTAQUA:
			SetConsoleTextAttribute(h, 0x0b);
			break;
		case Game_colors::LIGHTPURPLE:
			SetConsoleTextAttribute(h, 0x0d);
			break;
		case Game_colors::BRIGHTWHITE:
			SetConsoleTextAttribute(h, 0x0f);
			break;

		default:
			SetConsoleTextAttribute(h, 0x07);
		}
	}
}