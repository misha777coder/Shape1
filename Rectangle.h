#pragma once
#include "direct_shape.h"
class Rectangle : public direct_shape {
protected:
	double a, b;
public:
	Rectangle() : a(1.), b(1.) {}
	Rectangle(double A, double B) {
		a = (A > 0.1) ? A : 0.1;
		b = (B > 0.1) ? B : 0.1;
	}
	virtual~Rectangle() {}

	double per() const override { return a + b; }
	double area() const override { return a * b; }

	virtual void setA(double A) { a = (A > 0.1) ? A : 0.1; }
	virtual void setB(double B) { b = (B > 0.1) ? B : 0.1; }

	double getA() const {
		return a;
	}
	double getB() const {
		return b;
	}

	void in(istream& is) override {
		is >> a >> b;
	}
	void out(ostream& os) const override {
		os << "Rectangle  a: " << a << "\tb: " << b << "\ntArea: " << area() << "\tPer: " << per();
	}
};

