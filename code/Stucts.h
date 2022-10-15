#pragma once
struct Point {
	Point() {};
	Point(int x1, int y1) {
		x = x1;
		y = y1;
	};
	double x;
	double y;
};

struct NormalizeVector {
	double xV;
	double yV;
	NormalizeVector(Point B, Point A, int l) {
		xV = (B.x - A.x) / l;
		yV = (B.y - A.y) / l;
	}
};