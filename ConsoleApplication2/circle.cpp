#include"circle.h"

circle::circle() {}

circle::circle(double r)
{
	name = "circle";
	radius = r;
}

circle::~circle() {}

double circle::area() const
{
	return radius * radius;
}

double circle::perimeter() const
{
	return 2 * 3.14 * radius;
}

