#include "../includes/dateFormatException.h"

DateFormatException::DateFormatException(const std::string& msg) : message(msg) {}

std::string DateFormatException::what() const { return message; }