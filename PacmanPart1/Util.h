#pragma once
#include <time.h>
#include <conio.h>
#include <windows.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include <vector>
#include <stdlib.h>     
#include <time.h>      
#include "Color.h"
#include <string>

using namespace std;


static int constexpr ESC = 27;
static int constexpr MAX_ROW_SIZE = 25;
static int constexpr MAX_COL_SIZE = 80;
static int constexpr FRUIT_STEPS = 15;
static int constexpr STATUS_COLS = 19;
static int constexpr STATUS_ROWS = 2;
static int constexpr BORDER = 0;
static int constexpr ZERO_CHAR = 48;
static int constexpr FRUIT_PACE = 8;
static int constexpr MAX_NUM_OF_GHOSTS = 4;
static int constexpr GOOD_STEPS = 20;

enum class Mode { SAVE, LOAD, SIMPLE,SILENT };
enum class Creature { PACMAN, GHOST, FRUIT };
enum class Level { SMART, GOOD, NOVICE, INVALID };
enum class Direction { LEFT, RIGHT, DOWN, UP, STOP, ESC };
enum class Colors { WITH = 1, WITHOUT, INVALID };
enum class Status { PLAY, PAUSE };

void gotoxy(int x, int y);
int createFileNames(vector<string>& fileNames);
bool compare1(const string& a, const string& b);
