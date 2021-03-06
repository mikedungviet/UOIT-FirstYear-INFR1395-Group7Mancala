#pragma once
//Header Files
#include <string>
#include <iostream>
#include "Player.h"
#include "BoardGame.h"
//#include <sstream>

//Function prototype
//void SetWindow();
void PrintTitle(int);

/*
	Convert string to int
*/
int ConvertStringToInteger(std::string string) {
	//int num;
	try {
		return std::stoi(string);
	}
	catch (...) {
		return -1;
	}
}
/*
	Main menu
	@return the choice
*/
int FirstMenu() {
	std::string userInput;
	PrintTitle(375);
	while (true) {
		std::cout << "1. Play a Local Multiplayer Game" << std::endl;
		std::cout << "2. Instruction" << std::endl;
		std::cout << "3. Exit Game" << std::endl;

		while (std::cin >> userInput) {
			std::cin.ignore();
			int num = ConvertStringToInteger(userInput);
			if (num >= 1 || num <= 3)
				return num;
		}
	}
}


/*
	This function convert the player's choice to move
	@param *player This is the player's object
	@param *opponent This is the oppoenent's object
	@param *board This is the board
*/
void PlayerMoves(Player *player, Player *opponent, BoardGame *board, std::string message){
	std::string userChoice;
	system("CLS");
	PrintTitle(0);
	board->RenderBoard(8, 2, (player->GetName() + "'s Turn"));
	std::cout << "\nPlease pick a pit "+ message +": ";
	while (std::cin >> userChoice) {
		userChoice[0] = tolower(userChoice[0]);
		if (player->CheckValidMoves(userChoice)!=-1)
			break;
		std::cout << "Invalid Choice. Please try again: ";
		std::cout << "\nPlease pick a pit " + message + ": ";
	}
	int userInputToIndex = board->BinarySearchForIndex(userChoice);
	player->PlayerMoves(userInputToIndex, opponent, board);
}
	
/*
	This game loop run a mancala game
	@param *player1 The address of player1 Object
	@param *player2 The address of player2 Object
	@param *board The address of playingBoard Object
	@return Return the Winner's name
*/
std::string LocalMutiPlayer(Player *player1, Player *player2, BoardGame *board) {
	//Local Variable (Stack memory)
	std::string userInput, specialMessage;

	//Game loop
	while (true) {
		//Player1's turn
		if (player1->GetPlayerTurn()) {
			PlayerMoves(player1, player2, board, "(A1, A2, A3, A4, A5, A6)");
		}
		//Player2's turn
		if (player2->GetPlayerTurn()) {
			PlayerMoves(player2, player1, board, "(B1, B2, B3, B4, B5, B6)");
		}
		//Check if the game meets the condition to end
		if (board->CheckIfGameEnds()) {
			//Determine the winner
			board->AddUpPoints();
			if (board->GetBoardGameArray(6) > board->GetBoardGameArray(13))
				return player1->GetName(); //Player 1 wins
			else if (board->GetBoardGameArray(6) < board->GetBoardGameArray(13))
				return player2->GetName(); //Player 2 Wins
			else
				return "tie"; //No one wins
		}
		system("cls");
	}
}