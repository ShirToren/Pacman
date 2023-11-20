#pragma once
#include "Novice.h"
#include "Smart.h"

class Good: public Novice, public Smart
{
private:
	int countSteps = 0;
	bool flag = true;
	Direction dir = Direction::STOP;
public:
	~Good()override {};
	void moveInStrategy(const Board& b, GameCreature& creature, const Position& pacmanPos);

};

