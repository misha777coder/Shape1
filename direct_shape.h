#pragma once
#include "Shape.h"

class direct_shape {
protected:
	Shape* base;
	double h;
public:
	direct_shape() : base(nullptr), h(1) {}
	direct_shape(Shape* b, double H) : base(b), h(H) {}
	virtual~direct_shape() {}

	virtual void in(istream& is) { base->in(is); }
	virtual void out(ostream& os) const { base->out(os); }

	virtual double area() const { return base->area(); }
	virtual double per() const { return base->per(); }

	friend istream& operator>>(istream& is, direct_shape& S) {
		S.in(is);
		return is;
	}
	friend ostream& operator<<(ostream& os, const direct_shape& S) {
		S.out(os);
		return os;
	}
};

	