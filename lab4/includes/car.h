#pragma once

#include <iostream>
#include "../includes/cargoCarrier.h"

class Car :public CargoCarrier {
public:
	void getName() override;
	std::string getCity();
	Car();
	Car(double distance);
};