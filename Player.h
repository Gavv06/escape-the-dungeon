#pragma once
#include "entity.h"

class Player: public entity {
public:
	int posX, posY;
	float speed;
	RectangleShape playerShape;
	Player(int startX, int startY, float startSpeed);

	float getSpeed() const;      
	void setSpeed(float newSpeed);

	void setTempSpeedClock(sf::Clock& clock);
	sf::Clock& getTempSpeedClock();
	void setIsSpeedBoosted(bool boosted);
	bool isSpeedBoosted() const;

	Vector2f getPosition() const;
	void handleinput();
	void draw(RenderWindow& window) override;
	void update(float deltaTime) override;
	FloatRect getGlobalBounds() const;

private:
	Clock tempSpeedClock;
	bool speedBoosted = false;
};
