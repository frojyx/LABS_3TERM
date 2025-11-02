#include <iostream>
#include "../includes/dateValidator.h"
#include "../includes/dateFormatException.h"
#include "../includes/menu.h"

using namespace std;

void showMenu() {
    string date;

    while (true) {
        cout << "Введите дату в формате дд.мм.гг (или 0 для выхода): ";
        cin >> date;

        if (date == "0") {
            cout << "Выход из программы..." << endl;
            break;
        }

        try {
            DateValidator::checkDate(date);
            cout << " Дата введена корректно!" << endl;
            cout << "Программа завершена." << endl;
            break;
        }
        catch (const DateFormatException& e) {
            cout << " " << e.what() << endl << endl;
            cout << "Попробуйте снова." << endl << endl;
        }
    }
}
