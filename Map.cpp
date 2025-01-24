#include "Map.h"

Walls::Walls(int x, int y, int sx, int sy) : x(x), y(y), sizex(sx), sizey(sy) {
    wall_rect.setSize(Vector2f(sizex, sizey));
    wall_rect.setPosition(Vector2f(x, y));
    wall_rect.setFillColor(Color::White);
    if (!wall_t.loadFromFile("Assets/Map/Wall.png")) {
        return;
    }
    wall_rect.setTexture(&wall_t);
}

void Walls::draw(RenderWindow& window) {
    window.draw(wall_rect);
}

Floor::Floor(int x, int y, int sx, int sy) : x(x), y(y), sizex(sx), sizey(sy) {
    floor_rect.setSize(Vector2f(sizex, sizey));
    floor_rect.setPosition(Vector2f(x, y));
    floor_rect.setFillColor(Color::White);
    if (!floor_t.loadFromFile("Assets/Map/Floor.png")) {
        return;
    }
    floor_rect.setTexture(&floor_t);
}

void Floor::draw(RenderWindow& window) {
    window.draw(floor_rect);
}

Door::Door(int x, int y, int sx, int sy) : x(x), y(y), sizex(sx), sizey(sy) {
    door_rect.setSize(Vector2f(sizex, sizey));
    door_rect.setPosition(Vector2f(x, y));
    door_rect.setFillColor(Color::White);
    if (!door_t.loadFromFile("Assets/Map/ClosedDoor.png")) {
        return;
    }
    door_rect.setTexture(&door_t);
}

void Door::draw(RenderWindow& window) {
    window.draw(door_rect);
}

void Door::opendoor() {
    if (!door_t.loadFromFile("Assets/Map/OpenDoor.png")) {
        return;
    }
    door_rect.setTexture(&door_t);
}

Map::Map() {
    mapfile.open("Assets/Map/Map1.txt");
    string line;
    int y = 0;
    while (getline(mapfile, line)) {
        for (int i = 0; i < line.size(); i++) {
            if (line[i] == '#') {
                Walls* wall = new Walls(i * 50, y * 50, 50, 50);
                walls.push_back(wall);
            }
            else if (line[i] == '-') {
                Door* door = new Door(i * 50, y * 50, 50, 50);
                doors.push_back(door);
            }
            else {
                Floor* floorTile = new Floor(i * 50, y * 50, 50, 50);
                floors.push_back(floorTile);
            }
        }
        y++;
    }
}

void Map::draw(RenderWindow& window) {
    for (auto& wall : walls) {
        wall->draw(window);
    }
    for (auto& floor : floors) {
        floor->draw(window);
    }
    for (auto& door : doors) {
        door->draw(window);
    }
}
