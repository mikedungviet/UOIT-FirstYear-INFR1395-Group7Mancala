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
		
		testing[0].boardGameArray = 4;
		testing[1].boardGameArray = 4;
		testing[2].boardGameArray = 4;
		testing[3].boardGameArray = 4;
		testing[4].boardGameArray = 4;
		testing[5].boardGameArray = 4;
		testing[6].boardGameArray = 0;
		testing[7].boardGameArray = 4;
		testing[8].boardGameArray = 4;
		testing[9].boardGameArray = 4;
		testing[10].boardGameArray = 4;
		testing[11].boardGameArray = 4;
		testing[12].boardGameArray = 4;
		testing[13].boardGameArray = 0;

		
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

	void PrintArray() {
		for (int i = 0; i <= 13; i++)
			std::cout << i << ": " << testing[i].boardGameArray << std::endl;
	}

	//Class member function
	void RenderBoard(int xLocation, int yLocation);
};

