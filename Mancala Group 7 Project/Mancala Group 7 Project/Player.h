#pragma once
#include <string>
class Player
{
private:
	std::string *name = new std::string;
	int *playerMancalaLocation = new int;
	std::string *validUserInput = new std::string[6];
	bool *playerTurn = new bool;
public:
	//Default constructor
	Player() {}

	//Player constructor
	Player(std::string *_name, int _playerNumber) :name{ _name } {
		if (_playerNumber == 1) {
			std::string tempArr[6] = { "a1","a2","a3","a4","a5","a6" };
			std::copy(tempArr, tempArr + 6, validUserInput);
			*playerMancalaLocation = 6;
		}
		else if (_playerNumber == 2) {
			std::string tempArr[6] = { "b1","b2","b3","b4","b5","b6" };
			std::copy(tempArr, tempArr + 6, validUserInput);
			*playerMancalaLocation = 13;
		}
	}

	/*
		This function gets the name of the player
		@return Returns the name (Dereference the pointer)
	*/
	std::string GetName() {
		return *name;
	}

	/*
		This function returns the string array
		@return
	*/
	std::string *GetValidUserInput() {
		return validUserInput;
	}

	//Member function
	bool CheckValidMoves(std::string, int = 0, int = 5);
};

