#pragma once

#include <iostream>
#include "../includes/PassengerCarrier.h"

class Train :public PassengerCarrier {
public:
	void getName() override;

	Train();
};