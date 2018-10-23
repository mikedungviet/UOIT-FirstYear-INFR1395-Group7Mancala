#include "Player.h"
#include <stdlib.h>
#include <Windows.h>

/*
	This function performs a binary search to find a string
	@param arr[] The array to search in
	@param lastIndex The bigger side of Array
	@param value The value to search for
	@param firstIndex The smaller side of Array
	@return Return true if found
			Return false if not found
*/
bool Player::CheckValidMoves(std::string value, int firstIndex, int lastIndex) {
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
	return false;
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
		if (CheckValidMoves(board->GetUserChoice(index))) {
			
			if (board->GetBoardGameArray(index) == 1) {
				for (int i = 0; i < board->GetBoardGameArray(index + 6);i++) {
					
				}

				board->SetValueToZero(index + 6);
				board->SetValueToZero(index);	
			}
		}
			

		//Special Cases go above
		system("cls");
		board->RenderBoard(8,2,"");
		Sleep(500);
	}
}



