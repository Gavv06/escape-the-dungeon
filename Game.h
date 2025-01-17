#pragma once
#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "Manager.h"

class Game {
public:
    Game(sf::RenderWindow& win) : window(win) {}
    void gameLoop();
    void gameInput();
    void gameDraw();

    sf::RenderWindow& window;
    Manager manager;
};

#endif
