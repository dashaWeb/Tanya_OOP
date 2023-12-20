#include <iostream>
#include "Date.h"
using namespace std;
int main()
{
    Date date(31, 03, 2004);
    date.displayDate();
    cout << endl;

    date.incrementDate();
    cout << "incrementDate :: ";
    date.displayDate();
    cout << endl;

    date.setDate(29, 02, 2004);
    date.displayDate();
    cout << endl;
    date.incrementDate();
    cout << "incrementDate :: ";
    date.displayDate();
    cout << endl;


    date.setDate(31, 12, 2004);
    date.displayDate();
    cout << endl;
    date.incrementDate();
    cout << "incrementDate :: ";
    date.displayDate();
    cout << endl;

    date.decrementDate();
    cout << "decrementDate :: ";
    date.displayDate();
    cout << endl;

    date.decrementDate();
    cout << "decrementDate :: ";
    date.displayDate();
    cout << endl;
}

