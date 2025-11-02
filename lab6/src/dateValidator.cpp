#include "../includes/dateValidator.h"
#include "../includes/dateFormatException.h"

bool DateValidator::isValidFormat(const string& date) {
    if (date.size() != 8) return false;
    return isdigit(date[0]) && isdigit(date[1]) &&
        date[2] == '.' &&
        isdigit(date[3]) && isdigit(date[4]) &&
        date[5] == '.' &&
        isdigit(date[6]) && isdigit(date[7]);
}

void DateValidator::checkDate(const string& date) {
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
    if (month == 2 && day > 29)
        throw DateFormatException("ќшибка: в феврале не может быть более 29 дней!");
}
