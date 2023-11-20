#include "GamePlayMode.h"

bool GamePlayMode::moveCreatures()
{

	handelPacmansMove();
	ifPacmanEatsBreadcrumb();
	crashFruitAndPacman();
	if (checkCrashWithGhosts())
		return true;
	if (handelGhostsMove())
		return true;
	crashFruitAndGhosts();
	handelFruitMove();
	crashFruitAndGhosts();
	crashFruitAndPacman();

	return false;
}
void GamePlayMode::oneRound()
{
	int countTime = 0; /*for the fruit appearance and disappearance*/

	char ch;
	bool flag = true;

	// for first time input.
	do {
		ch = _getch();
	} while (!isValidDirection(ch)); /*wait for a valid key*/

	chooseDirection(ch);/*users pacman's choice*/

	while (flag)       /*continue with the round until the user loses a live*/
	{

		while (status == Status::PLAY && flag)  /*play while ESC not pressed*/
		{
			Sleep(80);

			if (_kbhit())
			{
				ch = _getch();
				chooseDirection(ch);
			}
			caseESC(ch);     /*if ch is ESC pause or play again the game*/
			if (status == Status::PLAY)
				flag = oneMove(&countTime);
		}
		if (_kbhit())
		{
			ch = _getch();
			if (ch == ESC)
			{
				caseESC(ch);
				ch = 0;
			}
		}
	}
}
bool GamePlayMode::oneMove(int* countTime)
{
	if (moveCreatures())
		return false;
		printStatus();
	if (pacman.getPoint() == numOfFood) //the user won
		return false;
	if (fruit == nullptr)
		(*countTime)++;
	fruitAppearing(countTime);
	return true;
}
bool GamePlayMode::handelGhostsMove()
{
	/*ghost's move*/
	for (int i = 0; i < numOfGhosts; i++)
	{
		if (numOfSteps % 2 == 0)
		{
			ghostArr[i].moveCreature(b[currBoard], pacman.getPos(), mode);

			if (mode == Mode::SAVE)
				gameFile.writeListOfSteps("G", ghostArr[i].getDirection(), false, false);

			if (pacman.getPos() == ghostArr[i].getPos())
			{
				handelCrashWithGhosts();
				deleteFruit();
				return true;
			}
		}
	}
	return false;
}
void GamePlayMode::handelFruitMove()
{
	if (fruit != nullptr)
	{
		if (numOfSteps % 8 == 0)
		{
			fruit->moveCreature(b[currBoard], pacman.getPos(), mode);
			numOfStepsFruit++;
			if (mode == Mode::SAVE)
				gameFile.writeListOfSteps("F", fruit->getDirection(), false, false);
			
		}
	}
}
void GamePlayMode::handelPacmansMove()
{
	
	pacman.goToCreature();
	cout << b[currBoard].get(pacman.getPos());
	pacman.moveCreature(b[currBoard], pacman.getPos(), mode);
	pacman.printCreatureMove();

	if (mode == Mode::SAVE)
		gameFile.writeListOfSteps("P", pacman.getDirection(), false, false);
	
	numOfSteps++;
}

void GamePlayMode::fruitAppearing(int* countTime)
{
	if (numOfStepsFruit == FRUIT_STEPS && fruit != nullptr)
		deleteFruit();

	if (*countTime == randTime)
	{
			fruit = new Fruit(b[currBoard], b[currBoard].getPacmanPos(), ghostArr, color.getColorful());
			if (mode == Mode::SAVE)
			{
				updateFruitInFile();
				gameFile.writeListOfSteps("F", Direction::STOP, true, false);
			}
		*countTime = 0;
	}
}
void GamePlayMode::playMode() 
{
	while (currBoard < numOfFiles)
	{
		if (mode != Mode::SIMPLE)
		{
			gameFile.modeSaveOpenFiles((*fileNames)[currBoard]);
		}
		system("cls");
		b[currBoard].printBoard(color);
		/*only in save*/
		fruit = new Fruit(b[currBoard], b[currBoard].getPacmanPos(), ghostArr, color.getColorful());
		if (mode == Mode::SAVE)
		{
			updateFruitInFile();
			gameFile.writeListOfSteps("F", Direction::STOP, true, false);
		}
		oneGame(levelOfGame);
		if (pacman.getLive() == 0)/*if user loses wont continue to next board*/
			break;
		if (mode == Mode::SAVE)
			gameFile.modeSaveCloseFiles();
	}
	color.setColorFul(false);
	endOfGame();

	char ch = _getch();      /*wait until the user press any key*/
	system("cls");
	
}

void GamePlayMode::start()
{
	Print::printMenu();
	char option, ch;
	cin >> option;

	while (option != '9')
	{
		system("cls");
		switch (option)
		{
		case '1':
			case1();
			playMode();
			break;
		case '2':
			case2();
			playMode();
			break;
		case '8':
			Print::printInstructions();
			ch = _getch();      /*wait until the user press any key*/
			system("cls");
			break;
		default:
			cout << "Please enter a valid choice" << endl;
			break;
		}
		Print::printMenu();
		cin >> option;
	}
	system("cls");
	cout << "GOODBYE :)";
}

void GamePlayMode::case1 ()
{
	char ch;
	
	if (numOfFiles == 0)
		cout << "There are no files. Please load a file.";
	else
	{
		colorsOption();
		levelOptions();
	
	}
}
void GamePlayMode::case2()
{
	char ch;
	if(numOfFiles==0)
		cout << "There are no files. Please load a file.";
	else
	{
		string name;
		cout << "Please enter the name of the screen" << endl;
		cin >> name;
		name = name + ".txt";

		while (!sameBoard)
		{
			for (int i = 0; i < numOfFiles; i++)
			{
				if (strcmp(name.c_str(), (*fileNames)[i].c_str()) == 0)
				{
					currBoard = i;
					sameBoard = true;
				}
			}

			if (!sameBoard)
			{
				cout << "File does'nt excist. Please enter a valid name." << endl;
				cin >> name;
				name = name + ".txt";
			}
		}
		system("cls");
	
		colorsOption();
		levelOptions();
	}
	
}
void GamePlayMode::caseESC(char ch)
{

	if (ch == ESC)
	{
		if (status == Status::PLAY)
		{
			system("cls");
			cout << "Game paused, press ESC again to continue";
			status = Status::PAUSE;
		}
		else
		{
			system("cls");
			b[currBoard].printBoard(color);
			status = Status::PLAY;

		}

	}
}
bool GamePlayMode::isValidDirection(char ch)const
{
	if (ch != 'W' && ch != 'X' && ch != 'D' && ch != 'A' && ch != 'S'
		&& ch != 'w' && ch != 'x' && ch != 'd' && ch != 'a' && ch != 's')
		return false;
	return true;

}
Level GamePlayMode::chooseLevel(char level)const
{

	switch (level)
	{
	case '1':
		return Level::SMART;
	case '2':
		return Level::GOOD;
	case '3':
		return Level::NOVICE;
	default:
		return Level::INVALID;
	}
}
void GamePlayMode::colorsOption()
{
	char ch;
	Colors _color;
	cout << "For colored game press 1, else press 2." << endl;
	do {
		cin >> ch;
		switch (ch)
		{
		case '1':
			_color = Colors::WITH;
			break;
		case '2':
			_color = Colors::WITHOUT;
			break;
		default:
			_color = Colors::INVALID;
			cout << "Please enter only a valid choice" << endl;
			break;
		}

	} while (_color == Colors::INVALID);
	if (_color == Colors::WITH)
	{
		pacman.setColorful(true);
		color.setColorFul(true);
	}
}
void GamePlayMode::levelOptions()
{
	char level;

	cout << "Please choose a level:" << endl;
	cout << "(1) HARD (2) NORMAL (3) EASY" << endl;
	cin >> level;
	levelOfGame = chooseLevel(level);
	while (levelOfGame == Level::INVALID)
	{
		cout << "Please enter a valid level." << endl;
		cin >> level;
		levelOfGame = chooseLevel(level);
	}

}



