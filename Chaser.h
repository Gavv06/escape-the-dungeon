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

    Chaser(int startX, int startY, float startSpeed);

    void hunt(const Player& player);

    void draw(RenderWindow& window) override;

    void update(float deltaTime) override;

    bool checkCollisionWithChaser(const Player& player);

    sf::Vector2f getPosition() const;
};
