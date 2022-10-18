#pragma once
#include "Object.h"
#include <filesystem>

class Lose : public Object{
public:
	Lose(int x, int y, int width, int height);
	void Update();
};