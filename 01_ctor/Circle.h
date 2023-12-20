#pragma once
#include <iostream>
class Circle
{
private:
	double radius;
	const double PI = 3.14159;
public:
	Circle():Circle(0)
	{

	}
	Circle(const double& radius)
	{
		setRadius(radius);
	}
	void setRadius(const double& radius);
	const double& getRadius() const;
	const double& area() const;
	const double& diametr() const;
	const double& length() const;
	~Circle()
	{
		std::cout << "Removing a circle object with a radius of " << getRadius() << std::endl;
	}
};

inline void Circle::setRadius(const double& radius)
{
	if (radius >= 0) {
		this->radius = radius;
	}
}

inline const double& Circle::getRadius() const
{
	return this->radius;
}
