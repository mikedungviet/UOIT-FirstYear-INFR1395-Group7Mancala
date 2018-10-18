#pragma once
//Header files
#include <iostream>
#include <iomanip>


class BoardGame
{
private:
	int boardGameArray[14];
public:
	/*
		This is a default constructor. It will initalize
		the board array at initial stage
	*/
	BoardGame() {
		int tempArr[]{ 4,4,4,4,4,4,0,4,4,4,4,4,4,0 };
		std::copy(tempArr, tempArr + 14, boardGameArray);
	}
	/*
		Deconstructor
	*/
	~BoardGame() {

	}

	//Class member function
	void RenderBoard(int xLocation, int yLocation);
};

