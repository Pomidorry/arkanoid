#pragma once
#include "Object.h"
#include "Platform.h"
#include <vector>
#include <filesystem>

class PositiveBonus : public Object
{
public:
	PositiveBonus(int width, int height);
	void Update();
	void Move();
	void SetVelocity(int y);
	void CatchByPlatform(Platform& plat);
	void SetPosition(std::vector<Point> v);
	bool onStage;
	bool isCatched;
private:
	int yVelocity;
};
