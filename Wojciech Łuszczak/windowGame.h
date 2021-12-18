#pragma once
#include <SFML/Graphics.hpp>
//#include "Battle.h"
#include "gameWorld.h"
#include "Coins.h"
#include "EnemyCharacter.h"
#ifndef WINDOWGAME_H
#define WINDOWGAME_H

class WindowGame{
	sf::VideoMode vm;
public:
	sf::RenderWindow window;
	void setWindowSize(int, int);
	WindowGame(int, int, std::string); //constructor: set title, width, height
	sf::RenderWindow getWindow();
	//void drawBattle(Battle& battle);
	void draw2dWorld(GameWorld gameWorld, PlayerCharacter player, EnemyCharacter enemy1, Coins coinsInGame);
};

#endif