#include "task_3_composible.h"

void Car::Odometer::addMileage(double km)
{
	this->mileage += km;
}

void Car::Odometer::reset()
{
	this->mileage = 0;
}

double Car::Odometer::getMileage()
{
	return this->mileage;
}

void Car::drive(double km)
{
	this->odometer.addMileage(km);
}

void Car::showMileage()
{
	cout << this->make << " mileage :: " << this->odometer.getMileage() << endl;
}

void Car::resetOdometer()
{
	this->odometer.reset();
}
