#pragma once
#include <SFML/Graphics.hpp>

#ifndef GAMESTAGES_H
#define GAMESTAGES_H

class StateMachine {
	bool isWorld, isBattle;
	bool isInventory = 0;
public:
	//setters
	StateMachine(bool, bool);
	void world2Battle();
	void battle2World();
	void world2Inventory();
	void inventory2World();
	
	//getters
	bool getIsWorld();
	bool getIsBattle();
	bool getIsInventory();
};

#endif