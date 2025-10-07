#pragma once

#include <iostream>
#include "../includes/PassengerCarrier.h"

class Airplane :public PassengerCarrier {
public:
	void getName() override;
	
	Airplane();
};