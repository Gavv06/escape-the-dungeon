#include "Chaser.h"
#include <cmath>
#include <SFML/Graphics.hpp>

using namespace sf;

Chaser::Chaser(int startX, int startY, float startSpeed)
    : posX(startX), posY(startY), speed(startSpeed) {

    chaserShape.setSize(Vector2f(25.f, 25.f));
    chaserShape.setFillColor(Color::Red);
    chaserShape.setPosition(static_cast<float>(posX), static_cast<float>(posY));
}

void Chaser::hunt(const Player& player) {
    Vector2f playerPos = player.getPosition();
    Vector2f chaserPos = chaserShape.getPosition();

    Vector2f direction = playerPos - chaserPos;
    float distance = sqrt(direction.x * direction.x + direction.y * direction.y);

    if (distance > 0) {
        direction /= distance;
        chaserPos += direction * speed;
        chaserShape.setPosition(chaserPos);
    }
}

Vector2f Chaser::getPosition() const {
    return chaserShape.getPosition();
}

bool Chaser::checkCollisionWithChaser(const Player& player) {
    Vector2f chaserPos = getPosition(); 
    Vector2f playerPos = player.getPosition();

    float distance = std::sqrt(std::pow(chaserPos.x - playerPos.x, 2) + std::pow(chaserPos.y - playerPos.y, 2));
    float collisionThreshold = 25.f; 

    return distance < collisionThreshold;
}





void Chaser::update(float deltaTime) {
    std::cout << "Chaser is hunting..." << std::endl;
}

void Chaser::draw(RenderWindow& window) {
    window.draw(chaserShape);
}
