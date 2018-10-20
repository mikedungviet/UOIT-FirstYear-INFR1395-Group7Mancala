#include <iostream>
#include <Windows.h>

void SetWindow() {
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r); //stores the console's current dimensions

	MoveWindow(console, r.left, r.top, 1050, 750, TRUE); // 1250 width, 100 height
}

void PrintTitle(int delay) {
	std::cout << " .----------------.  .----------------.  .-----------------. .----------------.  .----------------.  .----------------.  .----------------. " << std::endl;
	std::cout << "| .--------------. || .--------------. || .--------------. || .--------------. || .--------------. || .--------------. || .--------------. |" << std::endl;
	Sleep(delay);
	std::cout << "| | ____    ____ | || |      __      | || | ____  _____  | || |     ______   | || |      __      | || |   _____      | || |      __      | |" << std::endl;
	Sleep(delay);
	std::cout << "| ||_   \\  /   _|| || |     /  \\     | || ||_   \\|_   _| | || |   .' ___  |  | || |     /  \\     | || |  |_   _|     | || |     /  \\     | |" << std::endl;
	Sleep(delay);
	std::cout << "| |  |   \\/   |  | || |    / /\\ \\    | || |  |   \\ | |   | || |  / .'   \\_|  | || |    / /\\ \\    | || |    | |       | || |    / /\\ \\    | |" << std::endl;
	Sleep(delay);
	std::cout << "| |  | |\\  /| |  | || |   / ____ \\   | || |  | |\\ \\| |   | || |  | |         | || |   / ____ \\   | || |    | |   _   | || |   / ____ \\   | |" << std::endl;
	Sleep(delay);
	std::cout << "| | _| |_\\/_| |_ | || | _/ /    \\ \\_ | || | _| |_\\   |_  | || |  \\ `.___.'\\  | || | _/ /    \\ \\_ | || |   _| |__/ |  | || | _/ /    \\ \\_ | |" << std::endl;
	Sleep(delay);
	std::cout << "| ||_____||_____|| || ||____|  |____|| || ||_____|\\____| | || |   `._____.'  | || ||____|  |____|| || |  |________|  | || ||____|  |____|| |" << std::endl;
	Sleep(delay);
	std::cout << "| |              | || |              | || |              | || |              | || |              | || |              | || |              | |" << std::endl;
	Sleep(delay);
	std::cout << "| '--------------' || '--------------' || '--------------' || '--------------' || '--------------' || '--------------' || '--------------' |" << std::endl;
	std::cout << " '----------------'  '----------------'  '----------------'  '----------------'  '----------------'  '----------------'  '----------------' " << std::endl;
	std::cout << "___________________________________________________________________________________________________________________________________________" << std::endl;
}