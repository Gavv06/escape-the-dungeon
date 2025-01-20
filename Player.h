#pragma once
#include "entity.h"

class Player: public entity {
public:
	int posX, posY;
	float speed;
	RectangleShape playerShape;
	Player(int startX, int startY, float startSpeed);


	Vector2f getPosition() const;
	void handleinput();
	void draw(RenderWindow& window) override;
	void update(float deltaTime) override;
	
};

