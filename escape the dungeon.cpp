#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.h"
using namespace std;
using namespace sf;

int main() {
    RenderWindow window(sf::VideoMode(1280, 960), "escape the dungeon");
    window.setFramerateLimit(60);
    Image icon; icon.loadFromFile("Assets/Icon/chabrier.png");
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());


    Game game(window);
    game.gameLoop();
    return 0;
}

