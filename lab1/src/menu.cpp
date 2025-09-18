#include <iostream>
#include "../includes/mystr.h"
#include "../includes/utils.h"

void showMenu()
{
	std::cout << "\nМеню " << std::endl;
	std::cout << "1.Ввод строки." << std::endl;
	std::cout << "2.Вывод строки." << std::endl;
	std::cout << "3.Вывод объединенных строк." << std::endl;
	std::cout << "4.Конец работы программы." << std::endl;
	std::cout << "Выберете дейстие: ";
}

void menu()
{
	myString firststr;
	myString secondstr;
	char* newstr = nullptr;

	int opt;
	showMenu();

	while (true)
	{
		opt = validInt();
		switch (opt) {
		case 1:
			firststr.input();
			std::cout << "Выберите пункт из меню:" << std::endl;
			break;
		case 2:
			system("cls");
			firststr.printString();
			showMenu();
			break;
		case 3:
			if (firststr.getString() == nullptr)
			{
				std::cout << "Вначале введите первую строку!" << std::endl;
				continue;
			}

			secondstr.input();

			newstr = firststr.contacanateStrings(firststr.getString(), secondstr.getString());
			std::cout << "\nВаша объединненая строка:\n" << newstr << std::endl;
			delete[] newstr;
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


