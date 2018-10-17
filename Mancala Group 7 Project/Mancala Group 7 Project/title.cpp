#include <iostream>
#include <Windows.h>
using namespace std;

void PrintTitle(int delay) {
	Sleep(delay);
	cout << "''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''" << endl;
	Sleep(delay);
	cout << "                                                             ____ " << endl;
	cout << "	                        |\\    /|     /\\     |\\  |   |         /\\     |        /\\" << endl;
	Sleep(delay);
	cout << "	                        | \\  / |    /__\\    | \\ |   |        /__\\    |       /__\\ " << endl;
	Sleep(delay);
	cout << "                                |  \\/  |   /    \\   |  \\|   |____   /    \\   |____  /    \\" << endl;
	Sleep(delay);
	cout << "    " << endl;
	cout << "   " << endl;
	cout << "''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''" << endl;
}