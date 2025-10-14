#pragma once

#include <iostream>
#include "../includes/cargoCarrier.h"

class Train :public CargoCarrier {
public:
	void getName() override;
	explicit Train(double distance);
};