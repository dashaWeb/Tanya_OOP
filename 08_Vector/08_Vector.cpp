#include <iostream>
#include "Vector.h"
using namespace std;
int main()
{
	Vector v1(10);
	Vector v2(10, 2);

	cout << "V1 ----> \t Size :: " << v1.size_() << "\t Capacity :: " << v1.capacity_() << endl;
	v1.print();
	cout << "V2 ----> \t Size :: " << v2.size_() << "\t Capacity :: " << v2.capacity_() << endl;
	v2.print();

	Vector v3(v2);
	cout << "V3 ----> \t Size :: " << v3.size_() << "\t Capacity :: " << v3.capacity_() << endl;
	v3.print();
	v3.front() = 33;
	v3.back() = 55;
	v3.print();
	while (true)
	{
		v3.remove(15);
		v3.print();
		system("pause");
	}
}
