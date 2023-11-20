#pragma once
#include "ghost.h"
#include "GameCreature.h"
#include "Board.h"


class Board;
class Pacman : public GameCreature
{

private:

	int score, currLive, prevLive;
	int countPoint = 0;
	
public:

	//C'tor
	Pacman() : GameCreature(Direction::STOP, (0, 0), (0, 0), Game_colors::LIGHTYELLOW, 'C'), score(0), prevLive(3), currLive(3) { };
	Pacman(Position& firstPos) : GameCreature(Direction::STOP, firstPos, firstPos, Game_colors::LIGHTYELLOW, 'C'), score(0), prevLive(3), currLive(3) { };

	virtual void moveCreature(const Board& b, Position& pacmanPos, Mode mode);

	/*Get*/
	int getScore()const
	{
		return score;
	}
	int getLive()const
	{
		return currLive;
	}
	int getPoint()const
	{
		return countPoint;
	}

	/*Set*/
	void setScore(int _score)
	{
		score = _score;
	}
	void setPoint(int _point)
	{
		countPoint = _point;
	}

	void addScore(int num)
	{
		score += num;
	}
	void addPoint()
	{
		++countPoint;
	}
	void takeLive()
	{
		currLive--;
	}


	bool pacmanLostLive();    /*returns true when the pacman touched a ghost and lost 1 live*/
	void initPacmanValues();    /*when the game finished*/
	bool isMoving(Position& nextPos,const Board& b); /*if next pos is valid, returns true and set the new pos */
};

