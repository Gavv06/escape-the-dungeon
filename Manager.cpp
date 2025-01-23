#include "Manager.h"

void Manager::setSeed(unsigned int seed) {
    srand(seed);
}

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
    int x;
    int y;
    int marginX = 50;
    int marginY = 50;
    int countx = 5;
    for (int i = 0; i < countx; ++i) {
        x = initializeRandomGenerator(marginX, 1280 - marginX);
        cout << "Random Value " << (i + 1) << ": " << x << endl;
        
        
    }
    int county = 5;
    for (int i = 0; i < county; ++i) {
        y = initializeRandomGenerator(marginY, 960-marginY);
        cout << "Random Value " << (i + 1) << ": " << y << endl;
    }

    Potion* obj = new Potion(x, y);
    allPotions.push_back(obj);
    return obj;
}

Key* Manager::createKey() {
    int marginX = 50;
    int marginY = 50;
    int x = initializeRandomGenerator(marginX, 1280 - marginX);
    cout << x << endl;
    int y = initializeRandomGenerator(marginY, 960 - marginY);
    cout << y << endl;

   Key* obj = new Key(x, y, 0);
    allKeys.push_back(obj);
    return obj;
}

Map* Manager::createMap() {
    Map* obj = new Map();
    allMaps.push_back(obj);
    return obj;
}

