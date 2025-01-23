#pragma once
#include <SFML/Graphics.hpp>
#include "entity.h"
using namespace sf;

class Door: public entity{
public:
	int x, y;
	int sizex, sizey;
	Texture door_t;
	RectangleShape door_rect;

	Door(int x, int y, int sx, int sy);
	void draw(RenderWindow& window) override;
};


