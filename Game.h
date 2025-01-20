#pragma once
#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "Manager.h"

class Game {
public:
    Game(RenderWindow& win) : window(win) {}
    void gameLoop();
    void gameInput();
    void gameDraw();

    RenderWindow& window;
    Manager manager;
};

#endif
