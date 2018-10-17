#include <iostream>
#include <string>

void movePieces(int arrNum[], std::string arrString[], int goal1, int goal2, std::string coord ) {
	std::string test;
	int piecesToMove;
	int index = 0;

	//Checks what value the user entered
	for (int i = 0; i < 12; i++) {
		if (test == arrString[i]) {
			piecesToMove = arrNum[i];
			std::cout << arrNum[1];
			arrNum[i] = 0;
			i = index;
		}
	}

	for (int i = piecesToMove; i > 0; i--) {
		index++;
		arrNum[index] ++;
		if (index == 6) {
			goal1++;
		}
		if (index == 12) {
			goal2++;
			index = 0;
		}
	}

	for (int i = 0; i < 12; i++) {
		std::cout << arrNum[i] << " ";
	}

}