#pragma once
#include"shape.h"

class rectangle : public shape
{
private: 
	double length;
	double width;

public:
	rectangle();
	rectangle(double l, double w);
	~rectangle();
	double area() const override;
	double perimeter() const override;
};
