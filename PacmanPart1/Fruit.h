#pragma once
#include "GameCreature.h"
#include "Ghost.h"
#include "Novice.h"
#include "Files.h"



class Fruit : public GameCreature
{
private:
	int countPace = 0;
	bool flag = false;
	Novice strategy;


public:
	//C'tor
	Fruit(Board& b, Position& pacmanPos, vector<Ghost>& ghosts, bool colorFul);
	Fruit(Files& gameFile, int numOfFruit, bool colorFul);
	Fruit() {

		setColor(Game_colors::GREEN);
	};
	~Fruit()override {};

	virtual void  moveCreature(const Board& b, Position& pacmanPos, Mode mode);
	bool checkGhosts(Position& pos, vector<Ghost>& ghosts); /*checks that the random position is not on the ghosts*/
	bool checkStatus(const Position& pos, Board& b);/*checks that the random position is not on the key*/
	Direction direction(int dir)const;
	
	
};

