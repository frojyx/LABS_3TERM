#include "../includes/dateValidator.h"
#include "../includes/dateFormatException.h"
#include <string>


bool DateValidator::isValidFormat(const std::string& date) {
	if (date.size() != 8) return false;
	return isdigit(date[0]) && isdigit(date[1]) &&
		date[2] == '.' &&
		isdigit(date[3]) && isdigit(date[4]) &&
		date[5] == '.' &&
		isdigit(date[6]) && isdigit(date[7]);
}

void DateValidator::checkDate(const std::string& date) {
    if (!isValidFormat(date)) {
        throw DateFormatException("ќшибка: неверный формат даты! »спользуйте формат дд.мм.гг");
    }

    int day = stoi(date.substr(0, 2));
    int month = stoi(date.substr(3, 2));
    int year = stoi(date.substr(6, 2));

    if (day < 1 || day > 31)
        throw DateFormatException("ќшибка: день должен быть от 01 до 31!");
    if (month < 1 || month > 12)
        throw DateFormatException("ќшибка: мес€ц должен быть от 01 до 12!");
    if (year < 0 || year > 99)
        throw DateFormatException("ќшибка: год должен быть от 00 до 99!");

    bool isLeapYear = (year % 4 == 0);
    int maxDays = isLeapYear ? 29 : 28;
    switch (month) {
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
        if (day > 31) throw DateFormatException("ќшибка: в этом мес€це не может быть более 31 дн€!");
        break;
    case 4: case 6: case 9: case 11:
        if (day > 30) throw DateFormatException("ќшибка: в этом мес€це не может быть более 30 дней!");
        break;
    case 2:
    {
        if (day > maxDays) {
            throw DateFormatException("ќшибка: неверное число дней в феврале!");
        }
    }
    break;
    default:
        throw DateFormatException("ќшибка: некорректный номер мес€ца!");
    }
}

