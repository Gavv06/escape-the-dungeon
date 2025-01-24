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
    int posX, posY;
    bool possessed;
    
    RectangleShape keyShape;
    Texture key_t;

    Key(int startX, int startY, bool poss);
    bool isUsed() const;
    void draw(RenderWindow& window) override;
    void update(float deltaTime) override;
    void interact(Player& player) override;
};

