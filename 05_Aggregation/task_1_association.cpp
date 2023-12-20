#include "task_1_association.h"

Vehicle::Vehicle(const string& model, const string& registrationNumber)
{
	setModel(model);
	setNumber(registrationNumber);
}

void Vehicle::setNumber(const string& number)
{
	if (number.empty() || number[0] == ' ') {
		this->registrationNumber = "none name";
		return;
	}
	this->registrationNumber = number;
}

void Vehicle::setModel(const string& model)
{
	if (model.empty() || model[0] == ' ') {
		this->model = "none name";
		return;
	}
	this->model = model;
}

void Driver::setNumber(const string& number)
{
	if (number.empty() || number[0] == ' ') {
		this->licenseNumber = "none name";
		return;
	}
	this->licenseNumber = number;
}

void Driver::setName(const string& name)
{
	if (name.empty() || name[0] == ' ') {
		this->name = "none name";
		return;
	}
	this->name = name;
}

void Driver::assignVehicle(Vehicle* vehicle)
{
	if (vehicle->getOwner() != nullptr)
	{
		cout << "This vehicle has an owner" << endl;
		return;
	}
	if (!checkCategory(vehicle)) {
		cout << "There is no corresponding category for transport" << endl;
		return;
	}
	vehicle->setOwner(this);
	vehicle->setInsurance("Yes");
	addVehicle(vehicle);
	cout << "Adding new vehicle (model :: " << vehicle->getModel() << "; number :: " << vehicle->getNumber() << ")\n";
}

bool Driver::checkCategory(Vehicle* vehicle)
{
	char needCategory = '*';
	if (vehicle->getModel() == "motorcycle" || vehicle->getModel() == "scooter") {
		needCategory = 'A';
	}
	else if (vehicle->getModel() == "car") {
		needCategory = 'B';
	}
	else if (vehicle->getModel() == "truck") {
		needCategory = 'C';
	}
	else if (vehicle->getModel() == "bus") {
		needCategory = 'D';
	}

	for (size_t i = 0; i < size_c; i++)
	{
		if (category[i] == needCategory)
		{
			return true;
		}
	}
	return false;
}

void Driver::addVehicle(Vehicle* vehicle)
{
	++size;
	if (vehicles == nullptr)
	{
		vehicles = new Vehicle * [1]{ vehicle };
	}
	else
	{
		auto tmp = new Vehicle * [size];
		for (size_t i = 0; i < size - 1; i++)
		{
			tmp[i] = vehicles[i];
		}
		tmp[size - 1] = vehicle;
		delete []vehicles;
		vehicles = tmp;
	}
}

int Driver::findVehicle(const Vehicle* vehicle) const
{

	for (size_t i = 0; i < size; i++)
	{
		if (vehicles[i] == vehicle) {
			return i;
		}
	}
	return -1;
}

void Driver::deleteVehicle(const size_t index)
{
	size--;
	if (size == 0) {
		delete[]vehicles;
		vehicles = nullptr;
		return;
	}
	auto tmp = new Vehicle * [size];
	for (size_t i = 0; i < size; i++)
	{
		if (i < index)
		{
			tmp[i] = vehicles[i];
			continue;
		}
		tmp[i] = vehicles[i + 1];
	}
	delete[]vehicles;
	vehicles = tmp;
}

void Driver::showInsurance() const
{
	cout << "Print insurance :: " << endl;
	for (size_t i = 0; i < size; i++)
	{
		cout << "\t" << vehicles[i]->getModel() << " :: " << vehicles[i]->getInsurance() << endl;
	}
}

void Driver::addCategory(const char& cat)
{
	category[size_c++] = cat;
}

void Driver::releaseVehicle(Vehicle* vehicle)
{
	if (size == 0) {
		cout << "You do not have a vehicle" << endl;
		return;
	}
	int index = findVehicle(vehicle);
	if (index == -1) {
		cout << "Vehicle not found" << endl;
		return;
	}
	vehicle->clearOwner();
	deleteVehicle(index);
}
