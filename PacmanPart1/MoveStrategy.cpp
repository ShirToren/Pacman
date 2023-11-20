#include "MoveStrategy.h"

void MoveStrategy::move(const Board& b, GameCreature& creature)
{
	Position nextPos = creature.getPos();

	switch (creature.getDirection())
	{

	case Direction::RIGHT:
		nextPos.setY(creature.getPos().getY() + 1);
		break;
	case Direction::LEFT:
		nextPos.setY(creature.getPos().getY() - 1);
		break;
	case Direction::DOWN:
		nextPos.setX(creature.getPos().getX() + 1);
		break;
	case Direction::UP:
		nextPos.setX(creature.getPos().getX() - 1);
		break;
	}

	if (!b.isWall(nextPos))
		creature.setPos(nextPos);

}

