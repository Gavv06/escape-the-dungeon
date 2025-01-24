#pragma once
#include "Enemy.h"
#include "Player.h"
#include <SFML/Graphics.hpp>

using namespace sf;

class Chaser : public Enemy {
public:
    int posX, posY;
    float speed;
    RectangleShape chaserShape;
    Vector2f position;

    Chaser(int startX, int startY, float startSpeed);

    void hunt(const Player& player);

    void draw(RenderWindow& window) override;

    void update(float deltaTime, const std::vector<Walls>& walls, const std::vector<Door>& doors) override;

    bool checkCollisionWithChaser(const Player& player);

    sf::Vector2f getPosition() const;
    FloatRect getGlobalBounds() const;
    Vector2f calculateMovementTowardsPlayer();
    bool checkCollision(const Walls& wall) const;
    bool checkCollision(const Door& door) const;
    bool checkCollisionWithWalls(const std::vector<Walls>& walls) const;
    bool checkCollisionWithDoors(const std::vector<Door>& doors) const;
    Vector2f getPosition() const;
};
