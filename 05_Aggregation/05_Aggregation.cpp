#include <iostream>
#include "task_1_association.h"
#include "task_2_aggregation.h"
#include "task_3_composible.h"
using namespace std;


int main()
{
    {
        cout << "\n================= Task 1 =====================\n";
        Driver ivan("Ivan", "453-76RV");
        Driver denis("Denis", "453-76RV");
        Vehicle car("car");
        Vehicle scooter("scooter");
        Vehicle bus("bus");
        cout << "\nTest adding vehicle" << endl;
        ivan.assignVehicle(&car);
        cout << "\nTest adding category" << endl;
        ivan.addCategory('B');
        ivan.assignVehicle(&car);
        cout << "\nTest adding category" << endl;
        denis.addCategory('B');
        denis.assignVehicle(&car);
        cout << "\nTest adding vehicle" << endl;
        denis.assignVehicle(&scooter);
        cout << "\nTest adding category" << endl;
        denis.addCategory('A');
        cout << "\nTest adding vehicle" << endl;
        denis.assignVehicle(&scooter);
        denis.addCategory('D');
        denis.assignVehicle(&bus);
        denis.showInsurance();
        system("pause");
        system("cls");
    }

    {
        cout << "\n================= Task 2 =====================\n";

        Smartphone iphone;
        Smartphone sam("Samsung","A-45","Micro-USB",3000);

        Charger lig("Lightning");
        Charger m_usb("Micro-USB");

        iphone.connectCharger(&m_usb);
        sam.connectCharger(&lig);

        iphone.connectCharger(&lig);
        sam.connectCharger(&m_usb);

        iphone.hargerInfo();
        sam.hargerInfo();
        system("pause");
        system("cls");
    }


    {
        cout << "\n================= Task 3 =====================\n";

        Car* bmw = new Car("BMW");
        Car* ford = new Car("Ford","Ford",100);
        cout << "Before Mileage :: \n";
        cout << "\t";
        bmw->showMileage();
        cout << "\t";
        ford->showMileage();

        bmw->drive(150);
        ford->drive(100);
        cout << "After adding Mileage :: \n";
        cout << "\t";
        bmw->showMileage();
        cout << "\t";
        ford->showMileage();

        cout << "Reset Mileage bmw:: \n";
        bmw->resetOdometer();
        cout << "\t";
        bmw->showMileage();
        cout << "\t";
        ford->showMileage();

        delete bmw;
        delete ford;
    }
}
