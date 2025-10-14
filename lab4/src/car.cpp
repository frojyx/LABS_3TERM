#include <iostream>
#include "../includes/cargoCarrier.h"
#include "../includes/car.h"
#include "../includes/utils.h"

Car::Car(double distance) : CargoCarrier(60, 0.6, distance, inputCityName()) {}

void Car::getName()
{
	std::cout << "Машина" << std::endl;
}


