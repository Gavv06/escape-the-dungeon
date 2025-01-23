#pragma once
#include "Player.h"
#include "Chaser.h"
#include "Patrol.h"
#include "Potion.h"
#include "Key.h"
#include <random> 
#include <chrono>



class Manager{
public:
	vector<Player*> allPlayers;
	Player* createPlayer();

	vector<Chaser*> allChasers;
	Chaser* createChaser();

	vector<Patrol*> allPatrols;
	Patrol* createPatrol();

	vector<Potion*> allPotions;
	Potion* createPotion();

	vector<Key*> allKeys;
	Key* createKey();

	float initializeRandomGenerator(int nb1, int nb2);

	void setSeed(unsigned int seed);
};

