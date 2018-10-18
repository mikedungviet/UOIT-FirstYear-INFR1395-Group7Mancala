#pragma once
//Header files
#include <iostream>
#include <string>
#include <iomanip>


class BoardGame
{
private:
	//Create a data stucture
	struct node
	{
		int boardGameValue;
		std::string userPosibleChoices;
	};
	node *testing = new node[14];

public:
	/*
		This is a default constructor. It will initalize
		the board array at initial stage

		Note: For loop didn't work for all elements
			  need to figure out a correct for loop
		
	*/
	BoardGame() {
		testing[0].boardGameValue = 4;
		testing[1].boardGameValue = 4;
		testing[2].boardGameValue = 4;
		testing[3].boardGameValue = 4;
		testing[4].boardGameValue = 4;
		testing[5].boardGameValue = 4;
		testing[6].boardGameValue = 0; //Mancala Score
		testing[7].boardGameValue = 4;
		testing[8].boardGameValue = 4;
		testing[9].boardGameValue = 4;
		testing[10].boardGameValue = 4;
		testing[11].boardGameValue = 4;
		testing[12].boardGameValue = 4;
		testing[13].boardGameValue = 0; //Mancala Score

		testing[0].userPosibleChoices = "a1";
		testing[1].userPosibleChoices = "a2";
		testing[2].userPosibleChoices = "a3";
		testing[3].userPosibleChoices = "a4";
		testing[4].userPosibleChoices = "a5";
		testing[5].userPosibleChoices = "a6";
		testing[6].userPosibleChoices = "no"; //Mancala Score
		testing[7].userPosibleChoices = "a1";
		testing[8].userPosibleChoices = "a2";
		testing[9].userPosibleChoices = "a3";
		testing[10].userPosibleChoices = "a4";
		testing[11].userPosibleChoices = "a5";
		testing[12].userPosibleChoices = "a6";
		testing[13].userPosibleChoices = "no";

	}
	/*
		Deconstructor
	*/
	~BoardGame() {

	}

	/*
		Gets the value of Board Game Value in node at an index
		@param index This is the location within the array
		@return Returns the value as an int
	*/
	int GetBoardGameArray(int index) {
		return testing[index].boardGameValue;
	}

	/*
		Get the string of User Posible choices in Node array
		at an index
		@param index This is the location within the array
		@return Returns the string 
	*/
	std::string GetUserChoice(int index) {
		return testing[index].userPosibleChoices;
	}

	/*
		This function sets the value of Board Game Value 
		at the index to 0
		@param index The location in the array
	*/
	void SetValueToZero(int index) {
		testing[index].boardGameValue = 0;
	}

	/*
		This function sets the value of Board Game Value
		at the index to another value
		@param index The location in the array
		@param value The value to set to
	*/
	void SetValueToAnother(int index, int value) {
		testing[index].boardGameValue = value;
	}


	/*
	*/
	void PrintArray() {
		for (int i = 0; i < 14; i++) {
			std::cout << "I: " << i << " value: " << testing[i].boardGameValue << std::endl;
		}
	}

	//Class member function
	void RenderBoard(int xLocation, int yLocation);
};

