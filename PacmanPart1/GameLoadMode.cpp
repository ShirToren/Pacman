#include "GameLoadMode.h"


void GameLoadMode::PacmanLoad(string& line)
{

	pacman.pacmanLoadMove(b[currBoard], line.back(),mode);
	ifPacmanEatsBreadcrumb();
	numOfSteps++;
}
bool GameLoadMode::GhostLoad(string& line)
{
	ghostArr[currGhost].creatursLoadMove(b[currBoard], line.back(), mode);
	if (PacmanCrashWithGhost(ghostArr[currGhost]))
	{
		if (mode==Mode::SILENT &&(numOfSteps != gameFile.readGameResults("Pacman died in: ")))
			testFailed = true;
		currGhost = 0;
		return true;
	}
	currGhost++;
	if (currGhost == numOfGhosts)
		currGhost = 0;
	return false;
}
void GameLoadMode::FruitLoad(stringstream& check1, string& intermediate)
{

	getline(check1, intermediate, ' ');
	getline(check1, intermediate, ' ');
	if (intermediate == "Appearance")
	{
		fruit = new Fruit;
		getline(check1, intermediate, ' ');
		fruit->setObjSign(intermediate[0]);
		Position pos;
		getline(check1, intermediate, ' ');
		pos.setX(stoi(intermediate));
		getline(check1, intermediate, ' ');
		pos.setY(stoi(intermediate));
		fruit->setPos(pos);
		fruit->setFirstPos(pos);
	}

	else if (intermediate == "DisAppearance")
		deleteFruit();
	else
	{
		fruit->creatursLoadMove(b[currBoard], intermediate[0], mode);
		numOfStepsFruit++;
	}
}
void GameLoadMode::oneRound()
{
	bool flag = true;
	while (flag)
	{
		if (mode != Mode::SILENT)
			Sleep(20);
		flag = oneMove();
	}
}
bool GameLoadMode::oneMove()
{
	
	string line;
	gameFile.getLineFromFile(line);
	stringstream check1(line);
	string intermediate;

	switch (line[0])
	{
	case 'P':
		PacmanLoad(line);
		crashFruitAndPacman();
		if (checkCrashWithGhosts())
		{
			if (mode == Mode::SILENT &&(numOfSteps != gameFile.readGameResults("Pacman died in: ")))
				testFailed=true;
			currGhost = 0;
			return false;
		}
		break;
	case 'G':
		if (GhostLoad(line))
			return false;
		crashFruitAndGhosts();
		break;
	case 'F':
		FruitLoad(check1, intermediate);
		crashFruitAndGhosts();
		crashFruitAndPacman();
		break;
	}

	if (mode != Mode::SILENT) printStatus();
	if (pacman.getPoint() == numOfFood) return false;//the user won
	return true;
}
void GameLoadMode::start()
{
	color.setColorFul(false);
	while (currBoard < numOfFiles)
	{
		gameFile.modeLoadOpenFiles((*fileNames)[currBoard]);
		system("cls");

		if(mode==Mode::LOAD)
		b[currBoard].printBoard(color);

		oneGame(Level::NOVICE);
		if (pacman.getLive() == 0)
			break;
		else
		{
			if (mode == Mode::SILENT && (numOfSteps != gameFile.readGameResults("Pacman's winning point of time: ")))
				testFailed = true;
		}
		if (mode == Mode::LOAD || mode == Mode::SILENT)
			gameFile.modeLoadCloseFiles();
	}
	if (mode == Mode::SILENT)
	{
		system("cls");
		if (testFailed)
			cout << "Test FAILED";
		else
			cout << "Test PASSED";
	}
	endOfGame();

	char ch = _getch();      /*wait until the user press any key*/
	system("cls");
}


