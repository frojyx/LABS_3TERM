#include <iostream>

int validInt() {
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

        return number;
    }
}