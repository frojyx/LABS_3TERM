#include "../includes/ATSManager.h"
#include "../includes/ATS.h"
#include "../includes/inputValidation.h"
#include <iostream>
#include <fstream>
#include <iomanip>

void addRecords() {
	std::ofstream file("ats_data.txt", std::ios::app);
	if (!file) {
		std::cout << "Ошибка открытия файла для записи!" << std::endl;
		return;
	}

	ATS record;
	std::cin >> record;
	writeToFile(file, record);

	file.close();
	std::cout << "Данные успешно сохранены в текстовый файл." << std::endl;
}

void displayAllRecords() {
	std::ifstream file("ats_data.txt");
	if (!file) {
		std::cout << "Ошибка открытия файла для чтения!" << std::endl;
		return;
	}

	std::cout << "\nВсе записи АТС:" << std::endl;

	ATS record;
	while (!file.eof()) {
		readFromFile(file, record);
		if (!file.fail()) {
			std::cout << record << std::endl;
		}
	}

	file.close();
}

void searchByTariff() {
	std::cout << "Введите тариф для поиска: ";
	double targetTariff = getValidDouble();

	int count = 0;
	std::string* phones = ATS::getPhonesByTariff("ats_data.txt", targetTariff, count);

	if (phones == nullptr || count == 0) {
		std::cout << "Номера телефонов с тарифом " << targetTariff << " не найдены." << std::endl;
	}
	else {
		std::cout << "\nНомера телефонов с тарифом " << targetTariff << ":" << std::endl;
		for (int i = 0; i < count; i++) {
			std::cout << phones[i] << std::endl;
		}
		delete[] phones;
	}
}