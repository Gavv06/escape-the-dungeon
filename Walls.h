#pragma once
#include <SFML/Graphics.hpp>
#include "entity.h"
using namespace sf;

class Walls: public entity{
public:
	int x, y;
	int sizex, sizey;
	Texture wall_t;
	RectangleShape wall_rect;

	Walls(int x, int y, int sx, int sy);
	void draw(RenderWindow& window) override;
};


