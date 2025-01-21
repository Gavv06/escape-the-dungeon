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

    for (Potion* potion : manager.allPotions) { 
        potion->draw(window);
    }

    for (Key* key : manager.allKeys) {
        key->draw(window);
    }

    window.display();
}

void Game::gameLoop() {
    manager.createPlayer();
    manager.createChaser();
    manager.createPatrol();
    manager.createPotion();
    manager.createKey();

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

        for (Potion* potion : manager.allPotions) {
            for (Player* player : manager.allPlayers) {
                potion->interact(*player); 

                
                if (potion->isUsed()) {
                    cout << "Potion utilisée par le joueur !" << std::endl;
                    manager.allPotions.erase(remove(manager.allPotions.begin(), manager.allPotions.end(), potion), manager.allPotions.end());
                    break;
                }
            }
        }

        for (Key* key : manager.allKeys) {
            for (Player* player : manager.allPlayers) {
                key->interact(*player);


                if (key->isUsed()) {
                    cout << "nouvelle clé !" << std::endl;
                    manager.allKeys.erase(remove(manager.allKeys.begin(), manager.allKeys.end(), key), manager.allKeys.end());
                    break;
                }
            }
        }

        for (Player* player : manager.allPlayers) {
            player->update(0.016f); 
        }

        gameDraw();
    }
}
