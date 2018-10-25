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
	node *data = new node[14];

public:
	/*
		This is a default constructor. It will initalize
		the board array at initial stage

	*/
	BoardGame() {
		for (int i = 0; i <= 13; i++) {
			if (i == 6 || i == 13) {
				data[i].boardGameValue = 0;
				data[i].userPosibleChoices = "no";
				continue;
			}
			data[i].boardGameValue = 4;
		}

		//data[12].boardGameValue = 11;
		
		data[0].userPosibleChoices = "a1";
		data[1].userPosibleChoices = "a2";
		data[2].userPosibleChoices = "a3";
		data[3].userPosibleChoices = "a4";
		data[4].userPosibleChoices = "a5";
		data[5].userPosibleChoices = "a6";
		data[7].userPosibleChoices = "b6";
		data[8].userPosibleChoices = "b5";
		data[9].userPosibleChoices = "b4";
		data[10].userPosibleChoices = "b3";
		data[11].userPosibleChoices = "b2";
		data[12].userPosibleChoices = "b1";

	}
	/*
		Deconstructor
	*/
	~BoardGame() {
		
	}
	/*
		This function resets the boardGameValue to original
	*/
	void ResetBoardValue() {
		for (int i = 0; i <= 13; i++) {
			if (i == 6 || i == 3) {
				data[i].boardGameValue = 0;
				continue;
			}
			data[i].boardGameValue = 4;
		}
	}

	/*
		Gets the value of Board Game Value in node at an index
		@param index This is the location within the array
		@return Returns the value as an int
	*/
	int GetBoardGameArray(int index) {
		return data[index].boardGameValue;
	}

	/*
		Get the string of User Posible choices in Node array
		at an index
		@param index This is the location within the array
		@return Returns the string 
	*/
	std::string GetUserChoice(int index) {
		return data[index].userPosibleChoices;
	}

	/*
		This function sets the value of Board Game Value 
		at the index to 0
		@param index The location in the array
	*/
	void SetValueToZero(int index) {
		data[index].boardGameValue = 0;
	}

	/*
		This function sets the value of Board Game Value
		at the index to another value
		@param index The location in the array
		@param value The value to set to
	*/
	void IncreaseValueby1(int index) {
		data[index].boardGameValue ++;
	}
	
	/*
	*/
	void SetValue(int index, int value) {
		data[index].boardGameValue = value;
	}

	/*
		Print the array (For Testing purpose)
	*/
	void PrintArray() {
		for (int i = 0; i < 14; i++) {
			std::cout << "I: " << i << " value: " << data[i].boardGameValue << std::endl;
		}
	}

	//Class member function
	void RenderBoard(int xLocation, int yLocation, std::string);
	bool CheckIfGameEnds();
	void AddUpPoints();
	int BinarySearchForIndex(std::string);
};

