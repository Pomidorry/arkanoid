#include "Framework.h"
#include "Ball.h"
#include "Platform.h"
#include "Brick.h"
/* Test Framework realization */

//struct Point {
//	Point() {};
//	Point(int x1, int y1) {
//		x = x1;
//		y = y1;
//	};
//	double x;
//	double y;
//};
//
//struct NormalizeVector {
//	double xV;
//	double yV;
//	NormalizeVector(Point B, Point A, int l) {
//		xV = (B.x - A.x) / l;
//		yV = (B.y - A.y) / l;
//	}
//};
//class Object {
//public:
//	Object(int width, int height) {
//		o_width = width;
//		o_height = height;
//	}
//	void SetPath() {
//		texture = createSprite(o_path.c_str());
//	}
//	void DrawObject() {
//		setSpriteSize(texture, o_width, o_height);
//		drawSprite(texture, o_position.x, o_position.y);
//	}
//	void Destroy() {
//		destroySprite(texture);
//	};
//	Point GetPosition() const {
//		return o_position;
//	}
//	int GetWidth() const {
//		return o_width;
//	}
//	int GetHeight() const {
//		return o_width;
//	}
//	virtual void Update() = 0;
//protected:
//	Point o_position;
//	int o_width;
//	int o_height;
//	Sprite* texture;
//	std::string o_path;
//};
//class Ball : public Object {
//public:
//	// you depend on folder location
//	Ball(int x, int y, int width, int height) : Object(width, height) {
//		o_position.x = x;
//		o_position.y = y;
//		std::filesystem::path tmp = std::filesystem::current_path();
//		o_path = tmp.string() + "\\data\\\\17-Breakout-Tiles.png";
//	}
//
//	void Update() override {
//		SetPath(); // you depend on folder location
//		DrawObject();
//		Move();
//		Destroy();
//	}
//	void setIdle(bool on) {
//		isIdle = on;
//	}
//
//	// should be const
//	bool getIdle() {
//		return isIdle;
//	}
//	void SetVelocity(int x, int y) {
//		xVelocity = x;
//		yVelocity = y;
//	};
//	void ChangeDirection(int dx, int dy) {
//		xVelocity *= dx;
//		yVelocity *= dy;
//	};
//	void SetPosition(Point p) {
//		o_position = p;
//	};
//	void Move() {
//		o_position.x += xVelocity;
//		o_position.y += yVelocity;
//		if (o_position.x >= 800 || o_position.x <= 0) {
//			xVelocity *= -1;
//		}
//		if (o_position.y <= 0 || o_position.y >= 600) {
//			yVelocity *= -1;
//		}
//	};
//
//private:
//	double xVelocity = 0;
//	double yVelocity = 0;
//	bool isIdle = false;
//};
// I'm thinking about adding an event(programming patern) here. ColidedWithObject(Object);
// We can talk about it later
//class Colider {
//public:
//	Colider(int w, int h, const Object* object) : object(object) {
//		width = w;
//		height = h;
//	}
//	// Is colide should work not with point but with another colider
//	bool isColide(Point p) {
//		int collisionXNegative = object->GetPosition().x;
//		int collisionXPositive = object->GetPosition().x + width;
//		int collisionYNegative = object->GetPosition().y;
//		int collisionYPositive = object->GetPosition().y + height;
//		if (p.x >= collisionXNegative
//			&& p.x <= collisionXPositive
//			&& p.y >= collisionYNegative
//			&& p.y <= collisionYPositive) {
//			return 1;
//		}
//		else {
//			return 0;
//		}
//	}
//	NormalizeVector Colide(Point curr, Point prev) {
//		int prev_O = abs(prev.x - curr.x);
//		int curr_O = abs(prev.y - curr.y);
//		double prev_curr = sqrt(prev_O * prev_O + curr_O * curr_O);
//
//		if (prev.y < object->GetPosition().y) {
//			Point O1(prev.x, object->GetPosition().y);
//			int prev_B = abs(prev.y - O1.y);
//			int length = prev_B * prev_curr / prev_O;
//			double OA = sqrt(length * length + prev_B * prev_B);
//			Point O(prev.x + 2 * OA, prev.y);
//			Point A(O1.x + OA, O1.y);
//			NormalizeVector norm(O, A, OA);
//			return norm;
//		}
//		else if (prev.y >= object->GetPosition().y + height) {
//			Point O1(prev.x, object->GetPosition().y + height);
//			int prev_B = abs(prev.y - O1.y);
//			int length = prev_B * prev_curr / prev_O;
//			double OA = sqrt(length * length + prev_B * prev_B);
//			Point O(prev.y, prev.x + 2 * OA);
//			Point A(O1.y, O1.x + OA);
//			NormalizeVector norm(A, O, OA);
//			return norm;
//		}
//		else if (prev.x < object->GetPosition().x) {
//			Point O1(object->GetPosition().x, prev.y);
//			int prev_B = abs(prev.x - O1.x);
//			int length = prev_B * prev_curr / prev_O;
//			double OA = sqrt(length * length + prev_B * prev_B);
//			Point O(prev.x + 2 * OA, prev.y);
//			Point A(O1.x, O1.y + OA);
//			NormalizeVector norm(A, O, OA);
//			return norm;
//		}
//		else {
//			Point O1(object->GetPosition().x, prev.y);
//			int prev_B = abs(prev.x - O1.x);
//			int length = prev_B * prev_curr / prev_O;
//			double OA = sqrt(length * length + prev_B * prev_B);
//			Point O(prev.x - 2 * OA, prev.y + 2 * OA);
//			Point A(O1.x, O1.y + OA);
//			NormalizeVector norm(O, A, OA);
//			return norm;
//		}
//	}
//
//
//private:
//	int width;
//	int height;
//	const Object* const object;
//};
//class Brick : public Object {
//public:
//	// you depend on folder location
//	Brick(int x, int y, int width, int height) : Object(width, height) {
//		o_position.x = x;
//		o_position.y = y;
//		std::filesystem::path tmp = std::filesystem::current_path();
//		o_path = tmp.string() + "\\data\\\\17-Breakout-Tiles.png";
//	}
//	void Update() {
//		SetPath();
//		DrawObject();
//		Destroy();
//	};
//	Colider* myColider = new Colider(o_width, o_height, this);
//	bool isBrick = true;
//private:
//
//};
//class Platform : public Object {
//public:
//	// you depend on folder location
//	Platform(int x, int y, int s, int width, int height) : Object(width, height) {
//		o_position.x = x;
//		o_position.y = y;
//		step = s;
//		std::filesystem::path tmp = std::filesystem::current_path();
//		o_path = tmp.string() + "\\data\\\\17-Breakout-Tiles.png";
//	}
//	void MovePlatform(FRKey k) {
//		if (k == FRKey::RIGHT) {
//			o_position.x += step; // magic number
//		}
//		if (k == FRKey::LEFT) {
//			o_position.x -= step;
//		}
//	}
//	void Collision() {
//		if (o_position.x < 0) {
//			o_position.x = 0;
//		}
//		if (o_position.x > 700) {
//			o_position.x = 700;
//		}
//	}
//
//	void Destroy() {
//		destroySprite(texture);
//	};
//	void Update() {
//		SetPath(); // you depend on folder location
//		Collision();
//		DrawObject();
//		Destroy();
//	};
//
//	Colider myColider = Colider(o_width, o_height, this); // You already have width, height. Use it here
//private:
//	int step;
//};

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
		platform.MovePlatform(k);
	}

	virtual bool Tick() {
		platform.Update();
		Point prev = ball.GetPosition();
		static Point previousPosition = ball.GetPosition();
		ball.Update();
		if (platform.myColider.isColide(ball.GetPosition()))
		{
			ball.SetPosition(prev);
			// Plese make it not ChangeDirection but ChangeDirection. It is a common practice that vector and speed determince velocity
			ball.ChangeDirection(platform.myColider.Colide(ball.GetPosition(), prev).xV, platform.myColider.Colide(ball.GetPosition(), prev).yV);
		}
		return false;
	}

	virtual void onMouseMove(int x, int y, int xrelative, int yrelative) {
		if (ball.getIdle()) {
			if (x >= 400) {
				ball.SetVelocity(2, -2);
			}
			else {
				ball.SetVelocity(-2, -2);
			}
			ball.setIdle(false);
		}
	}

	virtual void onMouseButtonClick(FRMouseButton button, bool isReleased) {
		if (button == FRMouseButton::LEFT && isReleased) {
			ball.setIdle(isReleased);
		}
	}



	virtual void onKeyReleased(FRKey k) {


	}

	virtual const char* GetTitle() override
	{
		return "Arcanoid";
	}
private:
	Platform platform = Platform(350, 550, 50, 100, 50);
	Ball ball = Ball(360, 530, 20, 20);
};


int main(int argc, char* argv[])
{
	return run(new MyFramework);
}