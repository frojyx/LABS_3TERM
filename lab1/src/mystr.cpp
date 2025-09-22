#include "../includes/mystr.h"
#include "../includes/utils.h"
#include <iostream>

myString::myString() : length(0), cap(1), str(nullptr) {}

myString::myString(char* string) : length(strlen(string)), cap(length + 1) {
    str = new char[cap];
    strcpy(str, string);
    delete[] string;
    string = nullptr;
}

myString::~myString() {
    delete[] str;
}

void myString::input() {
    if (str != nullptr)
    {
        delete[] str;
        str = nullptr;
    }
    str = inputString();
    length = strlen(str);
    cap = length + 1;
}

char* myString::getString() {
    return str;
}

void myString::printString() const {
    if (str == nullptr)
    {
        std::cout << "Вначале введите строку!" << std::endl;
        return;
    }
    std::cout << "Ваша строка:" << std::endl;
    std::cout << str << std::endl;
}

char* myString::contacanateStrings(const char* str1, const char* str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    auto* newstr = new char[len1 + len2 + 1];
    strcpy(newstr, str1);
    strcpy(newstr + len1, str2);
    return newstr;
}

int myString::strlen(const char* str) {
    int length = 0;
    while (*str != '\0') {
        length++;
        str++;
    }
    return length;
}

char* myString::strcpy(char* strcopy, const char* str) {
    char* temp = strcopy;
    while (*str != '\0') {
        *temp = *str;
        str++;
        temp++;
    }
    *temp = '\0';
    return strcopy;
}

myString::myString(const myString& other) :length(other.length) {
    str = new char[length + 1];
    strcpy(str, other.str);
}

myString& myString :: operator=(const myString& other) {
    if (this != &other) {
        delete[] str;
        length = other.length;
        str = new char[length + 1];
        strcpy(str, other.str);
    }
    return *this;
}
