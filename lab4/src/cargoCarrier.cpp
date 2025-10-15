#include <iostream>

#include "../includes/cargoCarrier.h"

CargoCarrier::CargoCarrier(double speed, double cost, double distance,const std:: string& cityName) : 
	distance(distance), costPerKm(cost), speedKmH(speed),city(cityName) {}

CargoCarrier::CargoCarrier() : distance(0.0), costPerKm(0.0), speedKmH(0.0) {}

CargoCarrier::~CargoCarrier()
{
	distance = 0;
	costPerKm = 0;
	speedKmH = 0;
}
CargoCarrier& CargoCarrier:: operator=(const CargoCarrier& other) = default;

CargoCarrier::CargoCarrier(const CargoCarrier& other) = default;

double CargoCarrier::calculateTime() const { return distance / speedKmH; }

double CargoCarrier::calculateCost() const { return distance * costPerKm; }

void CargoCarrier::getName() { std::cout << "Cargo ñarrier" << std::endl; }

std::string CargoCarrier::getCity() const{ return city; }

