#pragma once
#include "Game.h"

class GameLoadMode : public Game
{
	bool testFailed = false;

public:
	GameLoadMode(vector<string>* _fileNames, int _numOfFiles, Mode _mode) : Game(_fileNames, _numOfFiles, _mode) {}
	GameLoadMode() : Game() {}
	virtual ~GameLoadMode() {}

	virtual void start();
	void PacmanLoad(string& line);
	bool GhostLoad(string& line);
	void FruitLoad(stringstream& check1, string& intermediate);
	virtual void oneRound();/*until the pacman touches a ghost*/
	bool oneMove(); /*returns true while the round needs to continue*/

};

