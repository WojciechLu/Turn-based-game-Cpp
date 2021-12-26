#pragma once
#include <SFML/Graphics.hpp>
//#include "Battle.h"
#include "gameWorld.h"
#include "Coins.h"
#include "EnemyCharacter.h"
#include "Attack.h"
#include "Battle.h"
#ifndef WINDOWGAME_H
#define WINDOWGAME_H

class WindowGame{
	sf::VideoMode vm;
public:
	sf::RenderWindow window;
	WindowGame(int, int, std::string); //constructor: set title, width, height
	//void drawBattle(Battle& battle);
	void draw2dWorld(GameWorld gameWorld, PlayerCharacter player, EnemyCharacter &enemy1, Coins coinsInGame);
	//void updateInputWorld(PlayerCharacter* player, EnemyCharacter& enemiesInGame, GameWorld gameWorld, StateMachine& states, Coins& coinsInGame);
	void drawBattle(Battle battle);

	void animation(Attack attackAnimation);
	void updateInputWorld(PlayerCharacter* player, EnemyCharacter &enemiesInGame, GameWorld gameWorld, StateMachine &states, Coins &coinsInGame);
	void battleUpdate(Battle &battle, Attack attack, StateMachine &states);
};

#endif