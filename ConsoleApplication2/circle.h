#pragma once
#include"shape.h"

class circle : public shape
{
private :
	double radius;

public: 
	circle();
	circle(double r);
	~circle();
	double area() const override;
	double perimeter() const override;
};
