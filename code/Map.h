#pragma once
#include "TNT.h"
#include "Brick.h"
#include "Ball.h"
#include <string>

class Map {
public:
	Map() ;
	void UpdateMap();
	void BallInteractWithBrick( Ball& ball, Point previousPosition);
	void CreateMap();
	inline static int counter = 0;
	std::vector<Point> vectorOfFreePositions;
private:
	std::vector<Brick> map;
	std::vector<TNT> tnt;
};