#pragma once
#include "Object.h"
#include <filesystem>

class Ball : public Object {
public:
	// you depend on folder location
	Ball(int x, int y, int width, int height);
	void Update() override;
	void setIdle(bool on);
	bool getIdle() const;
	void SetVelocity(int x, int y);
	void ChangeDirection(int dx, int dy);
	void SetPosition(Point p);
	void Move();
	bool isBrick = true;
	void Death();
	inline static int ballCounter = 1;
private:
	double xVelocity = 0;
	double yVelocity = 0;
	bool isIdle = false;
};