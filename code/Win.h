#pragma once
#include "Object.h"
#include <filesystem>

class Win : public Object {
public:
	Win(int x, int y, int width, int height);
	void Update();
};