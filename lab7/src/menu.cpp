#include "../includes/menu.h"
#include "../includes/ATSManager.h"
#include "../includes/inputValidation.h"
#include <iostream>

void displayMainMenu() {
    std::cout << "\n=== Система учета АТС ===" << std::endl;
    std::cout << "1. Добавить записи" << std::endl;
    std::cout << "2. Показать все записи" << std::endl;
    std::cout << "3. Найти номера по тарифу" << std::endl;
    std::cout << "4. Выход" << std::endl;
    std::cout << "Выберите действие: ";
}

void runMenu() {
    int choice;

    do {
        displayMainMenu();
        choice = validInt(0,4);

        switch (choice) {
        case 1:
            addRecords();
            break;
        case 2:
            displayAllRecords();
            break;
        case 3:
            searchByTariff();
            break;
        case 4:
            std::cout << "Выход из программы." << std::endl;
            break;
        default:
            std::cout << "Неверный выбор! Попробуйте снова." << std::endl;
        }
    } while (choice != 4);
}