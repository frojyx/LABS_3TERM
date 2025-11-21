#include "../includes/ATS.h"
#include "../includes/inputValidation.h"
#include <fstream>
#include <iomanip>
#include <sstream>

ATS::ATS() : date(""), cityCode(0), cityName(""), duration(""), tariff(0.0), phoneNumber("") {}

ATS::ATS(const std::string& d, int & code, const std::string& name,
    const std::string& dur, double tar, const std::string& phone)
    : date(d), cityCode(code), cityName(name), duration(dur), tariff(tar), phoneNumber(phone) {
}

//std::ostream& operator<<(std::ostream& out, const ATS& obj) {
//    out << std::setw(12) << obj.date << std::setw(8) << obj.cityCode
//        << std::setw(15) << obj.cityName << std::setw(10) << obj.duration
//        << std::setw(8) << obj.tariff << std::setw(15) << obj.phoneNumber;
//    return out;
//}

//std::istream& operator>>(std::istream& in, ATS& obj) {
//    std::cout << "Введите дату разговора (ДД.ММ.ГГ): ";
//    obj.date = getValidDate();
//    std::cout << "Введите код города: ";
//    obj.cityCode = validInt(0,10000000);
//    std::cout << "Введите название города: ";
//    obj.cityName = getValidString();
//    std::cout << "Введите время разговора (ЧЧ:ММ): ";
//    obj.duration = getValidTime();
//    std::cout << "Введите тариф: ";
//    obj.tariff = getValidDouble();
//    obj.phoneNumber = getValidPhoneNumber();
//    return in;
//}

void writeToFile(std::ofstream& out, const ATS& obj) {
    out << obj.date << " " << obj.cityCode << " " << obj.cityName << " "
        << obj.duration << " " << obj.tariff << " " << obj.phoneNumber << std::endl;
}

void readFromFile(std::ifstream& in, ATS& obj) {
    in >> obj.date >> obj.cityCode >> obj.cityName >> obj.duration >> obj.tariff >> obj.phoneNumber;
}

int ATS::getPhonesCountByTariff(const std::string& filename, double targetTariff) {
    std::ifstream file(filename);
    if (!file) {
        return 0;
    }

    int count = 0;
    ATS record;
    while (!file.eof()) {
        readFromFile(file, record);
        if (!file.fail() && record.tariff == targetTariff) {
            count++;
        }
    }
    file.close();
    return count;
}

std::string* ATS::getPhonesByTariff(const std::string& filename, double targetTariff, int& count) {
    count = getPhonesCountByTariff(filename, targetTariff);
    if (count == 0) {
        return nullptr;
    }

    auto* phones = new std::string[count];
    std::ifstream file(filename);
    if (!file) {
        delete[] phones;
        count = 0;
        return nullptr;
    }

    int index = 0;
    ATS record;
    while (!file.eof()) {
        readFromFile(file, record);
        if (!file.fail() && record.tariff == targetTariff) {
            phones[index] = record.phoneNumber;
            index++;
        }
    }
    file.close();
    return phones;
}