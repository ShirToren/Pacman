#pragma once
#include "Util.h"
#include "Position.h"
#include "Pacman.h"


/*saving fruit data from the save mode and also taking info to the load mode*/
typedef struct fileFruit
{
	Position fruitFirstPos;
	char digit = ' ';
};

class Files
{
private:
	fileFruit fruit;
	ofstream listOfsteps;
	ofstream result;
	ifstream loadSteps;
	ifstream loadResult;
	
public:

	//Get
	char getDigit()
	{
		return fruit.digit;
	}
	Position& getFruitPos()
	{
		return fruit.fruitFirstPos;
	}
	void getLineFromFile(string& str)/*reding one line from list of steps file*/
	{
		getline(loadSteps, str);
	}
	//Set
	void setFruitPos(Position& pos)
	{
		fruit.fruitFirstPos = pos;
	}
	void setFruitDigit(char dig)
	{
		fruit.digit = dig;
	}


	void writeListOfSteps(const char* cretureName, Direction dir, bool fruitAppearance, bool fruitDisAppearance);
	void writeResult(string& nameOffile, int numOfSteps, bool isWin);
	char directionToFile(Direction& dir); /*write dir to file in one letter*/
	Direction directionFromFile(char dir); /*read direction in one letter and return this direction*/
	int readGameResults(const string& wanted);
	void modeLoadCloseFiles();
	void modeSaveCloseFiles();
	void currStepsFile(string& name);
	void currResultFile(string& name);
	void modeLoadOpenFiles(string& nameOffile);
	void modeSaveOpenFiles(string& nameOffile);


};
