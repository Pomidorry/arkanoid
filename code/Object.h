#pragma once
#include "Framework.h"
#include "Stucts.h"
#include <string>

class Object {
public:
	Object(int width, int height);
	void SetPath();
	void DrawObject();
	void Destroy();
	Point GetPosition() const;
	int GetWidth() const;
	int GetHeight() const;
	virtual void Update() = 0;
protected:
	Point o_position;
	int o_width;
	int o_height;
	Sprite* texture;
	std::string o_path;
};