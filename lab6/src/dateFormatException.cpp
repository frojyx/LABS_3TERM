#include "../includes/dateFormatException.h"

DateFormatException::DateFormatException(const std::string& msg) : message(msg) {}

const char * DateFormatException::what() const noexcept{ return message.c_str(); }