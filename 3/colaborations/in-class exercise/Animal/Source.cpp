#include "Tree.h"
#include <iostream>

using namespace std;

int main()
{
	Tree game;
	char c;

	do
	{
		game.playGame();
		cout << endl << "Play again? (y/n)" << endl;
		cin >> c;
	} while (c == 'y');

	return 0;
}