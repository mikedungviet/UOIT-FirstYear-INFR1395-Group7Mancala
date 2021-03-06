#pragma once
#include <string>
#include "BoardGame.h"
class Player
{
private:
	std::string *name = new std::string;
	int *playerMancalaLocation = new int;
	std::string *validUserInput = new std::string[6];
	bool *playerTurn = new bool;
public:
	//Player constructor
	Player(int _playerNumber, std::string *_name) : name{ _name } {
		*playerTurn = false;
		if (_playerNumber == 1) {
			std::string tempArr[6] = { "a1","a2","a3","a4","a5","a6" };
			std::copy(tempArr, tempArr + 6, validUserInput);
			*playerMancalaLocation = 6;
			*playerTurn = true;
		}
		else if (_playerNumber == 2) {
			std::string tempArr[6] = { "b1","b2","b3","b4","b5","b6" };
			std::copy(tempArr, tempArr + 6, validUserInput);
			*playerMancalaLocation = 13;
		}
	}
	~Player() {
		delete name;
		delete playerMancalaLocation;
		delete validUserInput;
		delete playerTurn;
	}

	/*
		This function gets the name of the player
		@return Returns the name (Dereference the pointer)
	*/
	std::string GetName() {
		return *name;
	}


	/*
		This function gets the string at the index location
		of the validUserInput array
		@return Return the string
	*/
	std::string GetValidUserInput(int location) {
		return validUserInput[location];
	}

	/*
		This function returns the player turn
		@return Return the Player Turn
	*/
	bool GetPlayerTurn() {
		return *playerTurn;
	}

	/*
		This function returns the index of the player's
		mancala
	*/
	int GetPlayerMancalaIndex() {
		return *playerMancalaLocation;
	}

	/*
		This function set the player turn
	*/
	void SetPlayerTurn(bool turn) {
		*playerTurn = turn;
	}

	

	//Member function
	int CheckValidMoves(std::string, int = 0, int = 5);
	void PlayerMoves(int, Player *, BoardGame *);

protected:
	//Protected function
	void PerformSteal(int index, Player *opponent, BoardGame *board);
};

