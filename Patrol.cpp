#include "Patrol.h"
#include "Player.h"
#include <cmath>
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

Patrol::Patrol(int startX, int startY, float startSpeed)
    : posX(startX), posY(startY), speed(startSpeed), currentPointIndex(0) {

    patrolShape.setSize(Vector2f(25.f, 25.f));
    patrolShape.setFillColor(Color::Red);
    patrolShape.setPosition(static_cast<float>(posX), static_cast<float>(posY));

    path.push_back(Vector2f(100.f, 100.f));
    path.push_back(Vector2f(400.f, 100.f));
    path.push_back(Vector2f(400.f, 400.f));
    path.push_back(Vector2f(100.f, 400.f));
}

void Patrol::search() {
    Vector2f target = path[currentPointIndex];
    Vector2f currentPosition = patrolShape.getPosition();

    Vector2f direction = target - currentPosition;
    float distance = std::sqrt(direction.x * direction.x + direction.y * direction.y);

    if (distance < speed) {
        currentPointIndex = (currentPointIndex + 1) % path.size();
    }

    if (distance > 0) {
        direction /= distance;
    }

    patrolShape.move(direction * speed);
}

void Patrol::draw(RenderWindow& window) {
    window.draw(patrolShape);
}

sf::Vector2f Patrol::getPosition() const {
    return patrolShape.getPosition();
}


bool Patrol::checkCollisionWithPatrol(const Player& player) {
    sf::Vector2f patrolPos = this->getPosition();
    sf::Vector2f playerPos = player.getPosition();

    float distance = std::sqrt(std::pow(patrolPos.x - playerPos.x, 2) + std::pow(patrolPos.y - playerPos.y, 2));
    float collisionThreshold = 25.f;

    return distance < collisionThreshold;
}

FloatRect Patrol::getGlobalBounds() const {
    return patrolShape.getGlobalBounds();
}

bool Patrol::checkCollision(const Walls& wall) const {
    return getGlobalBounds().intersects(wall.wall_rect.getGlobalBounds());
}

bool Patrol::checkCollision(const Door& door) const {
    return getGlobalBounds().intersects(door.door_rect.getGlobalBounds());
}

bool Patrol::checkCollisionWithWalls(const std::vector<Walls>& walls) const {
    for (const Walls& wall : walls) {
        if (checkCollision(wall)) {
            return true; 
        }
    }
    return false; 
}

bool Patrol::checkCollisionWithDoors(const std::vector<Door>& doors) const {
    for (const Door& door : doors) {
        if (checkCollision(door)) {
            return true; 
        }
    }
    return false; 
}

void Patrol::update(float deltaTime, const std::vector<Walls>& walls, const std::vector<Door>& doors) {
    Vector2f movement = calculatePatrolMovement();
    Vector2f newPosition = this->position + movement * deltaTime;

    if (!checkCollisionWithWalls(walls) && !checkCollisionWithDoors(doors)) {
        this->position = newPosition;
    }
}

