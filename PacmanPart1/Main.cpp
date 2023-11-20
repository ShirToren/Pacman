#define _CRT_SECURE_NO_WARNINGS
#include "GamePlayMode.h"
#include "GameLoadMode.h"

bool compare1(const string& a, const string& b);
Mode readModes(char** argv);
Game* gameModes(vector<string>* fileNames, int numOfFiles, Mode mode);


int main(int argc, char** argv)
{

	vector<string> fileNames;
	int numOfFiles = createFileNames(fileNames);

	Mode mode = readModes(argv);

	Game* game = gameModes(&fileNames, numOfFiles, mode);
	game->start();

	delete game;
}

Game* gameModes(vector<string>* fileNames, int numOfFiles, Mode mode)
{
	Game* game;

	switch (mode)
	{
	case Mode::SAVE:
		game = new GamePlayMode(fileNames, numOfFiles, mode);
		break;
	case Mode::LOAD:
		game = new GameLoadMode(fileNames, numOfFiles, mode);
		break;
	case Mode::SIMPLE:
		game = new GamePlayMode(fileNames, numOfFiles, mode);
		break;
	case Mode::SILENT:
		game = new GameLoadMode(fileNames, numOfFiles, mode);
		break;
	default:
		game = new GamePlayMode(fileNames, numOfFiles, mode);
		break;
	}

	return game;
}
Mode readModes(char** argv)
{
	string line;
	string line2;

	if (argv[1])
	{
		line = argv[1];
		if (argv[2])
			line2 = argv[2];
	}


	if (line == "-save")
		return Mode::SAVE;

	else if (line == "-load")
	{

		if (line2 == "[-silent]")
			return Mode::SILENT;

		else return Mode::LOAD;
	}
	else
		return Mode::SIMPLE;

}
