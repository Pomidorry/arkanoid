#include "Map.h"
#include <iostream>
Map::Map() {
}
void Map::CreateMap() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 4; j++) {
			map.push_back((Brick(i * 100, 50 * j, 100, 50)));
		}
	}
	tnt.push_back(TNT(0, 150, 100, 50));
	tnt.push_back(TNT(600, 150, 100, 50));

}
void Map::BallInteractWithBrick(Ball& ball, Point previousPosition) {
	
		for (int i = 0; i < 32; i++) {
			for (int j = 0; j < 2; j++) {
				if (tnt[j].GetPosition().x <= ball.GetPosition().x
					&& tnt[j].GetPosition().x + tnt[j].GetWidth() >= ball.GetPosition().x
					&& ball.GetPosition().y <= tnt[j].GetHeight() + tnt[j].GetPosition().y
					&& ball.GetPosition().y >= tnt[j].GetPosition().y
					&& tnt[j].onStage == true
					) {
					int index =( (tnt[j].GetPosition().y) / tnt[j].GetHeight()+1)
						* (tnt[j].GetPosition().x / tnt[j].GetWidth()+1)
						-(4-((tnt[j].GetPosition().y)) / tnt[j].GetHeight());
					tnt[j].onStage = false;
					map[index].onStage = false;
					counter++;
					vectorOfFreePositions.push_back(map[index].GetPosition());
					if (index % 4 != 0 && index - 1 >= 0) {
						map[index - 1].onStage = false;
						vectorOfFreePositions.push_back(map[index-1].GetPosition());
						counter++;
					}
					if (index + 4 < 32) {
						map[index + 4].onStage = false;
						vectorOfFreePositions.push_back(map[index+4].GetPosition());
						counter++;
					}
					if ((index + 1) % 4 != 0 && index + 1 < 32) {
						map[index + 1].onStage = false;
						vectorOfFreePositions.push_back(map[index+1].GetPosition());
						counter++;
					}
					if (index - 4 >= 0) {
						map[index - 4].onStage = false;
						vectorOfFreePositions.push_back(map[index-4].GetPosition());
						counter++;
					}
					ball.SetPosition(previousPosition);
					ball.ChangeDirection(1, -1);
				}
				if (map[i].GetPosition().x <= ball.GetPosition().x
					&& map[i].GetPosition().x + map[i].GetWidth() >= ball.GetPosition().x
					&& ball.GetPosition().y <= map[i].GetHeight() + map[i].GetPosition().y
					&& ball.GetPosition().y >= map[i].GetPosition().y
					&& map[i].onStage == true
					) {
					ball.SetPosition(previousPosition);
					ball.ChangeDirection(1, -1);
					map[i].onStage = false;
					vectorOfFreePositions.push_back(map[i].GetPosition());
					counter++;
				}
			}
		}
	
};
void Map::UpdateMap() {
	for (int i = 0; i < 32; i++) {
			map[i].Update();
	}
	for (int i = 0; i < 2; i++) {
		tnt[i].Update();
	}
}