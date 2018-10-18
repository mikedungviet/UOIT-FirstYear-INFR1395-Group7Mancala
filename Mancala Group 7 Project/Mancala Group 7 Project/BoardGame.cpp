#include "BoardGame.h"

/*
	This function draws the board at the location set in
	the parameter
	@param xLocation This is the location top left corner
					 of the board in the x axis
	@param yLocation This is the location top left corner
					 of the board in the y axis
*/
void BoardGame::RenderBoard(int xLocation, int yLocation) {
	//Set to Y axis
	for (int i = 0; i < yLocation; i++) {
		std::cout << std::endl;
	}

	//Cout after indexing to X axis
	std::cout << std::setw(107+xLocation)<<" _______________________________________________________________________________________________________ \n";
	std::cout << std::setw(107+xLocation)<<"|            |    (A1)    |    (A2)    |    (A3)    |    (A4)    |    (A5)    |    (A6)    |            |\n";
	std::cout << std::setw(107+xLocation)<<"|            |            |            |            |            |            |            |            |\n";
	std::cout << std::setw(107+xLocation)<<"|            |     04     |     04     |     04     |     04     |     04     |     04     |            |\n";
	std::cout << std::setw(107+xLocation)<<"|            |____________|____________|____________|____________|____________|____________|            |\n";
	std::cout << std::setw(107+xLocation)<<"|            |                                                                             |            |\n";
	std::cout << std::setw(107+xLocation)<<"|            |                               Player 1's Turn                               |            |\n";
	std::cout << std::setw(107+xLocation)<<"|            |_____________________________________________________________________________|            |\n";
	std::cout << std::setw(107+xLocation)<<"|            |            |            |            |            |            |            |            |\n";
	std::cout << std::setw(107+xLocation)<<"|            |     04     |     04     |     04     |     04     |     04     |     04     |            |\n";
	std::cout << std::setw(107+xLocation)<<"|            |    (B1)    |    (B2)    |    (B3)    |    (B4)    |    (B5)    |    (B6)    |            |\n";
	std::cout << std::setw(107+xLocation)<<"|            |            |            |            |            |            |            |            |\n";
	std::cout << std::setw(107+xLocation)<<"|____________|____________|____________|____________|____________|____________|____________|____________|\n";
}							