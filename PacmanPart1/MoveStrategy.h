#pragma once
#include "Util.h"
#include "Position.h"
#include "Board.h"
#include "GameCreature.h"


class MoveStrategy
{
public:
	virtual ~MoveStrategy() {};
	virtual void moveInStrategy(const Board& b, GameCreature& creature, const Position& pacmanPos) = 0;
	void move(const Board& b, GameCreature& creature);

};

