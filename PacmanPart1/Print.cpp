#include "Print.h"

void Print::printMenu()
{
	cout << "MENU:" << endl;
	cout << "(1) Start a new game" << endl << "(2) For choosing a specific screen" << endl << "(8) Present instructions and keys" << endl << "(9) EXIT" << endl;

}
void Print::printInstructions()
{
	cout << "PACMAN'S INSTRUCTIONS:" << endl;
	cout << "When the game starts the pacman is positioned at his start position without any movement." << endl;
	cout << "Once you select move direction (using the keys, as listed below)," << endl << "the pacman will continue to move in this direction even if you don’t press any key," << endl << "as long as the pacman doesn’t hit a wall and the STAY key was not pressed." << endl;
	cout << "Pressing the ESC key during a game pauses the game, you should press the ESC key again to continue the game." << endl;
	cout << "The pacman travels on screen and eats the breadcrumbs. Each eaten breadcrumb equals a point to be earned." << endl << "Once all breadcrumbs on screen are eaten the game ends." << endl;
	cout << "Pacman has 3 lives." << endl;
	cout << "In case a ghost eats the pacman you lose one life. When all lives are gone the game is over." << endl;
	cout << "The pacman can cross the screen in an invisible tunnel if there are no walls at both sides." << endl;
	cout << endl;
	cout << endl;
	cout << "PRESS  D  to move RIGHT" << endl;
	cout << "PRESS  A  to move LEFT" << endl;
	cout << "PRESS  W  to move UP" << endl;
	cout << "PRESS  X  to move DOWN" << endl;
	cout << "PRESS  S  to STOP pacman's move" << endl;
	cout << "PRESS  ECS  to PUASE the game" << endl;
	cout << endl << "Press any key to go back to the manu" << endl;

}
