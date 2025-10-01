#pragma once

#include <iostream>
#include "..//includes/passengerCarrier.h"

class Train :public passengerCarrier {
public:
	void getName() override;

	Train();
};