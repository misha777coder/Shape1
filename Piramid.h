#pragma once
#include "Triangle.h"
#include "volum_shape.h"

class Piramid : public volume_shape {
public:
	Piramid() : volume_shape() {}
	Piramid(double A, double B, double C, double H) : volume_shape(dynamic_cast<Shape*>(new Triangle(A, B, C)), H) {
		h = (H > 0) ? H : 0.1;
	}
	virtual~Piramid() {}

	double volume() const override {
		return 0.33 * dynamic_cast<Triangle*>(base)->area() * h;
	}
	double sideArea() const override {
		return 0.5 * dynamic_cast<Triangle*>(base)->per() * h;
	}
	double surfaceArea() const override {
		return dynamic_cast<Triangle*>(base)->area() + sideArea();
	}

	void setH(double H) {
		h = (H > 0.1) ? H : 0.1;
	}

	void in(istream& is) override {
		double A, B, C;
		is >> A >> B >> C >> h;
		dynamic_cast<Triangle*>(base)->setA(A);
		dynamic_cast<Triangle*>(base)->setB(B);
		dynamic_cast<Triangle*>(base)->setC(C);
	}
	void out(ostream& os) const override {
		os << "Piramid  a: " << dynamic_cast<Triangle*>(base)->getA() << "\tb: " << dynamic_cast<Triangle*>(base)->getB() << "\tc: " << dynamic_cast<Triangle*>(base)->getC() << "\th:" << h << "\n\tVolume: " << volume() << "\tSideArea: " << sideArea() << "\tSurfaceArea: " << surfaceArea();
	}
};

