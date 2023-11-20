#pragma once
#include "Game.h"

class GamePlayMode : public Game
{
	Level levelOfGame;

public:
	GamePlayMode(vector<string>* _fileNames, int _numOfFiles, Mode _mode) : Game(_fileNames, _numOfFiles, _mode), levelOfGame(Level::NOVICE){}
	GamePlayMode() : levelOfGame(Level::NOVICE),Game() {}
	virtual ~GamePlayMode() {}
	
	virtual void start();
	virtual void oneRound();/*until the pacman touches a ghost*/
	bool moveCreatures(); /*returns true when a ghost eats the pacman*/
	bool oneMove(int* countTime);/*returns true while the round needs to continue*/
	bool handelGhostsMove(); /*returns true when a ghost eats the pacman*/
	void handelFruitMove();
	void handelPacmansMove();
	void fruitAppearing(int* countTime);/*handle fruit appearence and disappearence randomly*/
	void case1();
	void case2();
	Level chooseLevel(char level)const;
	void colorsOption();  /*choose colorful game or not*/
	void levelOptions();  /*choose game's level*/
	bool isValidDirection(char ch)const;
	void caseESC(char ch);  /*if the user presses ESC*/
	void playMode();

};

