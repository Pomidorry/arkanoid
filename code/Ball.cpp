#include "Ball.h"
Ball::Ball(int x, int y, int width, int height) : Object(width, height) {
	o_position.x = x;
	o_position.y = y;
	std::filesystem::path tmp = std::filesystem::current_path();
	o_path = tmp.string() + "\\data\\\\17-Breakout-Tiles.png";
};
void Ball::Update() {
	SetPath(); // you depend on folder location
	DrawObject();
	Move();
	Death();
	Destroy();
};
void Ball::setIdle(bool on) {
	isIdle = on;
};
bool Ball::getIdle() const {
	return isIdle;
};
void Ball::SetVelocity(int x, int y) {
	xVelocity = x;
	yVelocity = y;
};
void Ball::ChangeDirection(int dx, int dy) {
	xVelocity *= dx;
	yVelocity *= dy;
}
void Ball::SetPosition(Point p) {
	o_position = p;
};
void Ball::Move() {
	o_position.x += xVelocity;
	o_position.y += yVelocity;
	if (o_position.x >= 800 || o_position.x <= 0) {
		SetPosition(o_position);
		xVelocity *= -1;
	}
	if (o_position.y <= 0 || o_position.y >= 600) {
		SetPosition(o_position);
		yVelocity *= -1;
	}
};
void Ball::Death() {
	if (o_position.y >= 580) {
		--ballCounter;
	}
}