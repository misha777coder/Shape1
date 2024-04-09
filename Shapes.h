#pragma once
#include "Cylinder.h"
#include "Parallelepiped.h"
#include "Piramid.h"
#include "Cone.h"
class Shapes {
	int size;
	vector<direct_shape*> Shapess;
public:
	Shapes() : size(0) {}
	Shapes(int s) : size(s) {}
	Shapes(const Shapes& S) : size(S.size) {
		Shapess.reserve(S.Shapess.size());
		for (direct_shape* shape : S.Shapess) {
			Shapess.push_back(copy(shape));
		}
		for (int i = 0; i < size; i++)
		{
			Shapess[i] = copy(S.Shapess[i]);
		}
	}
	~Shapes() {
		for (direct_shape* i : Shapess) {
			delete i;
		}
		Shapess.clear();
	}

	bool isEmpty() const;
	void add(size_t, direct_shape*);
	void pop(size_t);
	void deleteAll();

	direct_shape* copy(direct_shape*) const;

	void operator=(const Shapes&);
	direct_shape* operator[](size_t);

	friend istream& operator>>(istream&, Shapes&);
	friend ostream& operator<<(ostream&, const Shapes&);
};


