#pragma once
#include "objets.h"
#include "Interactable.h"
#include "Player.h"
using namespace std;
using namespace sf;

class Key: public Objets, public Interactable {
private:
    bool used = false;
public:
    int posX, posY, knum, keynumber;
    
    RectangleShape keyShape;

    Key(int startX, int startY, int keynumber);
    bool isUsed() const;
    void draw(RenderWindow& window) override;
    void update(float deltaTime) override;
    void interact(Player& player) override;
};

