#pragma once

#include <iostream>
#include "../includes/cargoCarrier.h"

constexpr const int kMaxInt = 2147483647;

int validInt(int min, int max);

void addCarrier(CargoCarrier**& carriers, int* size, int* cap);
void expandCarries(int* size, int* cap, CargoCarrier**& carriers);
void showInfo(int size, CargoCarrier** carriers);
void printInfo(CargoCarrier& carrier);

std::string inputCityName();
void verifyString(std::string& str);

