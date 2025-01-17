#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;

class entity{
public:
	virtual void update(float deltaTime) = 0;
	virtual void draw(RenderWindow & window) = 0; 

};

