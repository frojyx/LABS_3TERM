#pragma once

#include <iostream>

class CargoCarrier {
private:
	double distance;
	double costPerKm;
	double speedKmH;
	std::string city;
protected:
	CargoCarrier(double speed, double cost, double distance,const std::string& cityName);
	CargoCarrier();
public:
	virtual ~CargoCarrier();
	virtual void getName()=0;
	
	CargoCarrier& operator=(const CargoCarrier& other);
	CargoCarrier(const CargoCarrier& other);

	double calculateTime() const;
	double calculateCost() const;
	std::string getCity() const;
};