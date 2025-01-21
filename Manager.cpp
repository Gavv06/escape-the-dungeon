#include "Manager.h"

float Manager::initializeRandomGenerator(int nb1, int nb2) {
    return floor(nb1 + ((rand() / (float)RAND_MAX) * nb2));
}

Player* Manager::createPlayer() {
    Player* obj = new Player(640, 330, 1.0f);
    allPlayers.push_back(obj);
    return obj;
}

Chaser* Manager::createChaser() {
    Chaser* obj = new Chaser(150, 150, 0.8f );
    allChasers.push_back(obj);
    for (Player* player : allPlayers) {
        obj->hunt(*player); 
    }
    return obj;
}

Patrol* Manager::createPatrol() {
    Patrol* obj = new Patrol(700, 400, 1.5f);
    allPatrols.push_back(obj);
    return obj;
}

Potion* Manager::createPotion() {
    int x = initializeRandomGenerator(0, 960);
    int y = initializeRandomGenerator(0, 1280);;

    Potion* obj = new Potion(x, y);
    allPotions.push_back(obj);
    return obj;
}

Key* Manager::createKey() {
    int x = initializeRandomGenerator(0, 960);
    int y = initializeRandomGenerator(0, 1280);;

    Key* obj = new Key(x, y, 0);
    allKeys.push_back(obj);
    return obj;
}
