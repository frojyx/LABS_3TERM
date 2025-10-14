#pragma once

#include <iostream>
#include "../includes/cargoCarrier.h"

class Car :public CargoCarrier {
public:
	void getName() override;
	explicit Car(double distance);
};