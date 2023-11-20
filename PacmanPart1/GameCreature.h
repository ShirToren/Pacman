#pragma once
#include "Board.h"


class GameCreature
{
private:
	char objSign;
	Direction direction;
	Position firstPos;
	Position pos;
	Color color;

public:
	GameCreature(Direction _direction, Position _pos, Position _firstPos, Color _color, char _objSign = ' ') : direction(_direction), pos(_pos), firstPos(_firstPos), color(_color), objSign(_objSign){};
	GameCreature() : direction(Direction::STOP), firstPos(0, 0), pos(firstPos), color(Game_colors::WHITE), objSign(' ') {};
	virtual ~GameCreature() {};

	virtual void moveCreature(const Board& b, Position& pacmanPos, Mode mode) = 0;

	//Get
	Position& getPos()
	{
		return pos;
	}
	Direction& getDirection()
	{
		return direction;
	}
	char getObjSign()const
	{
		return objSign;
	}

	//Set
	void setPos(Position& _pos)
	{
		pos = _pos;
	}
	void setDirection(Direction _d)
	{
		direction = _d;
	}
	void setFirstPos(Position& pos)
	{
		firstPos = pos;
	}
	void setObjSign(char sign)
	{
		objSign = sign;
	}
	void setColorful(bool isColorful)
	{
		color.setColorFul(isColorful);
	}
	void setColor(Game_colors _color)
	{
		color.setColor(_color);
	}

	void move(const Board& b);
	/*going to the creature's position on the screen*/
	void goToCreature()const
	{
		gotoxy(pos.getX(), pos.getY());
	} 
	void initPos(); /*init creature's position to the first position and color*/
	void printCreatureMove();

	void creatursLoadMove(const Board& b, char ch, Mode mode);
	Direction charToDir(char dir);
	void pacmanLoadMove(const Board& b, char ch, Mode mode);
};

