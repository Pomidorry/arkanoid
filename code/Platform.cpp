#include "Platform.h"
Platform::Platform(int x, int y, int s, int width, int height) : Object(width, height) {
	o_position.x = x;
	o_position.y = y;
	step = s;
	std::filesystem::path tmp = std::filesystem::current_path();
	o_path = tmp.string() + "\\data\\\\17-Breakout-Tiles.png";
};
void Platform::MovePlatform(FRKey k) {
	if (k == FRKey::RIGHT) {
		o_position.x += step; // magic number
	}
	if (k == FRKey::LEFT) {
		o_position.x -= step;
	}
};
void Platform::Collision() {
	if (o_position.x < 0) {
		o_position.x = 0;
	}
	if (o_position.x > 700) {
		o_position.x = 700;
	}
};
void Platform::Destroy() {
	destroySprite(texture);
};
void Platform::Update() {
	SetPath(); // you depend on folder location
	Collision();
	DrawObject();
	Destroy();
};