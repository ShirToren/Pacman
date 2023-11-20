#pragma once
#include "GameCreature.h"
#include "Smart.h"
#include "Good.h"
#include "Novice.h"


class Ghost : public GameCreature
{
private:
	bool flag;
	MoveStrategy* strategy;

public:
	//C'tor
	Ghost(Position& firstPos) : GameCreature(Direction::STOP, firstPos, firstPos, Game_colors::RED, '@'), flag(true), strategy(nullptr) {};
	Ghost() : GameCreature(Direction::STOP, (0, 0), (0, 0), Game_colors::RED, '@'), flag(false), strategy(nullptr) {};
	Ghost(const Ghost& ghost) :GameCreature(ghost){
		strategy = nullptr;
		flag = false;
	}
	Ghost operator=(const Ghost& ghost) = delete;
	~Ghost()
	{
		if (strategy != nullptr)
			delete strategy;
	};

	const MoveStrategy& getStrategy()const
	{
		return *strategy;
	}
	virtual void moveCreature(const Board& b, Position& pacmanPos, Mode mode);
	void setStrategy(Level level);
};


