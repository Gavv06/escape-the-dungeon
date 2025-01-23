#pragma once
#include <SFML/Graphics.hpp>
#include "entity.h"
using namespace sf;

class Floor: public entity{
public:
	int x, y;
	int sizex, sizey;
	Texture floor_t;
	RectangleShape floor_rect;

	Floor(int x, int y, int sx, int sy);
	void draw(RenderWindow& window) override;
};

