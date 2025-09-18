#include<iostream>

int validInt() {
    int number;

    while (true) {
        if (!(std::cin >> number)) {
            std::cin.clear();
            while (std::cin.get() != '\n');
            std::cout << "Введите целое число: ";
            continue;
        }

        if (std::cin.get() != '\n') {
            std::cin.clear();
            while (std::cin.get() != '\n');
            std::cout << "Введите число без других символов : ";
            continue;
        }

        return number;
    }
}

char* inputString() {
    rewind(stdin);
    char* str = nullptr;
    int length = 0;
    int cap = 1;
    std::cout << "Введите строку" << std::endl;
    char symbol = '\0';
    str = new char[cap];

    while (true) {
        symbol = std::cin.get();
        if (symbol == '\0' || symbol == '\n')
            break;

        if (length == cap - 1) {
            cap *= 2;
            auto* tempstr = new char[cap];
            for (int i = 0; i < length; i++)
                tempstr[i] = str[i];
            delete[] str;
            str = tempstr;
        }

        str[length] = symbol;
        length++;
        if (str[0] == '\0')
        {
            std::cout << "Ошибка.Введите строку." << std::endl;
            length = 0;
            cap = 1;
        }
    }
    str[length] = '\0';
    return str;
}