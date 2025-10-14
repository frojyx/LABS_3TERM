#include <iostream>
#include "../includes/cargoCarrier.h"
#include "../includes/menu.h"
#include "../includes/utils.h"
#include <string>

int validInt(int min, int max) {
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

void addCarrier(CargoCarrier**& carriers, int* size, int* cap)
{
    expandCarries(size, cap, carriers);

    chooseCarriers(*size, carriers);

    std::cout << "�� ������� �������� ���������." << std::endl;
}

void expandCarries(int* size, int* cap, CargoCarrier**& carriers)
{
    if (*size < 0)
    {
        *size = 0;
    }
    if (*size == *cap - 1)
    {
        *cap *= 2;
        auto** newCarriers = new CargoCarrier * [*cap];
        for (int i = 0; i < *size; i++)
        {
            newCarriers[i] = carriers[i];
        }
        delete[] carriers;
        carriers = newCarriers;
    }
    (*size)++;
}

void showInfo(int size, CargoCarrier** carriers)
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

void printInfo(CargoCarrier& carrier)
{
    std::cout << std::endl;
    carrier.getName();
    std::cout << "���������� ��� ������ " << carrier.getCity() << std::endl;
    std::cout << "����� �� ��������� : " << carrier.calculateTime() << std::endl;
    std::cout << "���� �� ��������� : " << carrier.calculateCost() << std::endl;
}

std::string inputCityName()
{
    std::string cityName;
    std::cout << "������� ����� : " << std::endl;
   // verifyString(cityName);
    getline(std::cin, cityName);
    return cityName;
}

//void verifyString(std::string &str)
//{
//    bool valid = false;
//
//    while (!valid) {
//        std::cout << "������� ������ (������ ����� � �����): ";
//        std::getline(std::cin, str);
//
//        valid = true;
//        for (char c : str) {
//            if (!std::isalpha(c) && c != '-') {
//                std::cout << "������: ������ '" << c << "' ����������!" << std::endl;
//                valid = false;
//                break;
//            }
//        }
//
//        if (str.empty()) {
//            std::cout << "������: ������ �� ����� ���� ������!" << std::endl;
//            valid = false;
//        }
//    }
//}