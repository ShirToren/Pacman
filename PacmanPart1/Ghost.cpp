#include "ghost.h"



void Ghost::moveCreature(const Board& b, Position& pacmanPos, Mode mode)
{

	strategy->moveInStrategy(b, *this, pacmanPos);

}
void Ghost::setStrategy(Level level)
{
	switch (level)
	{
	case Level::SMART:
		strategy = new Smart;
		break;
	case Level::GOOD:
		strategy = new Good;
		break;
	case Level::NOVICE:
		strategy = new Novice;
		break;

	}
}
