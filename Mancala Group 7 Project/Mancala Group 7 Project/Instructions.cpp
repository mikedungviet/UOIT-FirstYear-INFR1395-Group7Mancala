#include <iostream>


void instructions()
{

		std::cout << " _   _                   _____        ________            \n";
		std::cout << "| | | |                 |_   _|       | ___ \  |            \n";
		std::cout << "| |_| | _____      __     | | ___     | |_/ / | __ _ _   _ \n";
		std::cout << "|  _  |/ _ \\ \\ /\\ / /     | |/ _ \\    |  __/| |/ _` | | | |\n";
		std::cout << "| | | | (_) \\ V  V /      | | (_) |   | |   | | (_| | |_| |\n";
		std::cout << "\\_| |_/\\___/ \\_/\\_/       \\_/\\___/    \\_|   |_|\\__,_|\\__, |\n";
		std::cout << "                                                      __/ |\n";
		std::cout << "                                                     |___/\n";
		std::cout << "                                                          \n";
		std::cout << "===========================================================\n";
		std::cout << "                                                            \n";
		std::cout << "Each player gets one side of the board. (The bottom/ A side of the board is player 1's side & the top/ B side of the board is Player 2's side)\n";
		std::cout << "Each slot starts out with 4, and the mancalas(the large slots on either side) start out with 0. The number in each slot represents how many pieces are in that slot.\n";
		std::cout << "The mancalas are the \"goals\" in the game the one on the right is Player 1's goal and the one on the left is Player 2's goal.\n";
		std::cout << "Your objective is to get the most pieces in your mancala.\n";
		std::cout << "Pieses are moved counter clockwise.\n";
		std::cout << "On your turn, you type in the name of the slot you want to play (A1, A2, B1, B2, etc.)\n";
		std::cout << "The pieces in that slot will then be evenly distributed to the slots counter clockwise from that slot. \n";
		std::cout << "If the last piece on your move lands in your mancala, then you get a free turn,.\n";
		std::cout << "If the last piece on your move lands in an empty slot on your side of the board, you \"capture\" that piece and any pieces in the direct opposite slot, and all of those pieces go to your mancala.\n";
		std::cout << "The game ends when all six slots on one side of the board are empty.\n";
		std::cout << "The winner of the game is the player with the most pieces in their mancala at the end of the game.\n";


}