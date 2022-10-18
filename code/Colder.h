#pragma once
#include "Object.h"
#include "Stucts.h"

class Colider {
public:
	Colider( const Object* object);
	// Is colide should work not with point but with another colider
	bool isColide(Point p);
	/*Point Colide( Point prev);*/


private:
	int width;
	int height;
	const Object* const object;
};
