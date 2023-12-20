#pragma once
#include <iostream>
using namespace std;
class Driver;

class Vehicle
{
	string model;
	string registrationNumber;
	Driver* driver = nullptr;
	string insurance = "No";

public:
	Vehicle() = default;
	Vehicle(const string& model)
		:Vehicle(model, "000X00") {}
	Vehicle(const string& model, const string& registrationNumber);
	const string& getModel()const;
	const string& getNumber()const;
	void setNumber(const string& number);
	void setModel(const string& model);
	const Driver* getOwner() const;
	void setOwner(Driver* driver);
	const string& getInsurance() const;
	void setInsurance(const string& insurance);
	void clearOwner();
};

class Driver
{
	string name;
	string licenseNumber;
	Vehicle** vehicles = nullptr;
	size_t size = 0;
	char category[4];
	size_t size_c = 0;
	bool checkCategory(Vehicle* vehicle);
	void addVehicle(Vehicle* vehicle);
	int findVehicle(const Vehicle* vehicle) const;
	void deleteVehicle(const size_t index);
public:
	Driver() = default;
	Driver(const string& name)
		:Driver(name, "000X00") {}
	Driver(const string& name, const string& licenseNumber)
	{
		setName(name);
		setNumber(licenseNumber);
	}
	const string getName()const;
	const string getNumber()const;
	void setNumber(const string& number);
	void setName(const string& name);
	void assignVehicle(Vehicle* vehicle);
	void showInsurance() const;
	void addCategory(const char& cat);
	void releaseVehicle(Vehicle* vehicle);
};

inline const string& Vehicle::getModel()const {
	return model;
}

inline const string& Vehicle::getNumber() const
{
	return registrationNumber;
}

inline const Driver* Vehicle::getOwner() const
{
	return driver;
}

inline void Vehicle::setOwner(Driver* driver)
{
	this->driver = driver;
}

inline const string& Vehicle::getInsurance() const
{
	return insurance;
}

inline void Vehicle::setInsurance(const string& insurance)
{
	this->insurance = insurance;
}

inline void Vehicle::clearOwner()
{
	driver = nullptr;
}

inline const string Driver::getName() const
{
	return name;
}

inline const string Driver::getNumber() const
{
	return licenseNumber;
}


