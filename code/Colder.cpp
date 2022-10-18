#include "Colder.h"
Colider::Colider( const Object* object) : object(object) {
	
};
bool Colider::isColide(Point p) {
	int collisionXNegative = object->GetPosition().x;
	int collisionXPositive = object->GetPosition().x + object->GetWidth();
	int collisionYNegative = object->GetPosition().y;
	int collisionYPositive = object->GetPosition().y + object->GetHeight();
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
