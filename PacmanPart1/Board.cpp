#define _CRT_SECURE_NO_WARNINGS
#include "board.h"
#include "Color.h"

void Board::setAllBoard()
{

	numOfFood = 0;
	numOfGhosts = 0;
	int numOfPacman = 0, numOfStatus = 0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			switch (fullBoard[i][j])
			{
			case '%':
				pacmanBoard[i][j] = ' ';
				break;
			case '#':
				pacmanBoard[i][j] = '#';
				break;
			case '@':
				pacmanPos = { i,j };
				pacmanBoard[i][j] = ' ';
				numOfPacman++;
				break;
			case '$':
				ghostsPos.push_back({ i, j });
				pacmanBoard[i][j] = '.';
				numOfFood++;
				numOfGhosts++;
				break;
			case '&':
				statusPos = { i,j };
				for (int k = 0; k < STATUS_COLS+1; k++)
				{
					fullBoard[i][j + k] = '%';
					fullBoard[i + 1][j + k] = '%';
					fullBoard[i + 2][j + k] = '%';
				}
				fullBoard[i][j] = '&';
				pacmanBoard[i][j] = ' ';
				numOfStatus++;
				break;
			case ' ':
					pacmanBoard[i][j] = '.';
					numOfFood++;
				break;

			default:
				pacmanBoard[i][j] = '.';
				numOfFood++;
			}


		}
	}
	checkIfValidBoard(numOfGhosts, numOfPacman, numOfStatus,statusPos);
}
void Board::checkIfValidBoard(int numOfGhosts, int numOfPacman, int numOfStatus,const Position& pos)
{
	if (numOfGhosts > MAX_NUM_OF_GHOSTS)
		inValidBoard = true;
	if (numOfPacman != 1)
		inValidBoard = true;
	if (numOfStatus != 1)
		inValidBoard = true;
	if(pos.getX()== rows-1 && ((pos.getY()> MAX_COL_SIZE- STATUS_COLS)))
		inValidBoard = true;
	if (pos.getX() == BORDER && ((pos.getY() > MAX_COL_SIZE - STATUS_COLS)))
		inValidBoard = true;
	if (pos.getX() >= MAX_ROW_SIZE - STATUS_ROWS)
		inValidBoard = true;
}
void Board::printBoard(Color& color)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (pacmanBoard[i][j] == '#' && (i == BORDER || i == rows - 1 || j == BORDER || j == cols - 1))
			{
				color.setConsulColor(Game_colors::LIGHTAQUA);
			}
			else if (pacmanBoard[i][j] == '#')
			{
				color.setConsulColor(Game_colors::LIGHTPURPLE);
			}
			else
				color.setConsulColor(Game_colors::WHITE);
			cout << pacmanBoard[i][j];
		}
		cout << endl;
	}
}
bool Board::isWall(const Position& pos)const
{
	if (pacmanBoard[pos.getX()][pos.getY()] == '#')
		return true;

	return false;
}
void Board::getBoardFromFile(const string& fileName)
{
	ifstream myFile;
	myFile.open(fileName);
	int i = 0;
	string str;

	getline(myFile, str);
	cols = str.size();
	strcpy(fullBoard[i], str.c_str());
	i++;

	if (fullBoard[BORDER][cols - 1] == '&')
		cols += STATUS_COLS;
	if (str.size() > MAX_COL_SIZE)
		cols = MAX_COL_SIZE;
	

	while (!myFile.eof()&& i <= MAX_ROW_SIZE)
	{
		getline(myFile, str);
		strcpy(fullBoard[i], str.c_str());
		i++;
	}
	myFile.close();
	rows = i;
	/* check if in the last line a - &appears */
	string str2;
	str2 = fullBoard[(rows - 1)];
	str2.resize(cols - STATUS_COLS);
	std::size_t found = str2.find("&");
	if (found != std::string::npos && rows + STATUS_ROWS <= MAX_ROW_SIZE)
		rows += STATUS_ROWS;
}

