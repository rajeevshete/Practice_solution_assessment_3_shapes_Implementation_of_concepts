#include"shape.h"

shape::shape() {}

shape::shape(const string& n)
{
	name = n;
}

shape::~shape() {}

string shape::getname() const
{
	return name;
}

bool shape::operator < (const shape& next) const
{
	return this->area() < next.area();
}