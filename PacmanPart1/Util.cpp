#include "util.h"
#include <filesystem>

void gotoxy(int x, int y)
{
	HANDLE hConsoleOutput;
	COORD dwCursorPosition;
	cout << flush;
	dwCursorPosition.X = y;
	dwCursorPosition.Y = x;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, dwCursorPosition);
}
int createFileNames(vector<string>& fileNames)
{
	string str1;

	string path = "./";
	for (const auto& entry : filesystem::directory_iterator(path))
	{
		filesystem::path str = entry.path();
		str1 = str.string();

		string str2 = str1;
		str2.erase(0, str1.size() - 11);
		if (str2.compare(".screen.txt") == 0)
		{
			str1.erase(0, 2);
			fileNames.push_back(str1);
		}
	}

	int numOfFiles = fileNames.size();
	sort(fileNames.begin(), fileNames.end(), compare1);
	return numOfFiles;
}

bool compare1(const string& a, const string& b)
{
	return a < b;
}
