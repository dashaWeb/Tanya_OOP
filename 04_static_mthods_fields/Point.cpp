#include "Point.h"


char Point::lastName = 'A'-1;
int Point::counter = 0;
void Point::print() const
{
	cout << name << "(" << x << "," << y << ")";
}
const double& Point::distance() const
{
	return sqrt(pow(x, 2) + pow(y, 2));
}

Point Point::sub(const Point& other) const
{
	return Point(this->x - other.x, this->y -  other.y);
}

int Point::getCounter()
{
	return counter;
}

bool Point::Equals(const Point& first, const Point& second)
{
	return first.x == second.x and first.y == second.y;
}

int Point::cmpDistance(const Point& first, const Point& second)
{
	double first_d = first.distance(), second_d = second.distance();
	if (first_d == second_d) return 0;
	return first_d > second_d ? 1 : -1;
}

Point Point::maxDistance(const Point* points, const size_t& size)
{
	Point max = points[0];
	for (size_t i = 1; i < size; i++)
	{
		if(cmpDistance(max, points[i]) < 0){
			max = points[i];
		}
	}
	return max;
	
}

Point Point::sum(const Point& other) const
{
	return Point(this->x + other.x, this->y + other.y);
}
