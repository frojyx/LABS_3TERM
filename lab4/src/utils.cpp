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
            std::cout << "Enter an integer: ";
            continue;
        }

        if (std::cin.get() != '\n') {
            std::cin.clear();
            while (std::cin.get() != '\n');
            std::cout << "Please enter the number without any other characters. : ";
            continue;
        }

        if (number<min || number>max) {
            std::cout << "Please enter a number greater than the minimum:" << std::endl;
            continue;
        }
        return number;
    }
}

void addCarrier(CargoCarrier**& carriers, int* size, int* cap)
{
    expandCarries(size, cap, carriers);

    chooseCarriers(*size, carriers);

    std::cout << "You have successfully added transport." << std::endl;
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
        std::cout << "¬ведите данные!" << std::endl;
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
    std::cout << "Information for the " << carrier.getCity() << std::endl;
    std::cout << "Time on the distance: " << carrier.calculateTime() << std::endl;
    std::cout << "Price per distance: " << carrier.calculateCost() << std::endl;
}

std::string inputCityName()
{
    std::string cityName;
    std::cout << "Enter city:" << std::endl;
    verifyString(cityName);
    return cityName;
}

void verifyString(std::string &str)
{
    bool valid = false;

    while (!valid) {
        std::cout << "Enter city name : ";
        std::getline(std::cin, str);

        valid = true;
        for (char c : str) {
            if (!std::isalpha(c) && c != '-') {
                std::cout << "Error: symbol'" << c << "' impermissible!" << std::endl;
                valid = false;
                break;
            }
        }

        if (str.empty()) {
            std::cout << "Error: string cannot be empty!" << std::endl;
            valid = false;
        }
    }
}