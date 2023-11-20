#include "Pacman.h"

bool Pacman::pacmanLostLive()
{
	if (currLive < prevLive)
	{
		prevLive--;
		return true;
	}
	return false;
}
void Pacman::initPacmanValues()
{
	score = 0;
	currLive = 3;
	prevLive = 3;
}

void Pacman::moveCreature(const Board& b, Position& pacmanPos, Mode mode)
{
	Position currPos = getPos();
	Position nextPos = currPos;
	bool flag = false;

	switch (getDirection())
	{
	case Direction::LEFT:
		if (currPos.getY() == 0)
		{
			nextPos.setY(b.getCols() - 1);
			flag = isMoving(nextPos, b);	
		}
		break;
	case Direction::RIGHT:
		if (currPos.getY() == b.getCols()-1)
		{
			nextPos.setY(0);
			flag = isMoving(nextPos, b);

		}
		break;
	case Direction::UP:
		if (currPos.getX() == 0)
		{
			nextPos.setX(b.getRows() - 1);
			flag = isMoving(nextPos, b);

		}
		break;
	case Direction::DOWN:
		if (currPos.getX() == b.getRows()-1)
		{
			nextPos.setX(0);
			flag = isMoving(nextPos, b);
		}
		break;
	}

	if(!flag)
	move(b);

}
bool Pacman::isMoving(Position& nextPos, const Board& b)
{
	if (b.isWall(nextPos))
	{
		setDirection(Direction::STOP);
		return false;
	}
		
	else
	{
		setPos(nextPos);
		return true;
	}
}

