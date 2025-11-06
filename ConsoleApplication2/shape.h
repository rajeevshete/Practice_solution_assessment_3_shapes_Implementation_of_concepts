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
	virtual double area() const = 0;
	virtual double perimeter() const = 0;
};