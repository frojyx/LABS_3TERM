#pragma once

#include <iostream>

class PassengerCarrier { 
private:
	double distance;
	double costPerKm;
	double speedKmH;
protected:
	PassengerCarrier(double speed, double cost, double distance);
	PassengerCarrier();
public:
	virtual ~PassengerCarrier();
	virtual void getName();

	PassengerCarrier& operator=(const PassengerCarrier& other);
	PassengerCarrier(const PassengerCarrier& other);

	double calculateTime() const;
	double calculateCost() const;
};