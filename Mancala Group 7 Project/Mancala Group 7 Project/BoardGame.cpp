#include "BoardGame.h"
/*
	This function draws the board at the location set in
	the parameter
	@param xLocation This is the location top left corner
					 of the board in the x axis
	@param yLocation This is the location top left corner
					 of the board in the y axis
	@param speciaMessage This is the message to display in
						 the middle of the board
*/
void BoardGame::RenderBoard(int xLocation, int yLocation, std::string specialMessage) {
	//Variables to display the special message to display in the middle
	const int width{ 79 };
	size_t stringLength{ specialMessage.length() };
	if (stringLength % 2 == 0)
		specialMessage += " ";
	size_t remainder = width / 2 - stringLength / 2 + 5;

	//Set to Y axis
	for (int i = 0; i < yLocation; i++) {
		std::cout << std::endl;
	}

	//Cout after indexing to X axis
	std::cout << std::setw(92 + xLocation) << "<------------------------------- Player 2's side ---------------------------" << std::endl;
	std::cout << std::setw(107 + xLocation) << " _______________________________________________________________________________________________________ \n";
	std::cout << std::setw(107 + xLocation) << "|            |            |            |            |            |            |            |            |\n";
	std::cout << std::setw(107 + xLocation) << "|            |    (B1)    |    (B2)    |    (B3)    |    (B4)    |    (B5)    |    (B6)    |            |\n";
	std::cout << std::setw(107 + xLocation) << "|            |            |            |            |            |            |            |            |\n";

	//Print top row of data
	std::cout << std::setfill(' ') << std::setw(14 + xLocation) << "|            ";
	for (int i = 12; i > 6; i--) {
		std::cout << "|     " << std::setw(2) << std::setfill('0') << data[i].boardGameValue << "     ";
	}
	std::cout << "|            |" << std::endl;

	//Continue board printing
	std::cout << std::setfill(' ') << std::setw(107 + xLocation) << "|            |____________|____________|____________|____________|____________|____________|            |\n";
	std::cout << std::setfill(' ') << std::setw(107 + xLocation) << "|            |                                                                             |            |\n";

	//Print out manacala scores line
	std::cout << std::setfill(' ') << std::setw(7 + xLocation) << "|     " << std::setw(2) << std::setfill('0') << data[13].boardGameValue << "     |" << std::setw((width / 2) + stringLength / 2) << std::setfill(' ') << specialMessage << std::setw(remainder)
		<< "|     " << std::setw(2) << std::setfill('0') << data[6].boardGameValue << "     |\n";
	
	//Continue board printing
	std::cout << std::setfill(' ') << std::setw(107 + xLocation) << "|            |_____________________________________________________________________________|            |\n";
	std::cout << std::setfill(' ') << std::setw(107 + xLocation) << "|            |            |            |            |            |            |            |            |\n";

	//Print the bottom row of data
	std::cout << std::setw(14 + xLocation) << "|            ";
	for (int i = 0; i < 6; i++) {
		std::cout << "|     " << std::setw(2) << std::setfill('0') << data[i].boardGameValue << "     ";
	}
	std::cout << "|            |" << std::endl;

	//Continue board printing
	std::cout << std::setfill(' ') << std::setw(107 + xLocation) << "|            |            |            |            |            |            |            |            |\n";
	std::cout << std::setfill(' ') << std::setw(107 + xLocation) << "|            |    (A1)    |    (A2)    |    (A3)    |    (A4)    |    (A5)    |    (A6)    |            |\n";
	std::cout << std::setw(108 + xLocation) << "|____________|____________|____________|____________|____________|____________|____________|____________|\n\n";
	std::cout << std::setw(91 + xLocation) << "------------------------------- Player 1's side --------------------------->" << std::endl;
}

/*
	This function check if the games meets the condition to be ended
	@return True if the condition is met; False if the condition has not been met
*/
bool BoardGame::CheckIfGameEnds() {
	if (data[0].boardGameValue == 0 && data[1].boardGameValue == 0 && data[2].boardGameValue == 0 &&
		data[3].boardGameValue == 0 && data[4].boardGameValue == 0 && data[5].boardGameValue == 0)
		return true;
	else if (data[7].boardGameValue == 0 && data[8].boardGameValue == 0 && data[9].boardGameValue == 0 &&
		data[10].boardGameValue == 0 && data[11].boardGameValue == 0 && data[12].boardGameValue == 0)
		return true;
	else
		return false;
}

/*
	This function adds up all point for two players
*/
void BoardGame::AddUpPoints() {
	//Add up points for player 1
	for (int i = 0; i <= 5; i++) {
		data[6].boardGameValue += data[i].boardGameValue;
		data[i].boardGameValue = 0;
	}

	//Add up points for player 2
	for (int j = 7; j <= 12; j++) {
		data[13].boardGameValue += data[j].boardGameValue;
		data[j].boardGameValue = 0;
	}
}

/*
	This function performs a binary search to find the index
	of the userInput
	@param value The string to search
	@param firstIndex The first index of the array
	@param lastIndex The last index of the array
*/
int BoardGame::BinarySearchForIndex(std::string value) {
	node *arr = this->data;
	int firstIndex, lastIndex, midIndex;

	if (value.at(0) == 'a') {
		firstIndex = 0;
		lastIndex = 5;
	}
	else if (value.at(0) == 'b') {
		firstIndex = 7;
		lastIndex = 12;
	}

	//Start binary search for ascending order
	if (arr[firstIndex].userPosibleChoices < arr[lastIndex].userPosibleChoices) {
		while (firstIndex <= lastIndex) {
			midIndex = (firstIndex + lastIndex) / 2;
			if (arr[midIndex].userPosibleChoices == value)
				return midIndex;
			else if (arr[midIndex].userPosibleChoices < value)
				firstIndex = midIndex + 1;
			else
				lastIndex = midIndex - 1;
		}
		return -1; //If the string doesn't in the array
	}
	//Start binary search for decending order
	else if (arr[firstIndex].userPosibleChoices > arr[lastIndex].userPosibleChoices) {
		while (firstIndex <= lastIndex) {
			midIndex = (firstIndex + lastIndex) / 2;
			if (arr[midIndex].userPosibleChoices == value)
				return midIndex;
			else if (arr[midIndex].userPosibleChoices < value)
				lastIndex = midIndex - 1;
			else
				firstIndex = midIndex + 1;
		}
		return -1; //If the string doesn't in the array
	}
}