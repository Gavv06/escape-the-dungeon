#include "Key.h"

Key::Key(int startX, int startY, int keynumber)
    : posX(startX), posY(startY), knum(keynumber) {
    keyShape.setSize(Vector2f(15.f, 15.f));
    keyShape.setFillColor(Color::Yellow);
    keyShape.setPosition(static_cast<float>(posX), static_cast<float>(posY));
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

        std::cout << "une clé a ete trouvé!" << std::endl;
        keynumber = keynumber + 1;
        cout << "vous avez: " << keynumber << "cle" << endl;
        used = true;
        
    }
}
