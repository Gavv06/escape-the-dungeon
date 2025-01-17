#pragma once
#include "Player.h"



class Manager{
public:
	vector<Player*> allPlayers;
	Player* createPlayer();
};

