#include "PositiveBonus.h"
PositiveBonus::PositiveBonus(int width, int height) : Object(width, height) {
	std::filesystem::path tmp = std::filesystem::current_path();
	o_path = tmp.string() + "\\data\\\\03-Breakout-Tiles.png";
};
void PositiveBonus::SetPosition(std::vector<Point> v) {
	o_position.x = v[rand() % v.size()].x;
	o_position.y = v[rand() % v.size()].y;
}
void PositiveBonus::Update() {

	SetVelocity(3);
	SetPath();
	DrawObject();
	Move();
	Destroy();
}
void PositiveBonus::Move() {
	o_position.y += yVelocity;
}
void PositiveBonus::SetVelocity(int y) {
	yVelocity = y;
}

void PositiveBonus::CatchByPlatform(Platform& plat) {
	if (plat.GetPosition().x <= GetPosition().x
		&& plat.GetPosition().x + plat.GetWidth() >= GetPosition().x
		&& GetPosition().y <= plat.GetHeight() + plat.GetPosition().y
		&& GetPosition().y >= plat.GetPosition().y) {
		onStage = false;
		isCatched = true;
	}
}
