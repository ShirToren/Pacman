#include "Good.h"

void Good::moveInStrategy(const Board& b, GameCreature& creature, const Position& pacmanPos)
{
	if (countSteps >= GOOD_STEPS)
	{
		if (flag)
		{
			randomDirection(b, creature.getDirection());
			flag = false;
		}
		noviceMoving(b, creature, pacmanPos);
		countSteps++;

		if (countSteps == (GOOD_STEPS +5))
		{
			countSteps = 0;
			flag = !flag;
		}
	}
	else
	{
		smartMoving(b, creature, pacmanPos);
		countSteps++;
	}
	

}