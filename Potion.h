#pragma once
#include "objets.h"
#include "Interactable.h"
#include "Player.h"
#include <chrono>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class Potion : public Objets, public Interactable {
private:
    bool used = false;
    bool speedBoostActive = false;
    chrono::time_point<chrono::high_resolution_clock> boostEndTime;

public:
    int posX, posY;
    RectangleShape potionShape;
    Texture potion_t;

    Potion(int startX, int startY);

    bool isUsed() const;
    void usepotion(Player& player);
    void updateSpeedBoost();
    
    void draw(RenderWindow& window) override;
    void update(float deltaTime) override;
    void interact(Player& player) override;
};
