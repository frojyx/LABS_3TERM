#include <iostream>
#include "../includes/cargoCarrier.h"
#include "../includes/utils.h"
#include "../includes/car.h"
#include "../includes/airplane.h"
#include "../includes/train.h"

void showMenu()
{
	std::cout << "\n+======================================================================+" << std::endl;
	std::cout << "����" << std::endl;
	std::cout << "1.�������� ��� ����������������." << std::endl;
	std::cout << "2.����� ����������(���� � ����� �� ��������� ��� ������������� ������)." << std::endl;
	std::cout << "3.����� ������ ���������." << std::endl;
	std::cout << "+======================================================================+" << std::endl;
	std::cout << "�������� �������: ";
}

void showMenuCarrier()
{
	std::cout << "\n+========================+" << std::endl;
	std::cout << "���� ������ ����������" << std::endl;
	std::cout << "1.�������� ������." << std::endl;
	std::cout << "2.�������� ������." << std::endl;
	std::cout << "3.�������� �����." << std::endl;
	std::cout << "+========================+" << std::endl;
	std::cout << "�������� �������: ";
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
			std::cout << "�������� ����� ����:" << std::endl;
			break;
		case 2:
			showInfo(size, carriers);
			std::cout << "�������� ����� ����:" << std::endl;
			break;
		case 3:
			std::cout << "��������� ���������." << std::endl;
			return;
		default:
			std::cout << "�������� ����� �� ����!" << std::endl;
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
			std::cout << "������� ���������:" << std::endl;
			temp = validInt(1, kMaxInt);
			carriers[size - 1] = new Car(temp);
			return;
		case 2:
			std::cout << "������� ���������:" << std::endl;
			temp = validInt(1, kMaxInt);
			carriers[size - 1] = new Airplane(temp);
			return;
		case 3:
			std::cout << "������� ���������:" << std::endl;
			temp = validInt(1, kMaxInt);
			carriers[size - 1] = new Train(temp);
			return;
		default:
			std::cout << "�������� ����� �� ����!" << std::endl;
		}
	}
}
