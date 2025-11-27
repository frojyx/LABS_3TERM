#include "../includes/ATS.h"
#include "../includes/inputValidation.h"
#include <fstream>
#include <iomanip>
#include <sstream>

ATS::ATS() : date(""), cityCode(0), cityName(""), duration(""), tariff(0.0), phoneNumber("") {}

ATS::ATS(const std::string& d, const int& code, const std::string& name,
    const std::string& dur, double tar, const std::string& phone)
    : date(d), cityCode(code), cityName(name), duration(dur), tariff(tar), phoneNumber(phone) {
}

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

void ATS::displayPhonesByTariff(const std::string& filename, double targetTariff) {
    std::ifstream file(filename);
    if (!file) {
        std::cout << "Ошибка открытия файла." << std::endl;
        return;
    }

    bool found = false;
    ATS record;

    std::cout << "\nНомера телефонов с тарифом " << targetTariff << ":" << std::endl;

    while (!file.eof()) {
        readFromFile(file, record);
        if (!file.fail() && record.tariff == targetTariff) {
            std::cout << record.phoneNumber << std::endl;
            found = true;
        }
    }
    file.close();

    if (!found) {
        std::cout << "Номера телефонов с тарифом " << targetTariff << " не найдены." << std::endl;
    }
}