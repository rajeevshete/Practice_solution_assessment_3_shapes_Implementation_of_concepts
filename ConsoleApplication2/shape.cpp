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

//shape::shape(const shape& a)		// copy constructor
//{
//	cout << "Copy constructor" << endl;
//}

//shape& shape::operator=(const shape& b)		//Assignment operator
//{
//	if (this != &b)
//	{
//		this->name = b.name;
//	}
//	return *this;
//}