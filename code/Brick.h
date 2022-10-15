#pragma once
#include "Object.h"
#include "Colder.h"
#include <filesystem>

class Brick : public Object {
public:
	// you depend on folder location
	Brick(int x, int y, int width, int height);
	void Update();
	Colider* myColider = new Colider(o_width, o_height, this);
	bool isBrick = true;
private:

};