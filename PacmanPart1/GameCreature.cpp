#include "GameCreature.h"

void GameCreature::initPos()
{
	pos = firstPos;
	
}
void GameCreature::printCreatureMove()
{
	goToCreature();
	color.setConsulColor(Game_colors::CREATURECOLOR);
	cout << objSign;
	color.setConsulColor(Game_colors::WHITE);
}
bool checkIfTunnel(const Position& pos, const Board& b) {
	return (pos.getY() == BORDER || pos.getY() >= b.getCols() || pos.getX() == BORDER || pos.getX() >= b.getRows());
}
void GameCreature::move(const Board& b)
{
	Position nextPos = pos;

	switch (direction)
	{
	case Direction::RIGHT:
		nextPos.setY(pos.getY() + 1);
		break;
	case Direction::LEFT:
		nextPos.setY(pos.getY() - 1);
		break;
	case Direction::DOWN:
		nextPos.setX(pos.getX() + 1);
		break;
	case Direction::UP:
		nextPos.setX(pos.getX() - 1);
		break;
	}

	if (!b.isWall(nextPos))
		pos.setPosition(nextPos.getX(), nextPos.getY());
	else
		direction = Direction::STOP;
}
void GameCreature::pacmanLoadMove(const Board& b, char ch,Mode mode)
{
	Direction dir = charToDir(ch);
	direction = dir;
	if (mode == Mode::LOAD)
	{
		goToCreature();
		cout << b.get(pos);
	}

	Position currPos = getPos();
	bool flag = false;
	switch (dir)
	{
	case Direction::LEFT:
		if (currPos.getY() == 0)
		{
			pos.setY(b.getCols() - 1);
		}
		else
			pos.setY(pos.getY() - 1);
		break;
	case Direction::RIGHT:
		if (currPos.getY() == b.getCols() - 1)
			pos.setY(0);
		else
			pos.setY(pos.getY() + 1);
		break;
	case Direction::UP:
		if (currPos.getX() == 0)
		{
			pos.setX(b.getRows() - 1);
		}
		else
			pos.setX(pos.getX() - 1);
		break;
	case Direction::DOWN:
		if (currPos.getX() == b.getRows() - 1)
		{
			pos.setX(0);
		}
		else
			pos.setX(pos.getX() + 1);
		break;
	}
	if (mode == Mode::LOAD)
		printCreatureMove();

}
void GameCreature::creatursLoadMove(const Board & b,char ch,Mode mode)
{
	Direction dir = charToDir(ch);
	if (mode == Mode::LOAD)
	{
		goToCreature();
		cout << b.get(pos);
	}
	switch (dir)
	{
	case Direction::RIGHT:
		pos.setY(pos.getY() + 1);
		break;
	case Direction::LEFT:
		pos.setY(pos.getY() - 1);
		break;
	case Direction::DOWN:
		pos.setX(pos.getX() + 1);
		break;
	case Direction::UP:
		pos.setX(pos.getX() - 1);
		break;
	}
	if (mode == Mode::LOAD)
		printCreatureMove();
}
Direction GameCreature:: charToDir(char dir)
{
	switch (dir)
	{
	case 'D':
		return Direction::RIGHT;
	case 'W':
		return Direction::UP;
	case 'S':
		return Direction::STOP;
	case'A':
		return Direction::LEFT;
	case 'X':
		return Direction::DOWN;
	}
}
