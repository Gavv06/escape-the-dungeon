#include "Potion.h"
#include <iostream>
#include <chrono>

Potion::Potion(int startX, int startY)
    : posX(startX), posY(startY) {
    potionShape.setSize(Vector2f(15.f, 15.f));
    potionShape.setFillColor(Color::Green);
    potionShape.setPosition(static_cast<float>(posX), static_cast<float>(posY));
}

bool Potion::isUsed() const {
    return used; 
}

void Potion::usepotion(Player& player) {
    if (!isUsed()) {  
        std::cout << "Potion utilisée ! Vitesse augmentée temporairement." << std::endl;

        float originalSpeed = player.getSpeed();
        player.setSpeed(originalSpeed * 1.5f);

        boostEndTime = std::chrono::high_resolution_clock::now() + std::chrono::seconds(5);

        speedBoostActive = true;
        used = true;
    }
}

void Potion::updateSpeedBoost() {
    if (speedBoostActive && std::chrono::high_resolution_clock::now() >= boostEndTime) {
        speedBoostActive = false;
        std::cout << "Vitesse du joueur rétablie." << std::endl;
    }
}

void Potion::update(float deltaTime) {
    updateSpeedBoost();
}

void Potion::draw(RenderWindow& window) {
    window.draw(potionShape);
}

void Potion::interact(Player& player) {
    FloatRect potionBounds = potionShape.getGlobalBounds();
    FloatRect playerBounds = player.getGlobalBounds();

    if (potionBounds.intersects(playerBounds)) {
        std::cout << "La potion a été récupérée !" << std::endl;
        usepotion(player);
    }
}
