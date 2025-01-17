#include "Manager.h"

Player* Manager::createPlayer() {
    Player* obj = new Player(640, 330, 1.0f);
    allPlayers.push_back(obj);
    return obj;
}


