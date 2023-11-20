#include "game.h"

Game::Game() : numOfFiles(0), fileNames(nullptr),
b(nullptr), numOfFood(0), currBoard(-1), numOfGhosts(0),
ghostArr(0), status(Status::PAUSE), 
sameBoard(false), fruit(nullptr), numOfSteps(0), mode(Mode::SIMPLE)
, numOfStepsFruit(0), randTime(-1), currGhost(0){};
Game::Game(vector<string>* _fileNames, int _numOfFiles, Mode _mode) : numOfFiles(_numOfFiles),
fileNames(_fileNames), b(new Board[numOfFiles]{ (*_fileNames)[0] }),
currBoard(0), pacman(b[0].getPacmanPos()), status(Status::PLAY), 
numOfFood(b[0].getNumOfFood()),
numOfGhosts(b[0].getNumOfGhosts()), sameBoard(false) , fruit(nullptr), ghostArr(MAX_NUM_OF_GHOSTS)
, numOfSteps(0), mode(_mode), numOfStepsFruit(0), randTime(-1), currGhost(0)
{
	for (int i = 1; i < numOfFiles; i++)
	{
			b[i].getBoardFromFile((*_fileNames)[i]);
			b[i].setAllBoard();
	}
}
void Game::oneGame(Level level)
{
		updateValuesNewBoard(level);
		while (pacman.getLive() > 0)/*while pacman is alive*/
		{
			initCreatures();
			if (mode != Mode::SILENT) 
				printObjects();
			oneRound();//if run into ghost or eat all bread
			if (fruit != nullptr)
				deleteFruit();
			if (pacmanWin())  
				break; /*pacman wines*/
		}
}
bool Game::pacmanWin()
{
	if (pacman.getPoint() == numOfFood)
	{
		if (mode == Mode::SAVE)
			gameFile.writeResult((*fileNames)[currBoard], numOfSteps, true);

		if (sameBoard)
			currBoard = numOfFiles; //in this case, there is only one file
		else
			currBoard++;
		return true;
	}
	return false;
}
void Game::printObjects()
{
	printStatus();
	for (int i = 0; i < numOfGhosts; i++)
		ghostArr[i].printCreatureMove();
	pacman.printCreatureMove();
	if (fruit != nullptr)
		fruit->printCreatureMove();
}
void Game::initCreatures()
{
	pacman.initPos();
	for (int i = 0; i < numOfGhosts; i++)
		ghostArr[i].initPos();

	if (fruit != nullptr)
		fruit->initPos();
}
void Game::endOfGame()
{
	if (mode != Mode::SILENT)
		printEndOfGame();

	pacman.initPacmanValues();
	for (int i = 0; i < numOfFiles; i++)
		b[i].setAllBoard();
		
	currBoard = 0;
	sameBoard = false;
}
void Game::ifPacmanEatsBreadcrumb()
{
	if (pacman.getDirection() != Direction::STOP)
	{
		if (b[currBoard].get(pacman.getPos()) == '.')  //if current position is a breadcrumb
		{
			pacman.addScore(1);
			pacman.addPoint();
			b[currBoard].set(' ', pacman.getPos());
		}
	}
}
void  Game::crashFruitAndGhosts()
{
	for (int i = 0; i < numOfGhosts; i++)
	{
		if (fruit != nullptr && fruit->getPos() == ghostArr[i].getPos()) /*if the fruit and a ghost crashed*/
			deleteFruit();
	}
}
void  Game::crashFruitAndPacman()
{
	if (fruit != nullptr && pacman.getPos() == fruit->getPos()) /*if the pacman eats the fruit*/
	{
		pacman.addScore(fruit->getObjSign() - ZERO_CHAR);
		b[currBoard].set(' ', pacman.getPos());
		deleteFruit();
	}
}
bool Game::PacmanCrashWithGhost(Ghost & ghost)/*CRASH with one !!!!! ghost*/
{
	if (pacman.getPos() == ghost.getPos())
	{
		handelCrashWithGhosts();
		return true;
	}
	return false;
}
bool Game::checkCrashWithGhosts()
{
	
	for (int i = 0; i < numOfGhosts; i++)
	{
		if (pacman.getPos() == ghostArr[i].getPos())
		{
			handelCrashWithGhosts();
			return true;
		}
	}

	return false;
}
void Game::handelCrashWithGhosts()
{
	if(mode==Mode::SAVE)
		gameFile.writeResult((*fileNames)[currBoard], numOfSteps, false);

	
	pacman.takeLive();
	if (mode != Mode::SILENT)
	{
		for (int i = 0; i < numOfGhosts; i++)
		{
			ghostArr[i].goToCreature();
			cout << b[currBoard].get(ghostArr[i].getPos());
		}
	}
	  deleteFruit();
}
void Game::printStatus()
{
	gotoxy(b[currBoard].getStatusPos().getX(), b[currBoard].getStatusPos().getY());
	color.setConsulColor(Game_colors::LIGHTAQUA);
	cout << "SCORE: " << pacman.getScore();
	gotoxy(b[currBoard].getStatusPos().getX()+1, b[currBoard].getStatusPos().getY());
	cout << "LIVE:  " << pacman.getLive();
	color.setConsulColor(Game_colors::WHITE);
}
void Game::printEndOfGame()const
{
	if (mode != Mode::SILENT)
	{
		system("cls");
		if (pacman.getPoint() == numOfFood)
		{
			cout << "YOU WON THE GAME !!!! VERY NICE !!! SEE YOU NEXT TIME";
		}
		if (pacman.getLive() == 0)
		{
			cout << "GAME OVER :(";
		}
	}
}
void Game::chooseDirection(char ch)
{
	switch (ch)
	{
	case 'a':
		pacman.setDirection(Direction::LEFT);
		break;
	case 'A':
		pacman.setDirection(Direction::LEFT);
		break;
	case 'w':
		pacman.setDirection(Direction::UP);
		break;
	case 'W':
		pacman.setDirection(Direction::UP);
		break;
	case 'd':
		pacman.setDirection(Direction::RIGHT);
		break;
	case 'D':
		pacman.setDirection(Direction::RIGHT);
		break;
	case 'x':
		pacman.setDirection(Direction::DOWN);
		break;
	case 'X':
		pacman.setDirection(Direction::DOWN);
		break;
	case 's':
		pacman.setDirection(Direction::STOP);
		break;
	case 'S':
		pacman.setDirection(Direction::STOP);
		break;

	}
}
void Game::updateValuesNewBoard(Level level)
{
	if (caseBoardIsInvalid())
		return;
	pacman.setScore(0);
	pacman.setPoint(0);
	pacman.setFirstPos(b[currBoard].getPacmanPos());
	pacman.setPos(b[currBoard].getPacmanPos());
	numOfFood = b[currBoard].getNumOfFood();
	numOfGhosts = b[currBoard].getNumOfGhosts();
	ghostArr.clear();
	
	for (int i = 0; i < numOfGhosts; i++)
	{
		ghostArr.push_back(b[currBoard].getGhostsPos()[i]);
		ghostArr[i].setStrategy(level);
		ghostArr[i].setColorful(color.getColorful());
	}	
	numOfSteps = numOfStepsFruit= currGhost=0;
	
}
bool Game::caseBoardIsInvalid()
{
	if (b[currBoard].getBoardInValid())
	{
		cout << "This screen is invalid. Press any key to continue to the next screen" << endl;
		char ch = _getch(); /* wait until the user press any key */
			system("cls");
		currBoard++;
		if (currBoard == numOfFiles)
		{
			cout << "There are no more screens left to play." << endl;
			return true;
		}
	}
	return false;
}
void Game::deleteFruit()
{
	if (fruit != nullptr)
	{
		if (mode != Mode::SILENT)
		{
			fruit->goToCreature();
			cout << b->get(fruit->getPos());
		}
		delete fruit;
		fruit = nullptr;
		numOfStepsFruit = 0;
		if (mode == Mode::SAVE)
		{
			randTime = rand() % 100 + 5;
			gameFile.writeListOfSteps("F", Direction::STOP, false, true);
		}
	}
}
void Game::updateFruitInFile()
{
	if (fruit != nullptr)
	{
		gameFile.setFruitPos(fruit->getPos());
		gameFile.setFruitDigit(fruit->getObjSign());
	}
}
