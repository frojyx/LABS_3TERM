#pragma once 

#include <iostream>

class DateValidator {
public:
    static bool isValidFormat(const std::string& date);
    static void checkDate(const std::string& date);
};
