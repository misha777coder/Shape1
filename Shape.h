#pragma once
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

const double Pi = 3.14;

class Shape {
public:
	virtual~Shape() {}
	virtual void in(istream&) abstract;
	virtual void out(ostream&) abstract;

	virtual double per() const abstract;
	virtual double area() const abstract;
};