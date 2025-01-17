#include "Game.h"

void Game::gameInput() {
    Event event;
    manager.allPlayers[0]->handleinput();

    while (window.pollEvent(event)) {
        if (event.type == Event::Closed) {
            window.close();
        }
    }
}

void Game::gameDraw() {
    window.clear();

    manager.allPlayers[0]->draw(window);

    window.display();
}

void Game::gameLoop() {
    manager.createPlayer();
    while (window.isOpen()) {
        gameInput();
        gameDraw();
    }
}
