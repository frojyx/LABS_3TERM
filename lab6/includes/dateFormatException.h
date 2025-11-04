#pragma once 

#include <iostream>

class DateFormatException {
	std::string message;
public:
	explicit DateFormatException(const std::string& msg);
	std::string what() const;
};