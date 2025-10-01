#pragma once

#include <iostream>
#include "..//includes/passengerCarrier.h"

class Airplane :public passengerCarrier {
public:
	void getName() override;
	
	Airplane();
};