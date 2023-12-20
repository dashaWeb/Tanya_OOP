#include <iostream>
#include <ctime>
#include "Fraction.h"
#include "Circle.h"
using namespace std;



Circle* createArray(const size_t& size) {
    Circle* tmp = new Circle[size];
    for (size_t i = 0; i < size; i++)
    {
        tmp[i].setRadius(rand() % 20 + 1);
    }
    return tmp;
}
void print(const Circle* arr, const size_t& size) {
    for (size_t i = 0; i < size; i++)
    {
        cout << "Circle #" << i+1  << " radius = " << arr[i].getRadius() << "\n";
    }
}
//Circle minCircle(const Circle* arr, const size_t& size) {
//    Circle min_radius = arr[0];
//    for (size_t i = 1; i < size; i++)
//    {
//        if (min_radius.getRadius() > arr[i].getRadius()) {
//            min_radius.setRadius(arr[i].getRadius());
//        }
//    }
//    return min_radius;
//}
//Circle max(const Circle* arr, const size_t& size) {
//    Circle max_radius = arr[0];
//    for (size_t i = 1; i < size; i++)
//    {
//        if (max_radius.getRadius() < arr[i].getRadius()) {
//            max_radius.setRadius(arr[i].getRadius());
//        }
//    }
//    return max_radius;
//}

size_t minCircle(const Circle* arr, const size_t& size) {
    size_t index = 0;
    for (size_t i = 1; i < size; i++)
    {
        if (arr[index].getRadius() > arr[i].getRadius()) {
            index = i;
        }
    }
    return index;
}
size_t maxCircle(const Circle* arr, const size_t& size) {
    size_t index = 0;
    for (size_t i = 1; i < size; i++)
    {
        if (arr[index].getRadius() < arr[i].getRadius()) {
            index = i;
        }
    }
    return index;
}
int main()
{
    /*Fraction one(2,5);
    Fraction two(3,7);

    one.print();
    cout << endl;
    two.print();
    cout << endl;

    Fraction res = one.add(two);
    cout << "Sum :: \n";
    cout << one.toString() << " + " << two.toString() << " = " << res.toString() << endl;
    res = one.sub(two);
    cout << "Sub :: \n";
    cout << one.toString() << " - " << two.toString() << " = " << res.toString() << endl;
    res = one.mult(two);
    cout << "Mult :: \n";
    cout << one.toString() << " * " << two.toString() << " = " << res.toString() << endl;
    res = one.division(two);
    cout << "Divisiov :: \n";
    cout << one.toString() << " / " << two.toString() << " = " << res.toString() << endl;

    cout << "Sum number :: \n";
    res = one.addNum(3);
    cout << one.toString() << " + " << 3 << " = " << res.toString() << endl;

    cout << "Sum number :: \n";
    res = one.multNum(3);
    cout << one.toString() << " * " << 3 << " = " << res.toString() << endl;

    cout << "Equals :: " << boolalpha << one.toString() << " == " << two.toString() << ": " << one.Equals(two) << endl;
    two.setNum(2);
    cout << "Equals :: " << boolalpha << one.toString() << " == " << two.toString() << ": " << one.Equals(two) << endl;
    Fraction test(66, 99);
    cout << "Reduction :: " << test.toString() << " = ";
    test.reduction();
    cout << test.toString() << "\n";*/
    srand(time(0));
    Circle radius_1(5);
    const Circle radius_2(10);
    Circle* radius_3 = new Circle(15);

    delete radius_3; 

    Circle* arr = createArray(5);
    print(arr, 5);
    /*Circle min_ = minCircle(arr, 5);
    Circle max_ = max(arr, 5);*/
    int min_ = minCircle(arr, 5);
    int max_ = maxCircle(arr, 5);
    cout << "Min radius :: " << arr[min_].getRadius() << endl;
    cout << "Max radius :: " << arr[max_].getRadius() << endl;
    delete[] arr;
}

