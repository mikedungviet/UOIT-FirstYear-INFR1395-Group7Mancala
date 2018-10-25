#include <iostream>
#include <string>
#include <stdlib.h>
#include "BoardGame.h"
#include "Player.h"


//Function Prototype
void SetWindow();
void PrintTitle(int);
std::string LocalMutiPlayer(Player*, Player*, BoardGame*);
void GetandSetName(Player *, std::string);
int FirstMenu();
std::string LocalMutiPlayer(Player *, Player *, BoardGame *);
void instructions();

int main()
{
	//Local Variable (Stack Storage)
	int choice;
	std::string name;

	//Set window screen and title animation
	SetWindow();
	PrintTitle(375);
	while (true) {
		//Menu loop
		choice = FirstMenu();
		//if user input = 1 Start a game
		if (choice == 1) {
			//Heap Storage
			BoardGame *playingBoard = new BoardGame;
			Player *playerOne = new Player(1);
			Player *playerTwo = new Player(2);

			//Scope variable
			std::string winner;
			system("cls"); //Clear screen

			//Get name and  create a new player object
			GetandSetName(playerOne, "Player 1");
			//Get name and create a new player object
			GetandSetName(playerTwo, "Player 2");

			//Start game
			winner = LocalMutiPlayer(playerOne, playerTwo, playingBoard);
			
			system("cls");
			playingBoard->RenderBoard(8, 2, winner + " wins");


			//Delete Memory
			delete playingBoard;
			delete playerOne;
			delete playerTwo;

			continue;
		}
		//Print instruction
		else if (choice == 2) {
			system("cls");
			instructions();
			system("Pause");
			system("cls");
			PrintTitle(0);
			continue;
		}
		else if (choice == 3) {
			return 0;
		}
	}
}

/*
	This function sets the name of the player
	@param *player The player to set the name
	@param playerNum The player number to display
*/
void GetandSetName(Player *player, std::string playerNum) {
	std::string name;
	PrintTitle(0);
	std::cout << "Enter " << playerNum << "'s name: ";
	std::cin >> name;
	player->SetPlayerName(name);
	system("cls");
}



