#include"rectangle.h"

rectangle::rectangle() {}

rectangle::rectangle(double l, double w)
{
	name = "rectangle";
	length = l;
	width = w;
}

rectangle::~rectangle() {}

double rectangle::area() const
{
	return length * width;
}

double rectangle::perimeter() const
{
	return 2*(length + width);
}