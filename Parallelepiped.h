#pragma once
#include "Rectangle.h"
#include "volum_shape.h"

class Parallelepiped : public volume_shape {
public:
	Parallelepiped() : volume_shape() {}
	Parallelepiped(double A, double B, double H) : volume_shape(dynamic_cast<Shape*>(new Rectangle(A, B)), H) {
		h = (H > 0) ? H : 0.1;
	}
	virtual~Parallelepiped() {}

	double volume() const override {
		return dynamic_cast<Rectangle*>(base)->area() * h;
	}
	double sideArea() const override {
		return dynamic_cast<Rectangle*>(base)->per() * h;
	}
	double surfaceArea() const override {
		return 2 * dynamic_cast<Rectangle*>(base)->area() + sideArea();
	}

	void setH(double H) {
		h = (H > 0.1) ? H : 0.1;
	}

	void in(istream& is) override {
		double A, B;
		is >> A >> B >> h;
		dynamic_cast<Rectangle*>(base)->setA(A);
		dynamic_cast<Rectangle*>(base)->setB(B);
	}
	void out(ostream& os) const override {
		os << "Parallelepiped  a: " << dynamic_cast<Rectangle*>(base)->getA() << "\tb: " << dynamic_cast<Rectangle*>(base)->getB() << "\th:" << h << "\n\tVolume: " << volume() << "\tSideArea: " << sideArea() << "\tSurfaceArea: " << surfaceArea();
	}
};

