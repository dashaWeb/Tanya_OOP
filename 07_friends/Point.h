#pragma once
#include <iostream>
#include <math.h>
using std::cout;
using std::pow;

class Line;

class Point
{
	double x, y;
	friend bool Equals(const Point& A, const Point& B);
	friend Line;
public:
	Point(const double& x, const double& y)
	:x(x), y(y){}
	void print()const;
};

class Line {
	Point left, right;
public:
	Line(const double& x1, const double& y1, const double& x2, const double& y2)
	:left(x1,y1), right(x2,y2){}
	Line(const Point& left, const Point& right) :
		left(left), right(right) {}
	double length() const;
	void show() const;
};

inline void Point::print() const {
	cout << "(" << x << "," << y << ")";
}
inline double Line::length() const
{
	return sqrt(pow(right.x - left.x, 2) + pow(right.y - left.y, 2));
}

inline void Line::show() const
{
	cout << "Length line :: " << this->length() << "\n";
}
