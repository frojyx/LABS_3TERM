#include <iostream>
#include "../includes/PassengerCarrier.h"
#include "../includes/airplane.h"
#include "../includes/utils.h"

Airplane::Airplane() : PassengerCarrier(800,1,validInt(1,kMaxInt)) {}

void Airplane:: getName()
{
	std::cout << "Самолёт" << std::endl;
}

