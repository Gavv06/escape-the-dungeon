#pragma once
#include <iostream>
#include "Player.h"


class Interactable{
public:
	virtual void interact(Player& player) = 0;
};

