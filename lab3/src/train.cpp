#include <iostream>
#include "../includes/passengerCarrier.h"
#include "../includes/train.h"
#include "../includes/utils.h"

Train::Train() : passengerCarrier(80, 0.3, validInt(1, kMaxInt)) {}

void Train::getName()
{
	std::cout << "Поезд" << std::endl;
}


