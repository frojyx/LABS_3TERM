#pragma once 

#include <iostream>
using namespace std;

class DateFormatException {
    string message;
public:
    DateFormatException(const string& msg);
    string what() const;
};