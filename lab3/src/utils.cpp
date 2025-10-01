#include <iostream>
#include "..//includes/passengerCarrier.h"
#include "..//includes/menu.h"
#include "..//includes/utils.h"

int validInt(int min , int max ) {
    int number;

    while (true) {
        if (!(std::cin >> number)) {
            std::cin.clear();
            while (std::cin.get() != '\n');
            std::cout << "������� ����� �����: ";
            continue;
        }

        if (std::cin.get() != '\n') {
            std::cin.clear();
            while (std::cin.get() != '\n');
            std::cout << "������� ����� ��� ������ �������� : ";
            continue;
        }

        if (number<min || number>max) {
            std::cout << "������� ����� ������ ������������:" << std::endl;
            continue;
        }
        return number;
    }
}

void addCarrier(passengerCarrier**& carriers, int* size, int* cap)
{
    expandCarries(size, cap, carriers);

    chooseCarriers(*size, carriers);

    std::cout << "�� ������� �������� ���������." << std::endl;
}

void expandCarries(int* size, int* cap, passengerCarrier**& carriers)
{
    if (*size < 0)
    {
        *size = 0;
    }
    if (*size == *cap - 1)
    {
        *cap *= 2;
        auto** newCarriers = new passengerCarrier * [*cap];
        for (int i = 0; i < *size; i++)
        {
            newCarriers[i] = carriers[i];
        }
        delete[] carriers;
        carriers = newCarriers;
    }
    (*size)++;
}

void showInfo(int size, passengerCarrier** carriers)
{
    if (carriers == nullptr)
    {
        std::cout << "������� ������!" << std::endl;
        return;
    }

    for (int i = 0; i < size; i++)
    {
        printInfo(*carriers[i]);
    }
    std::cout << std::endl;
}

void printInfo(passengerCarrier& carrier)
{
    std::cout << std::endl;
    carrier.getName();
    std::cout << "����� �� ��������� : \n" << carrier.calculateTime() << std::endl;
    std::cout << "���� �� ��������� : \n" << carrier.calculateCost() << std::endl;
}


