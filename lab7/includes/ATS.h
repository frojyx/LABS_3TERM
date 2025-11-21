#ifndef ATS_H
#define ATS_H

#include <iostream>
#include <fstream>
#include <string>

class ATS {
private:
    std::string date;
    std::string cityCode;
    std::string cityName;
    std::string duration;
    double tariff;
    std::string phoneNumber;

public:
    ATS();
    ATS(const std::string& d, const std::string& code, const std::string& name,
        const std::string& dur, double tar, const std::string& phone);

    friend std::ostream& operator<<(std::ostream& out, const ATS& obj);
    friend std::istream& operator>>(std::istream& in, ATS& obj);

    friend void writeToFile(std::ofstream& out, const ATS& obj);
    friend void readFromFile(std::ifstream& in, ATS& obj);

    static int getPhonesCountByTariff(const std::string& filename, double targetTariff);
    static std::string* getPhonesByTariff(const std::string& filename, double targetTariff, int& count);

    std::string getDate() const { return date; }
    std::string getCityCode() const { return cityCode; }
    std::string getCityName() const { return cityName; }
    std::string getDuration() const { return duration; }
    double getTariff() const { return tariff; }
    std::string getPhoneNumber() const { return phoneNumber; }
};

void writeToFile(std::ofstream& out, const ATS& obj);
void readFromFile(std::ifstream& in, ATS& obj);

#endif