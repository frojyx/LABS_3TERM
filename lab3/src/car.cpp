#include <iostream>
#include "../includes/PassengerCarrier.h"
#include "../includes/car.h"
#include "../includes/utils.h"

Car::Car() : PassengerCarrier(60, 0.6, validInt(1, kMaxInt)) {}

void Car::getName()
{
	std::cout << "Машина" << std::endl;
}

