#include <iostream>

#include "../includes/PassengerCarrier.h"

PassengerCarrier::PassengerCarrier(double speed, double cost, double distance) : distance(distance), costPerKm(cost), speedKmH(speed) {}

PassengerCarrier::PassengerCarrier() : distance(0.0), costPerKm(0.0), speedKmH(0.0) {}

PassengerCarrier::~PassengerCarrier()
{
	distance = 0;
	costPerKm = 0;
	speedKmH = 0;
}	
PassengerCarrier& PassengerCarrier:: operator=(const PassengerCarrier& other) = default;

PassengerCarrier::PassengerCarrier(const PassengerCarrier& other) = default;

double PassengerCarrier:: calculateTime() const{ return distance / speedKmH; }

double PassengerCarrier:: calculateCost() const{ return distance * costPerKm; }
	
void PassengerCarrier :: getName(){ std::cout << "Транспорт" << std::endl; }
