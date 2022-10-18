#include "Lose.h"
Lose::Lose(int x, int y, int width, int height) : Object(width, height) {
	o_position.x = x;
	o_position.y = y;
	std::filesystem::path tmp = std::filesystem::current_path();
	o_path = tmp.string() + "\\data\\\\08-Breakout-Tiles.png";
};
void Lose::Update() {
	SetPath();
	DrawObject();
	Destroy();
};