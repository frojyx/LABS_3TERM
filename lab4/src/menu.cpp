#include <iostream>
#include "../includes/cargoCarrier.h"
#include "../includes/utils.h"
#include "../includes/car.h"
#include "../includes/airplane.h"
#include "../includes/train.h"

void showMenu()
{
	std::cout << "\n+======================================================================+" << std::endl;
	std::cout << "Меню" << std::endl;
	std::cout << "1.Добавить вид грузоперевозчика." << std::endl;
	std::cout << "2.Вывод информации(цена и время на дистанции для определенного города)." << std::endl;
	std::cout << "3.Конец работы программы." << std::endl;
	std::cout << "+======================================================================+" << std::endl;
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
			std::cout << "Введите дистанцию:" << std::endl;
			temp = validInt(1, kMaxInt);
			carriers[size - 1] = new Car(temp);
			return;
		case 2:
			std::cout << "Введите дистанцию:" << std::endl;
			temp = validInt(1, kMaxInt);
			carriers[size - 1] = new Airplane(temp);
			return;
		case 3:
			std::cout << "Введите дистанцию:" << std::endl;
			temp = validInt(1, kMaxInt);
			carriers[size - 1] = new Train(temp);
			return;
		default:
			std::cout << "Выберите пункт из меню!" << std::endl;
		}
	}
}
