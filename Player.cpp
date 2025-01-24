#include "Player.h"

Player::Player(int startX, int startY, float startSpeed)
    : posX(startX), posY(startY), speed(startSpeed), speedBoosted(false) {
    
    playerShape.setSize(Vector2f(25.f, 25.f));
    playerShape.setFillColor(sf::Color::Blue);    
    playerShape.setPosition(static_cast<float>(posX), static_cast<float>(posY));
}

float Player::getSpeed() const {
    return speed;
}

void Player::setSpeed(float newSpeed) {
    speed = newSpeed;
}

void Player::setTempSpeedClock(sf::Clock& clock) {
    tempSpeedClock = clock;  
}

sf::Clock& Player::getTempSpeedClock() {
    return tempSpeedClock;
}

void Player::setIsSpeedBoosted(bool boosted) {
    speedBoosted = boosted;
}

bool Player::isSpeedBoosted() const {
    return speedBoosted;
}


void Player::handleinput() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        posX -= speed;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        posX += speed;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        posY -= speed;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        posY += speed;
    }

    playerShape.setPosition(static_cast<float>(posX), static_cast<float>(posY));

}

void Player::draw(RenderWindow& window) {
    window.draw(playerShape);
}
Vector2f Player::getPosition() const {
    return sf::Vector2f(static_cast<float>(posX), static_cast<float>(posY));
}

FloatRect Player::getGlobalBounds() const {
    return playerShape.getGlobalBounds();
}

bool Player::checkCollision(const Walls& wall) const {
    return getGlobalBounds().intersects(wall.wall_rect.getGlobalBounds());
}

bool Player::checkCollision(const Door& door) const {
    return getGlobalBounds().intersects(door.door_rect.getGlobalBounds());
}

void Player::update(float deltaTime, const std::vector<Walls>& walls, const std::vector<Door>& doors) {
    if (speedBoosted && tempSpeedClock.getElapsedTime().asSeconds() > 5.0f) {
        setSpeed(getSpeed() / 1.5f);
        speedBoosted = false;
        std::cout << "Effet de vitesse terminé, retour à la vitesse normale." << std::endl;
    }

    Vector2f newPosition = this->getPosition();

    if (checkCollisionWithWalls(walls)) {
        std::cout << "Collision avec un mur, le joueur ne peut pas se déplacer." << std::endl;
    }

    if (checkCollisionWithDoors(doors)) {
        std::cout << "Collision avec une porte, le joueur ne peut pas se déplacer." << std::endl;
    }
}

bool Player::checkCollisionWithWalls(const std::vector<Walls>& walls) const {
    for (const Walls& wall : walls) {
        if (checkCollision(wall)) {
            return true; 
        }
    }
    return false;
}

bool Player::checkCollisionWithDoors(const std::vector<Door>& doors) const {
    for (const Door& door : doors) {
        if (checkCollision(door)) {
            return true;
        }
    }
    return false;
}

bool Player::checkCollision(const Walls& wall) const {
    return getGlobalBounds().intersects(wall.wall_rect.getGlobalBounds());
}

bool Player::checkCollision(const Door& door) const {
    return getGlobalBounds().intersects(door.door_rect.getGlobalBounds());
}