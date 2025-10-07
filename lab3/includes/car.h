#pragma once

#include <iostream>
#include "../includes/PassengerCarrier.h"

class Car :public PassengerCarrier {
public:
	void getName() override;

	Car();
};