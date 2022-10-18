#include "Object.h"
Object::Object(int width, int height) {
	o_width = width;
	o_height = height;
};
void Object::SetPath() {
	texture = createSprite(o_path.c_str());
};
void Object::DrawObject() {
	setSpriteSize(texture, o_width, o_height);
	drawSprite(texture, o_position.x, o_position.y);
};
void Object::Destroy() {
	destroySprite(texture);
};
Point Object::GetPosition() const {
	return o_position;
};
int Object::GetWidth() const {
	return o_width;
}
int Object::GetHeight() const {
	return o_height;
}