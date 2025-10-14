#pragma once

#include <iostream>
#include "../includes/passengerCarrier.h"

class Train :public PassengerCarrier {
public:
	void getName() override;

	Train();
};