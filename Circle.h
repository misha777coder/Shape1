#pragma once
#include "direct_shape.h"
class Circle : public direct_shape {
protected:
	double r;
public:
	Circle() : direct_shape(), r(1.) {}
	Circle(double R) {
		r = (R > 0.1) ? R : 0.1;
	}
	virtual~Circle() {}

	double per() const override { return 2 * Pi * r; }
	double area() const override { return Pi * pow(r, 2); }

	virtual void setR (double R) { r = (R > 0.1) ? R : 0.1; }
	double getR() const { return r; }

	void in(istream& is) override {
		is >> r;
	}
	void out(ostream& os) const override {
		os << "Circle  r: " << r << "\n  tArea: " << area() << "\tPer: " << per();
	}
};

