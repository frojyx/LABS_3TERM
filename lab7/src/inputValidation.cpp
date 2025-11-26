#include "../includes/inputValidation.h"
#include <iostream>
#include <string>
#include <cctype>

int getValidInt() {
    int value;
    while (!(std::cin >> value)) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Ошибка! Введите целое число: ";
    }
    std::cin.ignore(10000, '\n');
    return value;
}

int validInt(int min, int max) {
    int value;
    while (true) {
        value = getValidInt();
        if (value >= min && value <= max) {
            break;
        }
        std::cout << "Ошибка! Введите число от " << min << " до " << max << ": ";
    }
    return value;
}

double getValidDouble() {
    double value;
    while (!(std::cin >> value)) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Ошибка! Введите число: ";
    }
    std::cin.ignore(10000, '\n');
    return value;
}

std::string getValidString() {
    std::string value;
    std::getline(std::cin, value);
    while (value.empty()) {
        std::cout << "Ошибка! Введите непустую строку: ";
        std::getline(std::cin, value);
    }
    return value;
}

std::string getValidPhone() {
    std::string phone;
    while (true) {
        phone = getValidString();
        bool valid = true;
        if (phone.length() < 7) valid = false;
        for (char c : phone) {
            if (!std::isdigit(c) && c != '+' && c != '-' && c != '(' && c != ')' && c != ' ') {
                valid = false;
                break;
            }
        }
        if (valid) break;
        std::cout << "Ошибка! Введите корректный номер телефона: ";
    }
    return phone;
}

std::string getValidPhoneNumber() {
    std::string phone;
    while (true) {
        std::cout << "Введите 12 цифр номера телефона: ";
        phone = getValidString();

        if (phone.length() != 12) {
            std::cout << "Ошибка! Номер должен содержать ровно 12 цифр." << std::endl;
            continue;
        }

        bool allDigits = true;
        for (char c : phone) {
            if (!std::isdigit(c)) {
                allDigits = false;
                break;
            }
        }

        if (allDigits) {
            break;
        }
        else {
            std::cout << "Ошибка! Номер должен содержать только цифры." << std::endl;
        }
    }
    return phone;
}

std::string getValidTime() {
    std::string time;
    while (true) {
        time = getValidString();
        if (time.length() == 5 && time[2] == ':' &&
            std::isdigit(time[0]) && std::isdigit(time[1]) &&
            std::isdigit(time[3]) && std::isdigit(time[4])) {
            int hours = std::stoi(time.substr(0, 2));
            int minutes = std::stoi(time.substr(3, 2));
            if (hours >= 0 && hours < 24 && minutes >= 0 && minutes < 60) {
                break;
            }
        }
        std::cout << "Ошибка! Введите время в формате ЧЧ:ММ: ";
    }
    return time;
}

std::string getValidDate() {
    std::string date;
    while (true) {
        date = getValidString();
        if (date.length() == 8 && date[2] == '.' && date[5] == '.' &&
            std::isdigit(date[0]) && std::isdigit(date[1]) &&
            std::isdigit(date[3]) && std::isdigit(date[4]) &&
            std::isdigit(date[6]) && std::isdigit(date[7])) {
            int day = std::stoi(date.substr(0, 2));
            int month = std::stoi(date.substr(3, 2));
            int year = std::stoi(date.substr(6, 2));
            if (day >= 1 && day <= 31 && month >= 1 && month <= 12 && year >= 0 && year <= 99) {
                break;
            }
        }
        std::cout << "Ошибка! Введите дату в формате ДД.ММ.ГГ: ";
    }
    return date;
}

char getValidChar() {
    char c;
    std::cin >> c;
    std::cin.ignore(10000, '\n');
    return c;
}