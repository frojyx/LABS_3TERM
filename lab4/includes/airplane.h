#pragma once

#include <iostream>
#include "../includes/cargoCarrier.h"

class Airplane :public CargoCarrier {
public:
	void getName() override;

	Airplane(double distance);
};