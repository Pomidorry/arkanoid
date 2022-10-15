#include "Colder.h"
Colider::Colider(int w, int h, const Object* object) : object(object) {
	width = w;
	height = h;
};
bool Colider::isColide(Point p) {
	int collisionXNegative = object->GetPosition().x;
	int collisionXPositive = object->GetPosition().x + width;
	int collisionYNegative = object->GetPosition().y;
	int collisionYPositive = object->GetPosition().y + height;
	if (p.x >= collisionXNegative
		&& p.x <= collisionXPositive
		&& p.y >= collisionYNegative
		&& p.y <= collisionYPositive) {
		return 1;
	}
	else {
		return 0;
	}
};
NormalizeVector Colider::Colide(Point curr, Point prev) {
	int prev_O = abs(prev.x - curr.x);
	int curr_O = abs(prev.y - curr.y);
	double prev_curr = sqrt(prev_O * prev_O + curr_O * curr_O);

	if (prev.y < object->GetPosition().y) {
		Point O1(prev.x, object->GetPosition().y);
		int prev_B = abs(prev.y - O1.y);
		int length = prev_B * prev_curr / prev_O;
		double OA = sqrt(length * length + prev_B * prev_B);
		Point O(prev.x + 2 * OA, prev.y);
		Point A(O1.x + OA, O1.y);
		NormalizeVector norm(O, A, OA);
		return norm;
	}
	else if (prev.y >= object->GetPosition().y + height) {
		Point O1(prev.x, object->GetPosition().y + height);
		int prev_B = abs(prev.y - O1.y);
		int length = prev_B * prev_curr / prev_O;
		double OA = sqrt(length * length + prev_B * prev_B);
		Point O(prev.y, prev.x + 2 * OA);
		Point A(O1.y, O1.x + OA);
		NormalizeVector norm(A, O, OA);
		return norm;
	}
	else if (prev.x < object->GetPosition().x) {
		Point O1(object->GetPosition().x, prev.y);
		int prev_B = abs(prev.x - O1.x);
		int length = prev_B * prev_curr / prev_O;
		double OA = sqrt(length * length + prev_B * prev_B);
		Point O(prev.x + 2 * OA, prev.y);
		Point A(O1.x, O1.y + OA);
		NormalizeVector norm(A, O, OA);
		return norm;
	}
	else {
		Point O1(object->GetPosition().x, prev.y);
		int prev_B = abs(prev.x - O1.x);
		int length = prev_B * prev_curr / prev_O;
		double OA = sqrt(length * length + prev_B * prev_B);
		Point O(prev.x - 2 * OA, prev.y + 2 * OA);
		Point A(O1.x, O1.y + OA);
		NormalizeVector norm(O, A, OA);
		return norm;
	}
}