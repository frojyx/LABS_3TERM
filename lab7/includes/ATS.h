#ifndef ATS_H
#define ATS_H

#include <iostream>
#include <fstream>
#include <string>

#include "../includes/inputValidation.h"
#include <iomanip>


class ATS {
private:
    std::string date;
    int cityCode;
    std::string cityName;
    std::string duration;
    double tariff;
    std::string phoneNumber;

public:
    ATS();
    ATS(const std::string& d, const int& code, const std::string& name,
        const std::string& dur, double tar, const std::string& phone);

    friend std::ostream& operator<<(std::ostream& out, const ATS& obj)
    {
        out << std::setw(12) << obj.date << std::setw(8) << obj.cityCode
            << std::setw(15) << obj.cityName << std::setw(10) << obj.duration
            << std::setw(8) << obj.tariff << std::setw(15) << obj.phoneNumber;
        return out; 
    }
    friend std::istream& operator>>(std::istream& in, ATS& obj)
    {
        std::cout << "Введите дату разговора (ДД.ММ.ГГ): ";
        obj.date = getValidDate();
        std::cout << "Введите код города: ";
        obj.cityCode = validInt(0, 10000000);
        std::cout << "Введите название города: ";
        obj.cityName = getValidString();
        std::cout << "Введите время разговора (ЧЧ:ММ): ";
        obj.duration = getValidTime();
        std::cout << "Введите тариф: ";
        obj.tariff = getValidDouble();
        obj.phoneNumber = getValidPhoneNumber();
        return in;
    }

    friend void writeToFile(std::ofstream& out, const ATS& obj);
    friend void readFromFile(std::ifstream& in, ATS& obj);

    static int getPhonesCountByTariff(const std::string& filename, double targetTariff);
    static std::string* getPhonesByTariff(const std::string& filename, double targetTariff, int& count);

    std::string getDate() const { return date; }
   // std::string getCityCode() const { return cityCode; }
    std::string getCityName() const { return cityName; }
    std::string getDuration() const { return duration; }
    double getTariff() const { return tariff; }
    std::string getPhoneNumber() const { return phoneNumber; }
};

void writeToFile(std::ofstream& out, const ATS& obj);
void readFromFile(std::ifstream& in, ATS& obj);

#endif