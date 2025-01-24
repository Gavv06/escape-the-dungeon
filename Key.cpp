#include "Key.h"

Key::Key(int startX, int startY, bool poss)
    : posX(startX), posY(startY), possessed(poss) {
    keyShape.setSize(Vector2f(20.f, 20.f));
    keyShape.setFillColor(Color::Yellow);
    keyShape.setPosition(static_cast<float>(posX), static_cast<float>(posY));

    if (!key_t.loadFromFile("(Assets/Item/Key.png")) {
        return;
    }
    keyShape.setTexture(&key_t);
}

void Key::update(float deltaTime) {
    "i've got the key to leave the door";
}

bool Key::isUsed() const {
    return used;
}

void Key::draw(RenderWindow& window) {
    window.draw(keyShape);
}

void Key::interact(Player& player) {
    FloatRect potionBounds = keyShape.getGlobalBounds();
    FloatRect playerBounds = player.getGlobalBounds();

    if (potionBounds.intersects(playerBounds)) {

        std::cout << "la clé a ete trouvé!" << std::endl;
        possessed = true;
        used = true;
        
    }
}
