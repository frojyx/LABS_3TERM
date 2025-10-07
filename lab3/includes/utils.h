#pragma once

#include <iostream>
#include "../includes/PassengerCarrier.h"

constexpr const int kMaxInt = 2147483647;

int validInt(int min , int max );

void addCarrier(PassengerCarrier**& carriers, int* size, int* cap);	
void expandCarries(int* size, int* cap, PassengerCarrier**& carriers);
void showInfo(int size, PassengerCarrier** carriers);
void printInfo(PassengerCarrier& carrier);

