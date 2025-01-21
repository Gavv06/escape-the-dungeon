#pragma once
#include "entity.h"
class Objets: public entity{

public:
	void update(float deltaTime) override = 0;
	void draw(sf::RenderWindow& window) override = 0;
};

