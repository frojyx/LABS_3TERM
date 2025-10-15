#include <iostream>
#include "../includes/cargoCarrier.h"
#include "../includes/train.h"
#include "../includes/utils.h"

Train::Train(double distance) : CargoCarrier(80, 0.3, distance, inputCityName()) {}

void Train::getName()
{
	std::cout << "Train" << std::endl;
}


