#pragma once
#include <iostream>
using namespace std;
class Charger
{
	string connectorType;
	int outputPower;
public:
	Charger(const string& connectType)
		:Charger(connectType, 4000) {}
	Charger(const string& connectType, const int& power)
		:connectorType(connectType),outputPower(power)
	{}
	string getConnectorType() const;
};

class Smartphone
{
	string brand, model, requiredConnector;
	int batteryCapacity;
	Charger* currentCharger = nullptr;
public:
	Smartphone()
		: Smartphone("iPhone ") {}
	Smartphone(const string& brand)
		: Smartphone(brand, "15 Pro") {}
	Smartphone(const string& brand, const string& model)
		: Smartphone(brand, model,"Lightning") {}
	Smartphone(const string& brand, const string& model, const string& requiredConnector)
		: Smartphone(brand, model, requiredConnector, 4000) {}
	Smartphone(const string& brand, const string& model, const string& requiredConnector, const int& batteryCapacity)
		:brand(brand),model(model),requiredConnector(requiredConnector),batteryCapacity(batteryCapacity)
	{}
	void connectCharger(Charger* newCharger);
	void isconnectCharger();
	void hargerInfo() const;
};

