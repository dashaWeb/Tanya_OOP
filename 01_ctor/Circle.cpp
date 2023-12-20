#include "Circle.h"
const double& Circle::area() const
{
	return  PI * radius * radius;
}

const double& Circle::diametr() const
{
	return this->radius * 2;
}

const double& Circle::length() const
{
	return PI * diametr();
}
