#include "position.h"
bool Position::operator==(const Position& p)const
{
	if (x == p.x && y == p.y)
		return true;
	return false;
}
bool Position::operator!=(const Position& p)const
{
	if (x != p.x || y != p.y)
		return true;
	return false;
}