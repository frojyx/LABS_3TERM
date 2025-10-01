#include <iostream>
#include "..//includes/passengerCarrier.h"
#include "..//includes/airplane.h"
#include "..//includes/utils.h"

Airplane::Airplane() : passengerCarrier(800,1,validInt(1,kMaxInt)) {}

void Airplane:: getName()
{
	std::cout << "Самолёт" << std::endl;
}

