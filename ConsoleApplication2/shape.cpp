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