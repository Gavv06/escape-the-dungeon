#include "Map.h"

Map::Map() {
	mapfile.open("Assets/Map/Map1.txt");
	string line;
	int y = 0;

	while (getline(mapfile, line)) {
		for (int i = 0; i < line.size(); i++) {
			if (line[i] == '#') {
				walls.push_back(new RectangleShape(Vector2f(10, 10)));
			}

			else if (line[i] == '-') {
				door.push_back(new RectangleShape(Vector2f(10, 10)));
			}

			else {
				floor.push_back(new RectangleShape(Vector2f(10, 10)));
			}
		    
		}
		y++;
		cout << endl;;

	}
}

void Map::draw(RenderWindow& window) {
	for (auto& wall : walls) {
		wall->draw(window);
	}
	for (auto& floor : floor) {
		floor->draw(window);
	}
	for (auto& door : door) {
		door->draw(window);
	}
}