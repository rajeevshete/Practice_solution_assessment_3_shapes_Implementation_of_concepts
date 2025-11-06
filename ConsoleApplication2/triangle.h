#pragma once
#include"shape.h"

class triangle : public shape
{
private: 
	double side1;
	double side2;
	double side3;
	double s;

public: 
	triangle();
	triangle(double a, double b, double c);
	~triangle();
	double area() const override;
	double perimeter() const override;
};
