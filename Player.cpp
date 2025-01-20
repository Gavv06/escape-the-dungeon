#include "Player.h"

Player::Player(int startX, int startY, float startSpeed)
    : posX(startX), posY(startY), speed(startSpeed) {
    
    playerShape.setSize(Vector2f(25.f, 25.f));
    playerShape.setFillColor(sf::Color::Blue);    
    playerShape.setPosition(static_cast<float>(posX), static_cast<float>(posY));
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


//void Player::checkCollisionWithChaser(const Chaser& chaser, RenderWindow* window) {
//   
//    if (playerShape.getGlobalBounds().intersects(chaser.chaserShape.getGlobalBounds())) {
//        std::cout << "Collision détectée avec un chaser!" << std::endl;
//        if (window) {
//            window->close();  
//        }
//    }
//}

void Player::update(float deltaTime) {
    cout << "A";
}

void Player::draw(RenderWindow& window) {
    window.draw(playerShape);
}
sf::Vector2f Player::getPosition() const {
    return sf::Vector2f(static_cast<float>(posX), static_cast<float>(posY));
}


