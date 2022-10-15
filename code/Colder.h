#pragma once
#include "Object.h"
#include "Stucts.h"

class Colider {
public:
	Colider(int w, int h, const Object* object);
	// Is colide should work not with point but with another colider
	bool isColide(Point p);
	NormalizeVector Colide(Point curr, Point prev);


private:
	int width;
	int height;
	const Object* const object;
};
