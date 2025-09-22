#include <iostream>
#include "../includes/mystr.h"
#include "../includes/utils.h"

void showMenu()
{
	std::cout << "\n���� " << std::endl;
	std::cout << "1.���� ������." << std::endl;
	std::cout << "2.����� ������." << std::endl;
	std::cout << "3.����� ������������ �����." << std::endl;
	std::cout << "4.����� ������ ���������." << std::endl;
	std::cout << "�������� �������: ";
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
			std::cout << "�������� ����� �� ����:" << std::endl;
			break;
		case 2:
			system("cls");
			firststr.printString();
			showMenu();
			break;
		case 3:
			if (firststr.getString() == nullptr)
			{
				std::cout << "������� ������� ������ ������!" << std::endl;
				continue;
			}

			secondstr.input();

			newstr = firststr.contacanateStrings(firststr.getString(), secondstr.getString());
			std::cout << "\n���� ������������ ������:\n" << newstr << std::endl;
			delete[] newstr;
			showMenu();
			break;
		case 4:
			std::cout << "��������� ���������." << std::endl;
			return;
		default:
			std::cout << "�������� ����� �� ����!" << std::endl;
		}
	}
}


