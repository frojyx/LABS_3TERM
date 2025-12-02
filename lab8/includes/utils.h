#pragma once

#include "../includes/array.h"
#include "../includes/consts.h"

template <typename T>
T getValue() {
    T value;
    int sym = 0;

    while (true) {
        if (std::cin.peek() != '\n' && std::cin.peek() != ' ' &&
            (std::cin >> value).good()) {
            sym = std::cin.peek();
            if ((char)sym == '\n' || (char)sym == EOF) {
                std::cin.get();
                return value;
            }
        }

        std::cin.clear();
        while (std::cin.get() != '\n' && !std::cin.eof());
        std::cout << kRedColor << "\nError, invalid input. Please try again: "
            << kWhiteColor;
    }
}

void choiceArrayType();

template <typename T>
size_t getValidIndex(const Array<T>& arr) {
    while (true) {
        std::cout << "\nPlease enter the index at which to add the value: ";

        if (auto index = getValue<size_t>(); index <= arr.Size()) {
            return index;
        }

        std::cout << kRedColor << "\nInvalid index, please try again!"
            << kWhiteColor << std::endl;
    }
}