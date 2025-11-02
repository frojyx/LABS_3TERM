#include "../includes/dateFormatException.h"

DateFormatException::DateFormatException(const string& msg) : message(msg) {}

string DateFormatException:: what() const { return message; }