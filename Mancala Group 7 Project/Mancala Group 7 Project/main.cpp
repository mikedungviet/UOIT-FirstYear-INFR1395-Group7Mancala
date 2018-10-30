/*
	Group 7
	Members:
		Mike Pham (100706123)
		Katy Blackstone (100717941)
		Mikel Devlin (100725745)
		Jonah Griffin (100702748)
		Robert Knight (100670811)
*/
#include <iostream>
#include <string>
#include <stdlib.h>
#include "BoardGame.h"
#include "Player.h"


//Function Prototype
void SetWindow();
void PrintTitle(int);
std::string LocalMutiPlayer(Player*, Player*, BoardGame*);
std::string *GetandSetName(std::string);
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
	while (true) {
		//Menu loop
		system("cls");
		
		choice = FirstMenu();
		//if user input = 1 Start a game
		if (choice == 1) {
			//Heap Storage
			BoardGame *playingBoard = new BoardGame;
			std::string *stri = new std::string;
			
			//Scope variable
			std::string winner;
			system("cls"); //Clear screen

			//Get name and  create a new player object
			stri = GetandSetName("Player 1");
			Player *playerOne = new Player(1, stri); 
			stri = GetandSetName("Player 2");
			Player *playerTwo = new Player(2, stri);

			//Start game
			winner = LocalMutiPlayer(playerOne, playerTwo, playingBoard);
			system("cls");
			playingBoard->RenderBoard(8, 2, winner + " wins");
			system("pause");

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
	@return Returns the stored address
*/
std::string *GetandSetName(std::string playerNum) {
	std::string *name = new std::string;
	PrintTitle(0);
	std::cout << "Enter " << playerNum << "'s name: ";
	getline(std::cin, *name);
	system("cls");
	return name;
}



