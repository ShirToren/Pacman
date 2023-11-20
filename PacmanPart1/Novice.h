#pragma once
#include "MoveStrategy.h"
#include "GameCreature.h"

class Novice : virtual public MoveStrategy
{
private:
	int countSteps = 0;
	bool flag = true;

public:
	Novice() {}
	
	~Novice()override {};

	virtual void moveInStrategy(const Board& b, GameCreature& creature, const Position& pacmanPos);
	bool checkIfTunnel(const Position& pos, const Board& b); /*novice creature can't travel by tunnels*/
	Direction direction(int dir)const;
	void randomDirection(const Board& b, Direction& _direction); /*sets creature's direction to a new random one*/
	void noviceMoving(const Board& b, GameCreature& creature, const Position& pacmanPos);

};

