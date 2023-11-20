#pragma once
#include<queue>
#include "MoveStrategy.h"

struct Node {
	Position pt;
	int dist;
}; 

class Smart : virtual public MoveStrategy
{


public:
	~Smart()override {};
	virtual void moveInStrategy(const Board& b, GameCreature& creature, const Position& pacmanPos);


	string pathMoves(const Board& b, const Position& src, const Position& dest)const;
	bool isValid(int row, int col)const
	{
		return (row >= 0) && (col >= 0)
			&& (row < MAX_ROW_SIZE) && (col < MAX_COL_SIZE);
	}
	void smartMoving(const Board& b, GameCreature& creature, const Position& pacmanPos);

};

