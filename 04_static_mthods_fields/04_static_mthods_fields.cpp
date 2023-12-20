#include <iostream>
#include "Point.h"
using namespace std;

int main()
{
    Point A(2,5);
    A.print();
    cout << endl;

    Point B(7, 8);
    B.print();
    cout << endl;
    cout << "Counter point :: " << Point::getCounter() << endl;

    Point sum = A.sum(B);
    Point sub = A.sub(B);
    cout << "\n Sum :: ";
    A.print();
    cout << " + ";
    B.print();
    cout << " = ";
    sum.print();
    cout << endl;
    cout << "\n Sub :: ";
    A.print();
    cout << " - ";
    B.print();
    cout << " = ";
    sub.print();
    cout << endl;
    cout << "\n Equals :: ";
    A.print();
    cout << " == ";
    B.print();
    cout << ":: " << boolalpha << Point::Equals(A, B) << endl;
    cout << "\n Distance A :: " << A.distance() << endl;
    cout << " Distance B :: " << B.distance() << endl;
    cout << " compare distance A and B :: " << Point::cmpDistance(A, B) << endl;

    int size = 5;
    Point* points = new Point[]{ A,B,{4,5},{9,36}, {14,5}};
    for (size_t i = 0; i < size; i++)
    {
        points[i].print(); cout << "\t distance :: " << points[i].distance() << endl;
    }
    cout << "Point Max distance :: ";
    Point::maxDistance(points, size).print();
    cout << endl;

    cout << "Counter points :: " << Point::getCounter() << endl;
    delete[] points;
    cout << "After delete counter points :: " << Point::getCounter() << endl;

    
}

