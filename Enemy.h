#pragma once
#include "entity.h"


class Enemy: public entity
{
public:
	void update(float deltaTime, const std::vector<Walls>& walls, const std::vector<Door>& doors) = 0;
	void draw(sf::RenderWindow& window) override = 0;

};

