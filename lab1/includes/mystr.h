#pragma once

#include <iostream>

class myString {
    int length;
    int cap;
    char* str;
    char symbol = '\0';
public:
    myString();
    explicit myString(char* string);
    ~myString();

    void input();
    char* getString();
    void printString() const;
    char* contacanateStrings(const char* str1, const char* str2);

    static int strlen(const char* str);
    static char* strcpy(char* strcopy, const char* str);

    myString(const myString& other);
    myString& operator=(const myString& other);
};