#pragma once

#include <iostream>
#include "../includes/passengerCarrier.h"

constexpr const int kMaxInt = 2147483647;

int validInt(int min , int max );

void addCarrier(passengerCarrier**& carriers, int* size, int* cap);	
void expandCarries(int* size, int* cap, passengerCarrier**& carriers);
void showInfo(int size, passengerCarrier** carriers);
void printInfo(passengerCarrier& carrier);

