#include <iostream>
#include "../includes/cargoCarrier.h"
#include "../includes/airplane.h"
#include "../includes/utils.h"

Airplane::Airplane(double distance) : CargoCarrier(800, 1, distance, inputCityName()) {}

void Airplane::getName()
{
	std::cout << "Airplane" << std::endl;
}

