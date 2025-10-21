#include <iostream>
#include "../includes/utils.h"

void showMenu()
{
	std::cout << "\n+======================================================================+" << std::endl;
	std::cout << "Menu" << std::endl;
	std::cout << "1.Swap in integer array(int)." << std::endl;
	std::cout << "2.Swap in double array(double)." << std::endl;
	std::cout << "3.Swap in character array(char)." << std::endl;
	std::cout << "4.Exit programm." << std::endl;
	std::cout << "+======================================================================+" << std::endl;
	std::cout << "Select an action: ";
}

void menu()
{
	int opt;
	showMenu();

	while (true)
	{
		opt = getValue<int>("");
		switch (opt) {
		case 1:
			runProgram<int>("int");
			std::cout << "Select an action: ";
			break;
		case 2:
			runProgram<double>("double");
			std::cout << "Select an action: ";
			break;
		case 3:
			runProgram<char>("char");
			std::cout << "Select an action: ";
			break;
		case 4:
			std::cout << "Exiting program.";
			return;
		default:
			std::cout << "Select an MENU action:" << std::endl;
		}
	}
}
