#include "Object.h"
#include "Colder.h"
#include <filesystem>

class Platform : public Object {
public:
	// you depend on folder location
	Platform(int x, int y, int s, int width, int height);
	void MovePlatform(FRKey k);
	void Collision();
	void Destroy();
	void Update();
	Colider myColider = Colider(o_width, o_height, this); // You already have width, height. Use it here
private:
	int step;
};