#ifndef PATROL_H
#define PATROL_H
#include "Enemy.h"
#include "Player.h"
#include <SFML/Graphics.hpp>
#include <vector>

class Patrol : public Enemy {
public:
    sf::RectangleShape patrolShape;
    float speed;
    int posX, posY;
    int currentPointIndex;
    std::vector<sf::Vector2f> path;

    Patrol(int startX, int startY, float startSpeed);
    void search();
    void update(float deltaTime) override;
    void draw(sf::RenderWindow& window) override;
    bool checkCollisionWithPatrol(const Player& player);
    sf::Vector2f getPosition() const;
};

#endif
