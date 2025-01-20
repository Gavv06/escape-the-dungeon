#pragma once
#include "Player.h"
#include "Chaser.h"
#include "Patrol.h"



class Manager{
public:
	vector<Player*> allPlayers;
	Player* createPlayer();

	vector<Chaser*> allChasers;
	Chaser* createChaser();

	vector<Patrol*> allPatrols;
	Patrol* createPatrol();
};

