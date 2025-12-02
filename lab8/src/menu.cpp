#include "../includes/menu.h"

#include <iostream>

void showTask() {
    std::cout << "\t\t\t\tTASK" << std::endl;
    std::cout << "Implement classes Container and Iterator for a "
        "one-dimensional array."
        << std::endl;
    std::cout << "Implement a class Algorithm that defines methods for:"
        << std::endl;
    std::cout << "- Searching the array." << std::endl;
    std::cout << "- Sorting the array." << std::endl;
    std::cout << "Build and demonstrate the program." << std::endl;
}

void showArrayTypeMenu() {
    std::cout << "\nSelect array element type:\n";
    std::cout << "1. int\n";
    std::cout << "2. long\n";
    std::cout << "3. float\n";
    std::cout << "4. double\n";
    std::cout << "5. char\n";
    std::cout << "6. string\n";
}

void showMenu() {
    std::cout << "\n\t\t\t\tARRAY MENU" << std::endl;
    std::cout << "1. Create array." << std::endl;
    std::cout << "2. Add element." << std::endl;
    std::cout << "3. Remove element." << std::endl;
    std::cout << "4. Display array." << std::endl;
    std::cout << "5. Sort array." << std::endl;
    std::cout << "6. Search for element." << std::endl;
    std::cout << "7. Clear array." << std::endl;
    std::cout << "8. Exit program." << std::endl;
}

void showAddMenu() {
    std::cout << "\n\t\t\t\tADD MENU" << std::endl;
    std::cout << "1. Add to the beginning (push_front)." << std::endl;
    std::cout << "2. Add to the end (push_back)." << std::endl;
    std::cout << "3. Insert at index." << std::endl;
}

void showRemoveMenu() {
    std::cout << "\n\t\t\t\tREMOVE MENU" << std::endl;
    std::cout << "1. Remove from the beginning (pop_front)." << std::endl;
    std::cout << "2. Remove from the end (pop_back)." << std::endl;
    std::cout << "3. Remove at index." << std::endl;
}