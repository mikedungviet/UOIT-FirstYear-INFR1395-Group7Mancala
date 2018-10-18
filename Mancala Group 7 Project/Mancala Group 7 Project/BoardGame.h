#pragma once
//Header files
#include <iostream>
#include <string>
#include <iomanip>


class BoardGame
{
private:
	struct node
	{
		int boardGameArray;
		std::string userChoice;
	};
	node *testing = new node[14];

public:
	/*
		This is a default constructor. It will initalize
		the board array at initial stage
	*/
	BoardGame() {
		for (int i = 0; i < 14; i++) {
			//Set the mancala goals
			if (i == 6 || i == 13) {
				testing[i].boardGameArray = 0;
				testing[i].userChoice = "";
			}
			//Set the pits to their default
			else {
				testing[i].boardGameArray = 4;
				if (i <= 6)
					testing[i].userChoice = "a" + std::to_string(i++);
				else if (i >= 7) {
					testing[i].userChoice = "b" + std::to_string(i++);
				}
			}
		}
	}
	/*
		Deconstructor
	*/
	~BoardGame() {

	}

	int GetBoardGameArray(int index) {
		return testing[index].boardGameArray;
	}

	std::string GetUserChoice(int index) {
		return testing[index].userChoice;
	}

	//Class member function
	void RenderBoard(int xLocation, int yLocation);
};

