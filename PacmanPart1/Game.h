#pragma once
#include "util.h"
#include "board.h"
#include "position.h"
#include "Pacman.h"
#include "ghost.h"
#include "Fruit.h"
#include "Smart.h"
#include "Good.h"
#include "Novice.h"
#include "Files.h"
#include "Print.h"



class Game
{
protected:

	int numOfFiles;
	Board* b;
	int numOfFood, numOfGhosts;
	int currBoard;
	bool sameBoard;
	Pacman pacman;
	vector <Ghost> ghostArr;
	Status status;
	vector<string> *fileNames;
	GameCreature* fruit;
	Color color;
	Files gameFile;
	int numOfSteps;
	Mode mode;
	int numOfStepsFruit;
	int randTime;
	int currGhost;


public:
	//C'tor
	Game();
	Game(vector<string>* _fileNames, int _numOfFiles,Mode _mode);
	Game(const Game& game) = delete;
	Game operator=(const Game& game) = delete;
	virtual ~Game() {
			delete[] b;
			delete fruit;
	};

	virtual void start() = 0;
	virtual void oneRound() = 0;    /*until the pacman touches a ghost*/

	void printEndOfGame()const;   /*win or game over*/
	void endOfGame(); /*init values for a new game*/
	void oneGame(Level level);
	void chooseDirection(char ch);
	bool checkCrashWithGhosts(); /*checks crash of pacman and ghosts, and ghosts and fruit*/
	void handelCrashWithGhosts();
	void printStatus(); /*prints current live and score on the screen*/
	void updateValuesNewBoard(Level level);/*init values of ghosts and pacman, when paman loses a life or in case of a new board*/
	bool caseBoardIsInvalid();
	void deleteFruit();
	void updateFruitInFile();
	void initCreatures();
	bool pacmanWin();
	void printObjects();
	void crashFruitAndGhosts();
	void crashFruitAndPacman();
	void ifPacmanEatsBreadcrumb();
	bool PacmanCrashWithGhost(Ghost& ghost);
};

