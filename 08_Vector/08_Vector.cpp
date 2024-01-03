#include <iostream>
#include "Vector.h"
using namespace std;
int main()
{
	cout << "\n =================== Vector 1 ======================\n";
	Vector v1(2);
	cout << "Print V1 :: ";
	v1.print();
	cout << "\t Size :: " << v1.size_() << "\t Capacity :: " << v1.capacity_() << endl;

	cout << "\n =========================================\n";
	cout << "\n ============= PushBack(10) ================\n";
	v1.pushBack(10);
	cout << "Print V1 :: ";
	v1.print();
	cout << "\t Size :: " << v1.size_() << "\t Capacity :: " << v1.capacity_() << endl;

	cout << "\n ============= PushBack(20) ================\n";
	v1.pushBack(20);
	cout << "Print V1 :: ";
	v1.print();
	cout << "\t Size :: " << v1.size_() << "\t Capacity :: " << v1.capacity_() << endl;

	cout << "\n ============= PushBack(30) ================\n";
	v1.pushBack(30);
	cout << "Print V1 :: ";
	v1.print();
	cout << "\t Size :: " << v1.size_() << "\t Capacity :: " << v1.capacity_() << endl;
	
	cout << "\n =========================================\n";
	cout << "\n ============= PopBack() ================\n";
	if (!v1.empty()) {
		v1.popBack();
	}
	cout << "Print V1 :: ";
	v1.print();
	cout << "\t Size :: " << v1.size_() << "\t Capacity :: " << v1.capacity_() << endl;

	cout << "\n =========================================\n";
	cout << "\n ============= Reserve() ================\n";
	v1.reserve(20);
	cout << "Print V1 :: ";
	v1.print();
	cout << "\t Size :: " << v1.size_() << "\t Capacity :: " << v1.capacity_() << endl;
	
	cout << "\n =========================================\n";
	cout << "\n ============= Front() ================\n";
	v1.front() = 1234;
	cout << "Print V1 :: ";
	v1.print();
	cout << "\t Size :: " << v1.size_() << "\t Capacity :: " << v1.capacity_() << endl;

	cout << "\n =========================================\n";
	cout << "\n ============= Clear() ================\n";
	v1.clear();
	cout << "Print V1 :: ";
	v1.print();
	cout << "\t Size :: " << v1.size_() << "\t Capacity :: " << v1.capacity_() << endl;

	cout << "\n =========================================\n";
	cout << "\n ============= PushBack(1) ================\n";
	v1.pushBack(1);
	cout << "Print V1 :: ";
	v1.print();
	cout << "\t Size :: " << v1.size_() << "\t Capacity :: " << v1.capacity_() << endl;

	cout << "\n ============= PushBack(2) ================\n";
	v1.pushBack(2);
	cout << "Print V1 :: ";
	v1.print();
	cout << "\t Size :: " << v1.size_() << "\t Capacity :: " << v1.capacity_() << endl;

	cout << "\n ============= PushBack(3) ================\n";
	v1.pushBack(3);
	cout << "Print V1 :: ";
	v1.print();
	cout << "\t Size :: " << v1.size_() << "\t Capacity :: " << v1.capacity_() << endl;

	cout << "\n =========================================\n";
	cout << "\n =================== Vector 2 ======================\n";
	Vector v2(4,-1);
	cout << "Print V2 :: ";
	v2.print();
	cout << "\t Size :: " << v2.size_() << "\t Capacity :: " << v2.capacity_() << endl;

	cout << "\n =========================================\n";
	cout << "\n =================== Vector [1] ======================\n";
	v2[1]=20;
	cout << "Print V2 :: ";
	v2.print();
	cout << "\t Size :: " << v2.size_() << "\t Capacity :: " << v2.capacity_() << endl;


	cout << "\n =========================================\n";
	cout << "\n =================== Vector v3 = v1 + v2 ======================\n";
	Vector v3 = v1 + v2;
	cout << "Print V3 :: ";
	v3.print();
	cout << "\t Size :: " << v3.size_() << "\t Capacity :: " << v3.capacity_() << endl;

	cout << "\n =========================================\n";
	cout << "\n =================== Vector v3 = v1 * 5 ======================\n";
	v3 = v1 * 5;
	cout << "Print V3 :: ";
	v3.print();
	cout << "\t Size :: " << v3.size_() << "\t Capacity :: " << v3.capacity_() << endl;


	cout << "\n =========================================\n";
	cout << "\n =================== Vector v2 *= 10 ======================\n";
	v2 *= 10;
	cout << "Print V2 :: ";
	v2.print();
	cout << "\t Size :: " << v2.size_() << "\t Capacity :: " << v2.capacity_() << endl;

	cout << "\n =========================================\n";
	cout << "\n =================== Vector v2 += Vector(3,5) ======================\n";
	v2 += Vector(3,5);
	cout << "Print V2 :: ";
	v2.print();
	cout << "\t Size :: " << v2.size_() << "\t Capacity :: " << v2.capacity_() << endl;
}
