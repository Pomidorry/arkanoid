#include "NegativeBonus.h"
NegativeBonus::NegativeBonus( int width, int height) : Object(width, height) {
	std::filesystem::path tmp = std::filesystem::current_path();
	o_path = tmp.string() + "\\data\\\\08-Breakout-Tiles.png";
};
void NegativeBonus::SetPosition(std::vector<Point> v) {
	o_position.x = v[rand() % v.size()].x;
	o_position.y = v[rand() % v.size()].y;
}
void NegativeBonus::Update() {
	
		SetVelocity(3);
		SetPath();
		DrawObject();
		Move();
		Destroy();
}
void NegativeBonus::Move() {
	o_position.y += yVelocity;
}
void NegativeBonus::SetVelocity(int y) {
	yVelocity = y;
}

void NegativeBonus::CatchByPlatform(Platform& plat) {
	if (plat.GetPosition().x <= GetPosition().x
		&& plat.GetPosition().x + plat.GetWidth() >= GetPosition().x
		&& GetPosition().y <= plat.GetHeight() + plat.GetPosition().y
		&& GetPosition().y >= plat.GetPosition().y) {
		onStage = false;
		isCatched = true;
	}
}
Point NegativeBonus::Effect(std::vector<Point> v) {
	return v[rand() % v.size()];
}