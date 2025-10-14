#pragma once

#include <iostream>
#include "../includes/passengerCarrier.h"

class Airplane :public PassengerCarrier {
public:
	void getName() override;
	
	Airplane();
};