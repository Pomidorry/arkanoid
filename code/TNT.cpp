#include "TNT.h"
TNT::TNT(int x, int y, int width, int height) :Brick(x, y, width, height) {
	o_position.x = x;
	o_position.y = y;
	std::filesystem::path tmp = std::filesystem::current_path();
	o_path = tmp.string() + "\\data\\\\13-Breakout-Tiles.png";
};