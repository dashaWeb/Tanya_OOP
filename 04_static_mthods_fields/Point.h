#pragma once
#include <iostream>
#include <math.h>
using namespace std;
class Point
{
	int x, y;
	char name;
	static int counter;
	static char lastName;
public:
	Point(const int& x, const int& y)
		:x{ x }, y{y}
	{
		name = ++lastName;
		counter++;
	}
	explicit Point(const int& x)
		:Point(x,0)
	{
	}
	Point(const Point& other):Point(other.x, other.y)
	{

	}
	void print() const;
	const int& getX() const;
	const int& getY() const;
	void setX(const int& x);
	void setY(const int& y);
	const double& distance() const;
	Point sum(const Point& other)const;
	Point sub(const Point& other)const;
	static int getCounter();
	static bool Equals(const Point& first, const Point& second);
	static int cmpDistance(const Point& first, const Point& second);
	static Point maxDistance(const Point* points, const size_t& size);
	~Point()
	{
		--counter;
	}
};

inline const int& Point::getX() const
{
	return x;
}

inline const int& Point::getY() const
{
	return y;
}

inline void Point::setX(const int& x)
{
	this->x = x;
}

inline void Point::setY(const int& y)
{
	this->y = y;
}