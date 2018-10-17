#include <iostream>
//#include "movement.cpp"
#include <string>

void movePieces(int[], std::string[], int, int, std::string);

int main() {
	int numArr[12] = { 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4 };
	std::string wordArr[12] = { "A1", "A2", "A3", "A4", "A5", "A6", "B1", "B2", "B3", "B4", "B5", "B6" };

	int goal1 = 0, goal2 = 0;
	std::string test;

	//Asks user to select a hole to move pieces out of
	std::cout << "Enter a position (A1, A2, A3, A4, A5, A6, B1, B2, B3, B4, B5, B6): ";
	std::cin >> test;

	movePieces(numArr, wordArr, goal1, goal2, test);


	//std::cout << "Hello World!" << std::endl;
	system("pause");
	return 0;
}

void movePieces(int arrNum[], std::string arrString[], int goal1, int goal2, std::string coord ) {
	//std::string test;
	int piecesToMove;
	int index = 0;

	//Checks what value the user entered
	for (int i = 0; i < 12; i++) {
		if (coord == arrString[i]) {
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