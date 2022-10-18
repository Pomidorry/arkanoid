#pragma once
#include "Object.h"
#include "Platform.h"
#include <vector>
#include <filesystem>

class NegativeBonus : public Object
{
public:
	NegativeBonus( int width, int height);
	void Update();
	void Move();
	void SetVelocity(int y);
	void CatchByPlatform(Platform& plat);
	Point Effect(std::vector<Point> v);
	void SetPosition(std::vector<Point> v);
	bool onStage;
	bool isCatched;
private:
	int yVelocity;
};

