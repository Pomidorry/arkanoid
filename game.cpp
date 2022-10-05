#include <string>
#include <iostream>
#include <cmath>
#include <vector>
#include "Framework.h"
/* Test Framework realization */

struct Point {
	Point() {};
	Point(int x1, int y1) {
		x = x1;
		y = y1;
	};
	double x;
	double y;
};

struct Vector  {
	double xV;
	double yV;
	Vector(Point B, Point A, int l) {
		xV = (B.x - A.x)/l;
		yV = (B.y - A.y)/l;
	}
};

class Ball {
public:
	Ball() {
		position.x = 380;
		position.y = 530;
	};
	void SetPath(const char* path) {
		texture = createSprite(path);
	};
	void DrawBall() {
		setSpriteSize(texture, width, height);
		drawSprite(texture, position.x, position.y);
	};
	void Destroy() {
		destroySprite(texture);
	};
	void setIdle(bool on) {
		isIdle = on;
	}
	bool getIdle() {
		return isIdle;
	}
	void SetVelocityDirection(int xMouse, int yMouse) {
		if (xMouse > 400) {
			yVelocity = -2;
			xVelocity = 2;
		}
		else {
			yVelocity = -2;
			xVelocity = -2;
		}
	};
	void SetVelocity(int dx, int dy) {
		xVelocity *= dx;
		yVelocity *= dy;
	}
	void SetPosition(Point p) {
		position = p;
	}
	void Move() {
		position.x += xVelocity;
		position.y += yVelocity;
		if (position.x >= 800 || position.x <= 0) {
			xVelocity *= -1;
		}
		if (position.y <= 0) {
			yVelocity *= -1;
		}
	};
	Point GetPosition() {
		return position;
	};
private:
	int width = 20;
	int height = 20;
	Point position;
	Sprite* texture;
	double xVelocity=0;
	double yVelocity = 0;
	bool isIdle = false;
};
class Colider {
public:
	Colider(int w, int h, Point p) {
		width = w;
		height = h;
		position = p;
	}
	bool isColide(Point p) {
		if (p.x > position.x-20 && p.x < position.x + 100+20 && p.y==position.y) {
			return 1;
		}
		else {
			return 0;
		}
	}
	Vector Colide(Point curr,Point prev) {
			int a = abs(prev.x - curr.x);
			int b = abs(prev.y - curr.y);
			double c = sqrt(a * a + b * b);
			Point A (prev.x, 600-50);
			int pA = abs(prev.y-600+50);
			int k = pA * c / b;
			double BA = sqrt(k * k + pA ^ 2);
			Point P(prev.x + 2 * BA, prev.y);
			Point B(A.x + BA, A.y);
			Vector norm(P, B, k);
			return norm;
	}
	void ColiderUpdate(Point p) {
		position = p;
	}
private:
	int width;
	int height;
	Point position;
};
class Platform {
public:
	Platform() {
		position.x = 350;
		position.y = 550;
	}
	void SetPath(const char* path) {
		texture = createSprite(path);
	};
	void DrawPlatform() {
		setSpriteSize(texture, width, height);
		drawSprite(texture, position.x, position.y);
	}
	void MovePlatform(FRKey k) {
		if (k == FRKey::RIGHT) {
			position.x += 50;
		}
		if (k == FRKey::LEFT) {
			position.x -= 50;
		}
	}
	void Collision() {
		if (position.x < 0) {
			position.x = 0;
		}
		if (position.x > 700) {
			position.x = 700;
		}
	}

	void Destroy() {
		destroySprite(texture);
	};
	void PlatformUpdate() {
		SetPath("C:\\17-Breakout-Tiles.png");
		Collision();
		DrawPlatform();
		Destroy();
	};
	Point GetPosition() {
		return position;
	}
	Colider* myColider = new Colider(100, 50, GetPosition());
	
private:
	int width = 100;
	int height = 50;
	Point position;
	Sprite* texture;
};

class MyFramework : public Framework {

public:

	virtual void PreInit(int& width, int& height, bool& fullscreen)
	{
		width = 800;
		height = 600;
		fullscreen = false;
	}

	virtual bool Init() {

		return true;
	}

	virtual void Close() {

	}
	virtual void onKeyPressed(FRKey k) {
		platform->MovePlatform(k);
	}

	virtual bool Tick() {
		platform->PlatformUpdate();
		platform->myColider->ColiderUpdate(platform->GetPosition());
		ball->SetPath("C:\\13-Breakout-Tiles.png");
		Point prev = ball->GetPosition();
		ball->Move();
		Point curr = ball->GetPosition();
		if (platform->myColider->isColide(curr)) {
			std::cout << 1;
			ball->SetPosition(prev);
			ball->SetVelocity(platform->myColider->Colide(curr, prev).xV, platform->myColider->Colide(curr, prev).yV);
		}
		ball->DrawBall();
		ball->Destroy();
		return false;
	}

	virtual void onMouseMove(int x, int y, int xrelative, int yrelative) {
		if (ball->getIdle()) {
			ball->SetVelocityDirection(x, y);
			ball->setIdle(false);
		}
	}

	virtual void onMouseButtonClick(FRMouseButton button, bool isReleased) {
		if (button == FRMouseButton::LEFT && isReleased) {
			ball->setIdle(isReleased);
		}
	}



	virtual void onKeyReleased(FRKey k) {
		
		
	}

	virtual const char* GetTitle() override
	{
		return "Arcanoid";
	}
private:
	Platform* platform=new Platform();
    Ball* ball = new Ball();
};
	

int main(int argc, char *argv[])
{
	return run(new MyFramework);
}
