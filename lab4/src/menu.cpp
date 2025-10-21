#include <iostream>
#include "../includes/cargoCarrier.h"
#include "../includes/utils.h"
#include "../includes/car.h"
#include "../includes/airplane.h"
#include "../includes/train.h"

void showMenu()
{
	std::cout << "\n+======================================================================+" << std::endl;
	std::cout << "Menu" << std::endl;
	std::cout << "1.Add a carrier type." << std::endl;
	std::cout << "2.Information display (price and travel time for a specific city)." << std::endl;
	std::cout << "3.End of the program." << std::endl;
	std::cout << "+======================================================================+" << std::endl;
	std::cout << "Select an action: ";
}

void showMenuCarrier()
{
	std::cout << "\n+========================+" << std::endl;
	std::cout << "Carrier selection menu" << std::endl;
	std::cout << "1.Car." << std::endl;
	std::cout << "2.Airplane." << std::endl;
	std::cout << "3.Train." << std::endl;
	std::cout << "+========================+" << std::endl;
	std::cout << "Select an action: ";
}

void menu()
{
	CargoCarrier** carriers = nullptr;
	int size = 0;
	int cap = 1;

	int opt;
	showMenu();

	while (true)
	{
		opt = validInt(1, 3);
		switch (opt) {
		case 1:
			addCarrier(carriers, &size, &cap);
			std::cout << "Select an action:" << std::endl;
			break;
		case 2:
			showInfo(size, carriers);
			std::cout << "Select an action:" << std::endl;
			break;
		case 3:
			std::cout << "Program completed." << std::endl;
			return;
		default:
			std::cout << "Select an action:" << std::endl;
		}
	}
}

void chooseCarriers(int size, CargoCarrier**& carriers)
{
	int opt;
	int temp;
	showMenuCarrier();
	while (true)
	{
		opt = validInt(1, 3);
		switch (opt) {
		case 1:
			std::cout << "Enter distance:" << std::endl;
			temp = validInt(1, kMaxInt);
			carriers[size - 1] = new Car(temp);
			return;
		case 2:
			std::cout << "Enter distance:" << std::endl;
			temp = validInt(1, kMaxInt);
			carriers[size - 1] = new Airplane(temp);
			return;
		case 3:
			std::cout << "Enter distance:" << std::endl;
			temp = validInt(1, kMaxInt);
			carriers[size - 1] = new Train(temp);
			return;
		default:
			std::cout << "Select an item from the menu!" << std::endl;
		}
	}
}
