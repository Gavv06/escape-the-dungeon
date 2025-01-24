#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <vector>

#include "Walls.h"
#include "Door.h"
#include "Floor.h"

using namespace std;
using namespace sf;

class Map{  //: public Walls, public Floor, public Door {
public:
	ifstream mapfile;
	Texture wall_t;
	Texture floor_t;
	Texture door_t;
	vector<RectangleShape*> walls;
	vector<RectangleShape*> floors;
	vector<RectangleShape*> doors;

	Map();
	void draw(RenderWindow& window);




};

