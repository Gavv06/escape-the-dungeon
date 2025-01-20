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

    for (Chaser* chaser : manager.allChasers) {
        chaser->draw(window);
    }

    for (Patrol* patrol : manager.allPatrols) {
        patrol->draw(window);
    }

    window.display();
}

void Game::gameLoop() {
    manager.createPlayer();
    manager.createChaser();
    manager.createPatrol();

    while (window.isOpen()) {
        gameInput();

        for (Chaser* chaser : manager.allChasers) {
            for (Player* player : manager.allPlayers) {
                chaser->hunt(*player);

                if (chaser->checkCollisionWithChaser(*player)) {
                    std::cout << "Collision détectée entre Chaser et Player !" << std::endl;
                    window.close();
                    
                }
            }
        }

        for (Patrol* patrol : manager.allPatrols) {
            for (Player* player : manager.allPlayers) {
                patrol->search();

                if (patrol->checkCollisionWithPatrol(*player)) {
                    std::cout << "Collision détectée entre Patrol et Player !" << std::endl;
                    window.close();
                }
            }
        }

        gameDraw();
    }
}

