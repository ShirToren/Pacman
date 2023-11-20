#include "Fruit.h"


Fruit::Fruit(Board& b, Position& pacmanPos, vector<Ghost>& ghosts, bool colorFul)
{
	Position pos;
	srand((unsigned int)time(NULL));
	char digit = (rand() % 5 + 5) + ZERO_CHAR;

	do {
		pos.setX(rand() % b.getRows());
		pos.setY(rand() % b.getCols());

	} while (b.isWall(pos) || checkStatus(pos,b)|| checkGhosts(pos, ghosts) || (pos == pacmanPos));

	Direction _direction = Direction::RIGHT;
	setDirection(_direction);
	setPos(pos);
	setFirstPos(pos);
	setObjSign(digit);
	setColorful(colorFul);
	setColor(Game_colors::GREEN);

}
Fruit::Fruit(Files& gameFile, int numOfFruit, bool colorFul)
{
	setPos(gameFile.getFruitPos());
	setFirstPos(gameFile.getFruitPos());
	setObjSign(gameFile.getDigit());
	setColorful(colorFul);
	setColor(Game_colors::GREEN);
}
Direction Fruit::direction(int dir)const
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
bool Fruit::checkStatus(const Position& pos, Board& b)
{
	if (pos.getX() >= b.getStatusPos().getX() && pos.getX() <= b.getStatusPos().getX()+ STATUS_ROWS)
	{
		if (pos.getY() >= b.getStatusPos().getY() && pos.getY() <= b.getStatusPos().getY() + STATUS_COLS)
			return true;

	}
	return false;

}
bool Fruit::checkGhosts(Position& pos, vector<Ghost>& ghosts)
{
	for (int i = 0; i < (int)ghosts.size(); i++)
	{

		if (pos == ghosts[i].getPos())
			return true;
	}
	return false;
}
void Fruit::moveCreature(const Board& b, Position& pacmanPos, Mode mode)
{
	    strategy.moveInStrategy(b, *this ,pacmanPos);

}
