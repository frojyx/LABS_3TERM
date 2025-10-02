#include <iostream>

#include "../includes/passengerCarrier.h"

passengerCarrier::passengerCarrier(double speed, double cost, double distance) : distance(distance), costPerKm(cost), speedKmH(speed) {}

passengerCarrier::passengerCarrier() : distance(0.0), costPerKm(0.0), speedKmH(0.0) {}

passengerCarrier::~passengerCarrier()
{
	distance = 0;
	costPerKm = 0;
	speedKmH = 0;
}	
passengerCarrier& passengerCarrier:: operator=(const passengerCarrier& other) = default;

passengerCarrier::passengerCarrier(const passengerCarrier& other) = default;

double passengerCarrier:: calculateTime() const{ return distance / speedKmH; }

double passengerCarrier:: calculateCost() const{ return distance * costPerKm; }
	
void passengerCarrier :: getName(){ std::cout << "Транспорт" << std::endl; }
