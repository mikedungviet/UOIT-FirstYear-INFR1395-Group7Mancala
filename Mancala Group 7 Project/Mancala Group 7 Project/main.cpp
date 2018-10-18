#include <iostream>
#include <string>

void movePieces(int[], std::string[], int, int, std::string);

int main() {
	int numArr[14] = { 4, 4, 4, 4, 4, 4, 0, 4, 4, 4, 4, 4, 4, 0 };
	std::string wordArr[14] = { "A1", "A2", "A3", "A4", "A5", "A6", "no", "B1", "B2", "B3", "B4", "B5", "B6", "no" };

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