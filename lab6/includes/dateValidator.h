#pragma once 

#include <string>
using namespace std;

class DateValidator {
public:
    static bool isValidFormat(const string& date);
    static void checkDate(const string& date);
};
