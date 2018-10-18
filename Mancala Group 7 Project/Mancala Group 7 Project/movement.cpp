#include <iostream>
#include <string>

void movePieces(int arrNum[], std::string arrString[], int goal1, int goal2, std::string coord ) {
	int piecesToMove;
	int index = 0;
	//Checks what value the user entered
	for (int i = 0; i < 14; i++) {
		if (coord == arrString[i]) {
			piecesToMove = arrNum[i];
			arrNum[i] = 0;
			index = i;
		}
	}

	for (int o = piecesToMove; o > 0; o--) {
		index++;
		arrNum[index] ++;
		if (index == 13) {
			index = -1;
		}
		/*if (index == 5) {
			goal1++;
			index++;
		}
		else if (index == 11) {
			goal2++;
			index = 0;
		}
		else {
			index++;
			arrNum[index] ++;
		}*/
	}

	for (int p = 0; p < 14; p++) {
		if (p == 6) {
			std::cout << "GOAL: " << arrNum[p] << "\n";
		}
		else if (p == 13) {
			std::cout << "GOAL: " << arrNum[p] << "\n";
		}
		else {
			std::cout << arrNum[p] << " ";
		}
	}

}