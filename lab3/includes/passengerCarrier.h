#pragma once

#include <iostream>
#include <string>

class passengerCarrier {
private:
	double distance;
	double costPerKm;
	double speedKmH;
protected:
	passengerCarrier(double speed, double cost, double distance);
	passengerCarrier();
public:
	virtual ~passengerCarrier();
	virtual void getName();

	passengerCarrier& operator=(const passengerCarrier& other);
	passengerCarrier(const passengerCarrier& other);

	double calculateTime();
	double calculateCost();
};