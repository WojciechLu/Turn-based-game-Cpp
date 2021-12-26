#pragma once
#include <SFML/Graphics.hpp>
#include "playerCharacter.h"
#include "Character.h"
#include "StateMachine.h"
#include "gameTile.h"

#ifndef GAMEENEMY_H
#define GAMEENEMY_H

class EnemyCharacter : public Character{
	int numberOfEnemiesOnMap; //how many coins are on the map
	void setUpTiles();

public:
	std::vector<GameTile*> tiles;
	std::vector<Character*> entities;
	int getNumberOfEnemies();
	void setNumberOfEnemies(int a);
	//EnemyCharacter(std::string, float, float); //constructor: set texture, and x, y
	EnemyCharacter(); //constructor: set texture, and x, y
	EnemyCharacter(const EnemyCharacter& e1);
	bool setUpSprite(std::string);	//set texture to sprite

	bool isPlayerOn(PlayerCharacter* player); //if player is on coin, then remove coin from vector using erase

};

#endif

