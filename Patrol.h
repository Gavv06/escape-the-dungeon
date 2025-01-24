#ifndef PATROL_H
#define PATROL_H
#include "Enemy.h"
#include "Player.h"
#include <SFML/Graphics.hpp>
#include <vector>

class Patrol : public Enemy {
public:
    sf::RectangleShape patrolShape;
    Vector2f position;
    float speed;
    int posX, posY;
    int currentPointIndex;
    std::vector<sf::Vector2f> path;

    Patrol(int startX, int startY, float startSpeed);
    void search();
    void update(float deltaTime, const std::vector<Walls>& walls, const std::vector<Door>& doors) override;
    Vector2f calculatePatrolMovement(); 
    bool checkCollision(const Walls& wall) const;
    bool checkCollision(const Door& door) const;
    bool checkCollisionWithWalls(const std::vector<Walls>& walls) const;
    bool checkCollisionWithDoors(const std::vector<Door>& doors) const;

    void draw(sf::RenderWindow& window) override;
    bool checkCollisionWithPatrol(const Player& player);
    sf::Vector2f getPosition() const;

    FloatRect getGlobalBounds() const;
  
};

#endif
