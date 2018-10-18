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
	std::cout << std::setw(20+xLocation)<<"|            |     "<<std::setw(2)<<std::setfill('0')<< testing[0].boardGameValue <<"     |     " << std::setw(2) << std::setfill('0') 
		<<testing[1].boardGameValue <<"     |     " << std::setw(2) << std::setfill('0') <<testing[2].boardGameValue <<"     |     " << std::setw(2) << std::setfill('0') <<testing[3].boardGameValue <<"     |     "
		<< std::setw(2) << std::setfill('0') <<testing[4].boardGameValue <<"     |     " << std::setw(2) << std::setfill('0') <<testing[5].boardGameValue <<"     |            |\n";
	std::cout << std::setfill(' ') << std::setw(107+xLocation)<<"|            |____________|____________|____________|____________|____________|____________|            |\n";
	std::cout << std::setfill(' ')<< std::setw(107+xLocation)<<"|            |                                                                             |            |\n";
	std::cout << std::setfill(' ')<< std::setw(7+xLocation)<<"|     " << std::setw(2) << std::setfill('0') << testing[13].boardGameValue <<"     |                               Player 1's Turn                               |     " 
		<< std::setw(2) << std::setfill('0') << testing[6].boardGameValue << "     |\n";
	std::cout << std::setfill(' ')<< std::setw(107+xLocation)<<"|            |_____________________________________________________________________________|            |\n";
	std::cout << std::setfill(' ')<< std::setw(107+xLocation)<<"|            |            |            |            |            |            |            |            |\n";
	std::cout << std::setfill(' ')<< std::setw(20+xLocation)<<"|            |     " << std::setw(2) << std::setfill('0') << testing[12].boardGameValue << "     |     "
		<< std::setw(2) << std::setfill('0') << testing[11].boardGameValue << "     |     " << std::setw(2) << std::setfill('0') << testing[10].boardGameValue << "     |     " 
		<< std::setw(2) << std::setfill('0') << testing[9].boardGameValue << "     |     "
		<< std::setw(2) << std::setfill('0') << testing[8].boardGameValue << "     |     " << std::setw(2) << std::setfill('0') << testing[7].boardGameValue << "     |            |\n";
	std::cout << std::setfill(' ')<< std::setw(107+xLocation)<<"|            |            |            |            |            |            |            |            |\n";
	std::cout << std::setfill(' ')<< std::setw(107+xLocation)<<"|            |    (B1)    |    (B2)    |    (B3)    |    (B4)    |    (B5)    |    (B6)    |            |\n";
	std::cout << std::setw(107+xLocation)<<"|____________|____________|____________|____________|____________|____________|____________|____________|\n";
}							