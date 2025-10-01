#include <iostream>
#include "..//includes/passengerCarrier.h"
#include "..//includes/car.h"
#include "..//includes/utils.h"

Car::Car() : passengerCarrier(60, 0.6, validInt(1, kMaxInt)) {}

void Car::getName()
{
	std::cout << "Машина" << std::endl;
}

