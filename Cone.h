#pragma once
#include "Circle.h"
#include "volum_shape.h"

class Cone : public volume_shape {
public:
	Cone() : volume_shape() {
		base = new Circle;
	}
	Cone(double R, double H) : volume_shape(dynamic_cast<Shape*>(new Circle(R)), H) {}
	virtual~Cone() {}

	double volume() const override {
		return 0.33 * dynamic_cast<Circle*>(base)->area() * h;
	}
	double sideArea() const override {
		double R = dynamic_cast<Circle*>(base)->getR();
		return Pi * R * sqrt(h * h + R * R);
	}
	double surfaceArea() const override {
		return dynamic_cast<Circle*>(base)->area() + sideArea();
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
		os << "Cone  r: " << dynamic_cast<Circle*>(base)->getR() << "\th:" << h << "\n\tVolume: " << volume() << "\tSideArea: " << sideArea() << "\tSurfaceArea: " << surfaceArea();
	}
};

