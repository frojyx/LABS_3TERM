#pragma once

#include <iostream>
#include "..//includes/passengerCarrier.h"

class Car :public passengerCarrier {
public:
	void getName() override;

	Car();
};