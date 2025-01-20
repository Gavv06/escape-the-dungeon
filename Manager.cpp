#include "Manager.h"

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
