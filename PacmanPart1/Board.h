#pragma once
#include "Position.h"
#include "Util.h"


class Board
{
private:
	char fullBoard[MAX_ROW_SIZE][MAX_COL_SIZE];
	char pacmanBoard[MAX_ROW_SIZE][MAX_COL_SIZE];
	int rows, cols;
	Position pacmanPos, statusPos;
	vector <Position> ghostsPos;
	int numOfFood;
	int numOfGhosts;
	bool inValidBoard = false;
	

public:
	//C'tor
	Board() : fullBoard{ }, pacmanBoard{}, rows(BORDER), cols(BORDER), numOfFood(0), numOfGhosts(0) {};
	Board(string str) : fullBoard{ }, pacmanBoard{}, rows(BORDER), cols(BORDER), numOfFood(0), numOfGhosts(0)
	{
		getBoardFromFile(str);
		setAllBoard();
	};

	//Set
	void set(char ch, const Position& pos)
	{
		pacmanBoard[pos.getX()][pos.getY()] = ch;
	}
	void setAllBoard();
	
	//Get
	char get(const Position& pos)const 
	{
		return pacmanBoard[pos.getX()][pos.getY()];

	}
	int getNumOfFood()const
	{
		return numOfFood;
	}
	Position& getStatusPos()
	{
		return statusPos;
	}
	Position& getPacmanPos()
	{
		return pacmanPos;
	}
	vector<Position>& getGhostsPos()
	{
		return ghostsPos;
	}
	int getNumOfGhosts()const
	{
		return numOfGhosts;
	}
	int getCols()const
	{
		return cols;
	}
	int getRows()const
	{
		return rows;
	}
	void getBoardFromFile(const string& fileName);
	bool getBoardInValid()const
	{
		return inValidBoard;
	}

	void printBoard(Color& color);
	bool isWall(const Position& pos)const;
	void checkIfValidBoard(int numOfGhosts, int numOfPacman, int numOfStatus, const Position& pos); /*followed by the given instructions*/


};





