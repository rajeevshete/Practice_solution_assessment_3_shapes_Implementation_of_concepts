#include"triangle.h"
#include<cmath>

triangle::triangle() {}

triangle::triangle(double a, double b, double c)
{
	name = "triangle";
	side1 = a;
	side2 = b;
	side3 = c;
	s = (side1 + side2 + side3) / 2;
}

triangle::~triangle() {}

double triangle::area() const
{
	return sqrt(s * (s - side1) * (s - side2) * (s - side3));
}

double triangle::perimeter() const
{
	return side1 + side2 + side3;
}