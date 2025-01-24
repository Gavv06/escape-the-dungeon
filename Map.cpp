#include "Map.h"

Map::Map() {
	mapfile.open("Assets/Map/Map1.txt");
	string line;
	int y = 0;
	while (getline(mapfile, line)) {
		for (int i = 0; i < line.size(); i++) {
			if (line[i] == '#') {
				RectangleShape* wall = new RectangleShape(Vector2f(30, 30));
				wall->setPosition(i * 30, y * 30);
				walls.push_back(wall);
			}

			else if (line[i] == '-') {
				RectangleShape* door = new RectangleShape(Vector2f(30, 30));
				door->setPosition(i * 50, y * 50); 
				doors.push_back(door);
			}

			else {
				RectangleShape* floorTile = new RectangleShape(Vector2f(30, 30));
				floorTile->setPosition(i * 30, y * 30); 
				floors.push_back(floorTile);
			}

		}
		y++;
		cout << endl;;

	}
}

void Map::draw(RenderWindow& window) {
	for (auto& wall : walls) {
		window.draw(*wall);
	}
	for (auto& floor : floors) {
		window.draw(*floor);
	}
	for (auto& door : doors) {
		window.draw(*door);
	}
}