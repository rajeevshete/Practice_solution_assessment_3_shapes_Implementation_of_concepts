#pragma once
#include <iostream>
#include<string>
using namespace std;

class shape {
protected:
	string name;

public :
	shape();
	shape(const string& n);
	virtual ~shape();
	string getname() const;
	bool operator<(const shape& next) const;
	/*shape(const shape& a);*/		// copy constructor
	/*shape& operator=(const shape& b);*/		//Assignment operator
	virtual double area() const = 0;
	virtual double perimeter() const = 0;
};