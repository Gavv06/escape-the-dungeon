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
	void update(float deltaTime, const std::vector<Walls>& walls, const std::vector<Door>& doors) override;
	FloatRect getGlobalBounds() const;

	bool checkCollision(const Walls& wall) const;
	bool checkCollision(const Door& door) const;
	bool checkCollisionWithWalls(const std::vector<Walls>& walls) const;
	bool checkCollisionWithDoors(const std::vector<Door>& doors) const;


private:
	Clock tempSpeedClock;
	bool speedBoosted = false;
};
