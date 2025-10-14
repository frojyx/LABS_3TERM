#pragma once

#include <iostream>
#include "../includes/passengerCarrier.h"

class Car :public PassengerCarrier {
public:
	void getName() override;

	Car();
};