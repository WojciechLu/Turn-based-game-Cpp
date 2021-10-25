#pragma once
#include <SFML/Graphics.hpp>

#ifndef GAMEPLAYER_H
#define GAMEPLAYER_H

class StateMachine {
public:
	bool isMap = true;

	void startBattle();
	void endBattle();
	void openInventory();
	void closeInventory();
};

#endif