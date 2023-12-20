#include "task_2_aggregation.h"

void Smartphone::connectCharger(Charger* newCharger)
{
    if (newCharger->getConnectorType() == requiredConnector && currentCharger == nullptr) {
        currentCharger = newCharger;
    }
    else
    {
        cout << "The charger connector is not compatible with the needs of the "<<this->brand<<" \n";
    }
}

void Smartphone::isconnectCharger()
{
    if (currentCharger != nullptr) {
        currentCharger = nullptr;
    }
}

void Smartphone::hargerInfo() const
{
    if (currentCharger != nullptr) { 
        cout << "\nthe charger "<< this->currentCharger->getConnectorType() << " is connected\n"; }
    else {
        cout << "\nthe charger is not connected\n";
    }
}

string Charger::getConnectorType() const
{
    return connectorType;
}
