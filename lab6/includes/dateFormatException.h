#pragma once 

#include <exception>
#include <iostream>
#include <string>

class DateFormatException : public std::exception{
	std::string message;
public:
	explicit DateFormatException(const std::string& msg);
	const char * what() const noexcept override;
};