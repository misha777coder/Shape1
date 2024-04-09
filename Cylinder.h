#pragma once
#include "Circle.h"
#include "volum_shape.h"

class Cylinder : public volume_shape {
public:
	Cylinder() : volume_shape() {}
	Cylinder(double R, double H) : volume_shape(dynamic_cast<Shape*>(new Circle(R)), H) {}
	Cylinder(const Cylinder& c) : volume_shape(c)
	{
		base = dynamic_cast<Shape*>(new Circle(*dynamic_cast<Circle*>(c.base)));
	}
	virtual~Cylinder() {}

	double volume() const override {
		return dynamic_cast<Circle*>(base)->area() * h;
	}
	double sideArea() const override {
		return dynamic_cast<Circle*>(base)->per() * h;
	}
	double surfaceArea() const override {
		return 2 * dynamic_cast<Circle*>(base)->area() + sideArea();
	}

	void setH(double H) {
		h = (H > 0.1) ? H : 0.1;
	}

	void in(istream& is) override {
		double R;
		is >> R >> h;
		dynamic_cast<Circle*>(base)->setR(R);
	}
	void out(ostream& os) const override {
		os << "Cylinder  r: " << dynamic_cast<Circle*>(base)->getR() << "\th:" << h << "\n\tVolume: " << volume() << "\tSideArea: " << sideArea() << "\tSurfaceArea: " << surfaceArea();
	}
};

