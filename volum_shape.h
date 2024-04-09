#pragma once
#include "direct_shape.h"

class volume_shape: public direct_shape {
public:
	volume_shape() : direct_shape() {}
	volume_shape(Shape* b, double H) : direct_shape(b, H) {}
	virtual~volume_shape() {}

	virtual void in(istream& is) { base->in(is); }
	virtual void out(ostream& os) const { base->out(os); }

	virtual double volume() const abstract;
	virtual double sideArea() const abstract;
	virtual double surfaceArea() const abstract;
};