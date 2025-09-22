#include <iostream>
#include "../includes/array.h"
#include "../includes/utils.h"

void showMenu()
{
	std::cout << "\n����" << std::endl;
	std::cout << "1.���� �������." << std::endl;
	std::cout << "2.����� �������." << std::endl;
	std::cout << "3.����� ������������ �������." << std::endl;
	std::cout << "4.����� ������ ���������." << std::endl;
	std::cout << "�������� �������: ";
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
			std::cout << "�������� ����� ����:" << std::endl;
			break;
		case 2:
			system("cls");
			std::cout << "��� ������:" << std::endl;
			showArray(arr);
			std::cout << std:: endl;
			showMenu();
			break;
		case 3:

			if (!increment(arr)) {
				std::cout << "�������� ����� ����:" << std::endl;
				continue;
			}
			system("cls");
			std::cout << "��� ����������� ������:" << std::endl;
			showArray(arr);
			std::cout << std::endl;
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