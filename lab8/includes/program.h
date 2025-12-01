#pragma once

#include "../includes/algorithm.h"
#include "../includes/array.h"
#include "../includes/utils.h"

template <typename T>
class Program {
    Array<T> arr;
    Algorithm<T> algorithm [[no_unique_address]];

    void createArray();
    void addArrayElement();
    void removeArrayElement();
    void showArray();
    void sortArray();
    void searchArrayElement();
    void clearArray();

public:
    Program();

    void run();
};

template <typename T>
Program<T>::Program() {
    std::cout << kGreenColor << "\nYou successfully chose a type of array!"
        << kWhiteColor << std::endl;
}

template <typename T>
void Program<T>::createArray() {
    if (!arr.empty()) {
        std::cout << kRedColor << "\nError, array is also entered!"
            << kWhiteColor << std::endl;
        return;
    }

    std::cout << "\nEnter initial size of array: ";
    auto size = getValue<size_t>();

    arr = Array<T>(size);

    for (size_t i = 0; i < size; i++) {
        std::cout << "\nEnter element " << i + 1 << ">> ";
        arr[i] = getValue<T>();
    }

    std::cout << kGreenColor << "\nArray created successfully!" << kWhiteColor
        << std::endl;
}

template <typename T>
void Program<T>::addArrayElement() {
    if (arr.empty()) {
        std::cout << kRedColor << "\nError, array is empty." << kWhiteColor
            << std::endl;
        return;
    }

    std::cout << "\nPlease enter a value to add to the array: ";
    auto value = getValue<T>();

    int opt = 0;
    showAddMenu();

    while (true) {
        std::cout << "\nPlease enter the add menu option: ";
        opt = getValue<int>();

        switch (opt) {
        case 1:
            arr.push_front(value);

            std::cout << kGreenColor
                << "\nYou successfully added an element to the "
                "beginning of the array!"
                << kWhiteColor << std::endl;
            return;
        case 2:
            arr.push_back(value);

            std::cout << kGreenColor
                << "\nYou successfully added an element to the end "
                "of the array!"
                << kWhiteColor << std::endl;
            return;
        case 3: {
            size_t index = getValidIndex(arr);

            arr.insert(arr.begin() + index, value);

            std::cout
                << kGreenColor
                << "\nYou successfully inserted an element into the array!"
                << kWhiteColor << std::endl;
            return;
        }
        default:
            std::cout << kRedColor << "\nWrong choice, please try again!"
                << kWhiteColor << std::endl;
        }
    }
}

template <typename T>
void Program<T>::removeArrayElement() {
    if (arr.empty()) {
        std::cout << kRedColor << "\nError, array is empty." << kWhiteColor
            << std::endl;
        return;
    }

    int opt = 0;
    showRemoveMenu();

    while (true) {
        std::cout << "\nPlease enter the remove menu option: ";
        opt = getValue<int>();

        switch (opt) {
        case 1:
            arr.pop_front();

            std::cout << kGreenColor
                << "\nYou successfully removed the first element of "
                "the array!"
                << kWhiteColor << std::endl;
            return;
        case 2:
            arr.pop_back();

            std::cout << kGreenColor
                << "\nYou successfully removed the last element of "
                "the array!"
                << kWhiteColor << std::endl;
            return;
        case 3: {
            size_t index = getValidIndex(arr);

            arr.erase(arr.begin() + index);

            std::cout
                << kGreenColor
                << "\nYou successfully removed an element from the array!"
                << kWhiteColor << std::endl;
            return;
        }
        default:
            std::cout << kRedColor << "\nWrong choice, please try again!"
                << kWhiteColor << std::endl;
        }
    }
}

template <typename T>
void Program<T>::showArray() {
    if (arr.empty()) {
        std::cout << kRedColor << "\nError, array is empty." << kWhiteColor
            << std::endl;
        return;
    }

    std::cout << "\nArray elements: ";
    for (auto it = arr.begin(); it != arr.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << kGreenColor
        << "\nYou have successfully displayed the array elements!"
        << kWhiteColor << std::endl;
}

template <typename T>
void Program<T>::sortArray() {
    if (arr.empty()) {
        std::cout << kRedColor << "\nError, array is empty." << kWhiteColor
            << std::endl;
        return;
    }

    algorithm.sort(arr);

    std::cout << kGreenColor << "\nYou successfully sorted the array!"
        << kWhiteColor << std::endl;
}

template <typename T>
void Program<T>::searchArrayElement() {
    if (arr.empty()) {
        std::cout << kRedColor << "\nError, array is empty." << kWhiteColor
            << std::endl;
        return;
    }

    std::cout << "\nPlease enter value to search: ";
    auto value = getValue<T>();

    Array tmp = arr;
    algorithm.sort(tmp);

    if (algorithm.find(tmp, value)) {
        std::cout << kGreenColor << "\nThe element was found successfully!"
            << kWhiteColor << std::endl;
    }
    else {
        std::cout << kRedColor << "\nValue not found." << kWhiteColor
            << std::endl;
    }
}

template <typename T>
void Program<T>::clearArray() {
    if (arr.empty()) {
        std::cout << kRedColor << "Error, array is empty.\n" << kWhiteColor;
        return;
    }

    arr.clear();

    std::cout << kGreenColor << "\nYou successfully cleared the array!"
        << kWhiteColor << std::endl;
}

template <typename T>
void Program<T>::run() {
    showMenu();

    int opt = 0;

    while (true) {
        std::cout << "\nPlease enter menu option: ";

        opt = getValue<int>();

        switch (opt) {
        case 1:
            createArray();
            break;
        case 2:
            addArrayElement();
            break;
        case 3:
            removeArrayElement();
            break;
        case 4:
            showArray();
            break;
        case 5:
            sortArray();
            break;
        case 6:
            searchArrayElement();
            break;
        case 7:
            clearArray();
            break;
        case 8:
            std::cout << kGreenColor
                << "\nYou have successfully exited the program."
                << kWhiteColor << std::endl;
            return;
        default:
            std::cout << kRedColor
                << "\nError, you picked is an incorrect menu option. "
                "Please try again."
                << kWhiteColor << std::endl;
        }
    }
}