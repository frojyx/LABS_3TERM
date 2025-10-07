#include <iostream>
#include "../includes/PassengerCarrier.h"
#include "../includes/utils.h"
#include "../includes/car.h"
#include "../includes/airplane.h"
#include "../includes/train.h"

void showMenu()
{
	std::cout << "\n+==========================================================+" << std::endl;
	std::cout << "Меню" << std::endl;
	std::cout << "1.Добавить вид пассажироперевозчика." << std::endl;
	std::cout << "2.Вывод информации(цена и время на определенной дистанции)." << std::endl;
	std::cout << "3.Конец работы программы." << std::endl;
	std::cout << "+==========================================================+" << std::endl;
	std::cout << "Выберете дейстие: ";
}

void showMenuCarrier()
{
	std::cout << "\n+========================+" << std::endl;
	std::cout << "Меню выбора транспорта" << std::endl;
	std::cout << "1.Добавить машину." << std::endl;
	std::cout << "2.Добавить самолёт." << std::endl;
	std::cout << "3.Добавить поезд." << std::endl;
	std::cout << "+========================+" << std::endl;
	std::cout << "Выберете дейстие: ";
}

void menu()
{
	PassengerCarrier** carriers = nullptr;
	int size = 0;
	int cap = 1;

	int opt;
	showMenu();

	while (true)
	{
		opt = validInt(1,3);
		switch (opt) {
		case 1:
			addCarrier(carriers, &size, &cap);
			std::cout << "Выберите пункт меню:" << std::endl;
			break;
		case 2:
			showInfo(size, carriers);
			std::cout << "Выберите пункт меню:" << std::endl;
			break;
		case 3:
			std::cout << "Программа завершена." << std::endl;
			return;	
		default:
			std::cout << "Выберите пункт из меню!" << std::endl;
		}
	}
}

void chooseCarriers(int size, PassengerCarrier**& carriers)
{
	int opt;
	showMenuCarrier();
	while (true)
	{
		opt = validInt(1, 3);
		switch (opt) {
		case 1:
			std::cout << "Введите дистанцию:" << std::endl;
			carriers[size - 1] = new Car;
			return;
		case 2:
			std::cout << "Введите дистанцию:" << std::endl;
			carriers[size - 1] = new Airplane;
			return;
		case 3:
			std::cout << "Введите дистанцию:" << std::endl;
			carriers[size - 1] = new Train;
			return;
		default:
			std::cout << "Выберите пункт из меню!" << std::endl;
		}
	}
}
