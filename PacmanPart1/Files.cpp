#include "Files.h"


/*writing each step of the game to the file by naming the creature and the diraction*/
/*writing creture nume : F means fruit, P means pacnan G means ghost*/
/**for fruit there are three possible options:*/
/*Appreance means a new fruit in the game with new posision and digit*/
/*Disappearance for the time of the fruits death*/
/*A regula step of the fruit*/
void Files::writeListOfSteps(const char* cretureName, Direction dir, bool fruitAppearance, bool fruitDisAppearance)
{
	if (fruitAppearance)
	{
		listOfsteps << cretureName << " " << "Appearance" << " " << fruit.digit << " " << fruit.fruitFirstPos.getX() << " " << fruit.fruitFirstPos.getY() << endl;
	}
	else if (fruitDisAppearance)
	{
		listOfsteps << cretureName << " " << "DisAppearance" << endl;
	}
	else
		listOfsteps << cretureName << " " << directionToFile(dir) << endl;

}


/*writing to the file the time of pcaman death or winning*/
void Files::writeResult(string& nameOffile, int numOfSteps, bool isWin)
{

	if (isWin)
		result << "Pacman's winning point of time: " << endl<<numOfSteps << endl;
	else
		result << "Pacman died in: " << endl<< numOfSteps << endl;
}
int Files::readGameResults(const string & wanted)
{
	int numOfSteps;
	
	string line;
	
	getline(loadResult, line);
	if (wanted == "Pacman's winning point of time: ")
	{
		getline(loadResult, line);
		numOfSteps = stoi(line);
	}
	else if (wanted == "Pacman died in: ")
	{
		getline(loadResult, line);
		numOfSteps = stoi(line);
	}
	else /*mean's there is unsuitability*/
		return 0;

	return numOfSteps;

}

Direction Files::directionFromFile(char dir)
{
	switch (dir)
	{
	case 'D':
		return Direction::RIGHT;
	case 'W':
		return Direction::UP;
	case 'S':
		return Direction::STOP;
	case'A':
		return Direction::LEFT;
	case 'X':
		return Direction::DOWN;
	default:
		return Direction::STOP;
	}
}
char Files::directionToFile(Direction& dir)
{
	switch (dir)
	{
	case Direction::DOWN:
		return 'X';
	case Direction::UP:
		return 'W';
	case Direction::STOP:
		return 'S';
	case Direction::RIGHT:
		return 'D';
	case Direction::LEFT:
		return 'A';
	default:
		return ' ';
	}
}


void Files::currStepsFile(string& name)
{

	name.erase(name.end() - 11, name.end());
	name = name + ".steps.txt";
	
}
void Files::currResultFile(string& name)
{
	name.erase(name.end() - 11, name.end());
	name = name + ".result.txt";

}

void Files::modeLoadOpenFiles(string& nameOffile)
{

	string steps = nameOffile;
	string _result = nameOffile;

	currStepsFile(steps);
	currResultFile(_result);
	loadSteps.open(steps);
	loadResult.open(_result);
}
void Files::modeSaveOpenFiles(string& nameOffile)
{
	string steps = nameOffile;
	string _result = nameOffile;

	currStepsFile(steps);
	currResultFile(_result);
	listOfsteps.open(steps);
	result.open(_result);
}

void Files::modeSaveCloseFiles()
{
	listOfsteps.close();
	result.close();
}
void Files::modeLoadCloseFiles()
{
	loadResult.close();
	loadSteps.close();
}