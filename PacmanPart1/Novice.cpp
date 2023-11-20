#include "Novice.h"

void Novice::moveInStrategy(const Board& b, GameCreature& creature, const Position& pacmanPos)
{	
	noviceMoving(b, creature, pacmanPos);
}

Direction Novice::direction(int dir)const
{
	switch (dir)
	{
	case 1:
		return Direction::LEFT;
	case 2:
		return Direction::RIGHT;
	case 3:
		return Direction::UP;
	case 4:
		return Direction::DOWN;
	default:
		return Direction::STOP;
	}
}
void Novice::randomDirection(const Board& b, Direction& _direction)
{
	int dir = rand() % 4 + 1;
	_direction = direction(dir);
}

bool Novice::checkIfTunnel(const Position& pos, const Board& b) {
	return (pos.getY() == BORDER || pos.getY() >= b.getCols() || pos.getX() == BORDER || pos.getX() >= b.getRows());
}
void Novice::noviceMoving(const Board& b, GameCreature& creature, const Position& pacmanPos)
{
	if (creature.getDirection() == Direction::STOP)
	{
		randomDirection(b, creature.getDirection());
		countSteps = 0;
	}

	creature.goToCreature();
	cout << b.get(creature.getPos());

	Position temp = creature.getPos();

	bool firstIter = true;
	do {
		if (!firstIter) {
			creature.setPos(temp);
			randomDirection(b, creature.getDirection());
		}
		
		move(b, creature);
		firstIter = false;
	} while (temp == creature.getPos() || checkIfTunnel(creature.getPos(), b));
	
	creature.printCreatureMove();
	countSteps++;
}

