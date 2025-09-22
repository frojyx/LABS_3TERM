#include <iostream>
#include "../includes/array.h"
#include "../includes/utils.h"

void showMenu()
{
	std::cout << "\nМеню" << std::endl;
	std::cout << "1.Ввод массива." << std::endl;
	std::cout << "2.Вывод массива." << std::endl;
	std::cout << "3.Вывод увеличенного массива." << std::endl;
	std::cout << "4.Конец работы программы." << std::endl;
	std::cout << "Выберете дейстие: ";
}

void menu()
{
	Array arr;
	int opt;
	showMenu();

	while (true)
	{
		opt = validInt();
		switch (opt) {
		case 1:
			inputArray(arr);
			std::cout << "Выберите пункт меню:" << std::endl;
			break;
		case 2:
			system("cls");
			std::cout << "Ваш массив:" << std::endl;
			showArray(arr);
			std::cout << std:: endl;
			showMenu();
			break;
		case 3:

			if (!increment(arr)) {
				std::cout << "Выберите пункт меню:" << std::endl;
				continue;
			}
			system("cls");
			std::cout << "Ваш увеличенный массив:" << std::endl;
			showArray(arr);
			std::cout << std::endl;
			showMenu();
			break;
		case 4:
			std::cout << "Программа завершена." << std::endl;
			return;
		default:
			std::cout << "Выберите пункт из меню!" << std::endl;
		}
	}
}