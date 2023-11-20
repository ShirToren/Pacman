#pragma once
#include "Util.h"


class Position
{
private:
	int x, y;

public:
	//C'tor
	Position(int _x = 0, int _y = 0) :x(_x), y(_y) {};
	bool operator==(const Position& p)const;
	bool operator!=(const Position& p)const;

	// Set
	void setX(int _x = 0)
	{
		x = _x;
	};
	void setY(int _y = 0)
	{
		y = _y;
	};
	void setPosition(int _x, int _y)
	{
		x = _x;
		y = _y;
	};

	// Get
	int getX() const
	{
		return x;
	};
	int getY() const
	{
		return y;
	};

};

