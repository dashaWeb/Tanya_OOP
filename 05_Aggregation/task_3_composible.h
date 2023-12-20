#pragma once
#include <iostream>
using namespace std;
class Car
{
	class Odometer {
		double mileage;
	public:
		Odometer(const double& mileage)
			:mileage(mileage){}
		~Odometer()
		{
			cout << "Delete Odometer" << endl;
		}
		void addMileage(double km);
		void reset();
		double getMileage();
	};
	string make;
	string model;
	Odometer odometer;
public:
	Car(const string& make = "None mark", const string& model = "None model", const Odometer& odometer = Odometer(0))
		:make(make),model(model),odometer(odometer){}
	~Car()
	{
		cout << "Delete Car " << make << endl;
	}
	void drive(double km);
	void showMileage();
	void resetOdometer();
};

