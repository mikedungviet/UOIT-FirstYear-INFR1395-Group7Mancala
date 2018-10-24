#include "Player.h"
#include <stdlib.h>
#include <Windows.h>
#include <string>

/*
	This function performs a binary search to find a string
	@param arr[] The array to search in
	@param lastIndex The bigger side of Array
	@param value The value to search for
	@param firstIndex The smaller side of Array
	@return Return true if found
			Return false if not found
*/
int Player::CheckValidMoves(std::string value, int firstIndex, int lastIndex) {
	//
	std::string *arr = this->validUserInput;
	if (firstIndex <= lastIndex) {
		int midIndex = (firstIndex + lastIndex) / 2;

		//If the value is equal to mid
		if (value.compare(arr[midIndex]) == 0)
			return true;
		//If the value is lower than mid
		else if (arr[midIndex] > value)
			return CheckValidMoves(value, 0, midIndex - 1);
		//If the value is higher than mid
		else if (arr[midIndex] < value)
			return CheckValidMoves(value, midIndex + 1);
	}
	return -1;
}
/*
	This function performs a steal
	@param index The index where the steal will perform
	@param *opponent An instance of the opponent player object
	@param *board An instance of a board object
*/
void Player::PerformSteal(int index, Player *opponent, BoardGame *board) {
	//pseudo code
	//If the conditions are not met, return;
	int newIndex(0);
	int subIndex = CheckValidMoves(board->GetUserChoice(index));
	if (subIndex == -1 || board->GetBoardGameArray(index)!= 1)
		return;
	//ets the string of ValidUserChoice of the opponent at the subIndex
	std::string *location = new std::string;
	*location = opponent->GetValidUserInput(subIndex);
	//Search the returned string (from above) using board binary search to get the
	//new index
	if (location[0]=="a") {
		//If the first char is a then search from 0 to 5
		newIndex=board->BinarySearchForIndex(*location, 0, 5);
	}
	else if (location[0]=="b"){
		//If the first char is b then search from 7 to 12
		newIndex=board->BinarySearchForIndex(*location, 7, 12);
	}
	board->SetValue(*playerMancalaLocation, newIndex + 1);
	board->SetValue(newIndex, 0);
	board->SetValue(subIndex, 0);
	//Set the value at new index to 0 and Adding the value to player's Mancala
	//Set the value at index to 0 and add the value to player's Mancala
}


/*
	This function performs a set of steps to change the score board
	@param index The index where the player chose
	@param *opponent An instance of a Player object
	@param *board The address of the board

*/
void Player::PlayerMoves(int index, Player *opponent, BoardGame *board) {
	//Change turn
	*playerTurn = false;
	opponent->SetPlayerTurn(true);

	system("cls");//Clear screen

	//Get the counter and set the value at index to 0
	int counter = board->GetBoardGameArray(index);
	board->SetValueToZero(index);

	//Main loop
	for (counter; counter > 0; counter--) {
		index++;
		if (index > 13)
			index = 0;

		//Skip the opponent's mancala if index is equal to theirs
		if (index == opponent->GetPlayerMancalaIndex()) {
			counter++;
			continue;
		}

		board->IncreaseValueby1(index);

		//Special Cases go under
		if (counter == 1) {
			PerformSteal(index, opponent, board);
		}
		//Condition for getting a free turn
		if (index == *playerMancalaLocation) {
			*playerTurn = true;
			opponent->SetPlayerTurn(false);
		}
	}
		//Special Cases go above
		system("cls");
		board->RenderBoard(8,2,"");
		Sleep(500);
}



