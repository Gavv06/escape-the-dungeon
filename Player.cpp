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


void Player::update(float deltaTime) {
    if (speedBoosted && tempSpeedClock.getElapsedTime().asSeconds() > 5.0f) {
        setSpeed(getSpeed() / 1.5f);
        speedBoosted = false;
        cout << "Effet de vitesse terminé, retour à la vitesse normale." << endl;
    };
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

