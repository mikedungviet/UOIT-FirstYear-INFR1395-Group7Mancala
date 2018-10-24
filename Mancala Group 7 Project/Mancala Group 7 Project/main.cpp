#include <iostream>
#include <string>
#include <stdlib.h>
#include "BoardGame.h"
#include "Player.h"

//Function Prototype
void SetWindow();
void PrintTitle(int);
std::string LocalMutiPlayer(Player*, Player*, BoardGame*);


int main()
{
	//Heap Storage
	BoardGame *playingBoard = new BoardGame;
	Player *playerOne = new Player(1);
	Player *playerTwo = new Player(2);

	//Local Variable (Stack Storage)
	int userInput;
	std::string name;

	//Set window screen and title animation
	SetWindow();
	PrintTitle(500);

	//Menu Loop
	while (true) {
		std::cout << "1. Play a Local Multiplayer Game" << std::endl;
		std::cout << "2. Instruction" << std::endl;
		std::cout << "3. Exit Game" << std::endl;

		/*Loop to check for valid user input
		Valid User Input: 1,2
		*/
		while (std::cin >> userInput) {
			if (userInput >= 1 && userInput <= 3)
				break;
		}

		//if user input = 1 Start a game
		if (userInput == 1) {
			//Scope variable
			std::string winner;

			system("cls"); //Clear screen

			//Get name and  create a new player object
			PrintTitle(0);
			std::cout << "Enter Player 1's name: ";
			std::cin >> name;
			playerOne->SetPlayerName(name);
			playerOne->SetPlayerTurn(true);
			system("cls");

			//Get name and create a new player object
			PrintTitle(0);
			std::cout << "Enter Player 2's name: ";
			std::cin >> name;
			playerTwo->SetPlayerName(name);
			system("cls");

			while (true) {

				//Start a local multiplayer game
				winner = LocalMutiPlayer(playerOne, playerTwo, playingBoard);
				system("cls");
				PrintTitle(0);
				std::cout << "The winner is: " << winner << std::endl;
				//End game
				std::cout << "Do you want to play again? "; 
				while (std::cin >> userInput) {
					if (userInput == 1 || userInput == 2)
						break;
				}

				//
				if (userInput == 1) {

				}
			}
		}
		// if the userInput = 3 then exit the game
		else if (userInput == 3)
			break;
	}
	return 0;
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
	int userInputToIndex;

	system("CLS");

	//Game loop
	while (true) {
		//Player1's turn
		if (player1->GetPlayerTurn()) {
			system("CLS");
			PrintTitle(0);
			board->RenderBoard(8, 2, (player1->GetName() + "'s Turn"));
			std::cout << "Please enter a pit position: ";
			while (std::cin >> userInput) {
				userInput[0] = tolower(userInput[0]);
				if (player1->CheckValidMoves(userInput))
					break;
				else
					std::cout << "Enter a valid input (A1-A6): ";
			}

			int userInputToIndex = board->BinarySearchForIndex(userInput, 0, 5);
			player1->PlayerMoves(userInputToIndex, player2, board);
		}
		//Player2's turn
		if (player2->GetPlayerTurn()) {
			system("CLS");
			PrintTitle(0);
			board->RenderBoard(8, 2, (player2->GetName() + "'s Turn"));
			std::cout << "Please enter a pit position: ";
			while (std::cin >> userInput) {
				userInput[0] = tolower(userInput[0]);
				if (player2->CheckValidMoves(userInput))
					break;
				else
					std::cout << "Enter a valid input (B1-B6): ";
			}
			int userInputToIndex = board->BinarySearchForIndex(userInput, 7, 12);
			player2->PlayerMoves(userInputToIndex, player1, board);
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

