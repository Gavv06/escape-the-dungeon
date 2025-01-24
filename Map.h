#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
using namespace sf;

class Walls {
public:
    int x, y;
    int sizex, sizey;
    Texture wall_t;
    RectangleShape wall_rect;

    Walls(int x, int y, int sx, int sy);
    void draw(RenderWindow& window);
};

class Floor {
public:
    int x, y;
    int sizex, sizey;
    Texture floor_t;
    RectangleShape floor_rect;

    Floor(int x, int y, int sx, int sy);
    void draw(RenderWindow& window);
};

class Door {
public:
    int x, y;
    int sizex, sizey;
    Texture door_t;
    RectangleShape door_rect;

    Door(int x, int y, int sx, int sy);
    void draw(RenderWindow& window);
    void opendoor();
};

class Map {
public:
    ifstream mapfile;
    vector<Walls*> walls;
    vector<Floor*> floors;
    vector<Door*> doors;

    Map();
    void draw(RenderWindow& window);
};
