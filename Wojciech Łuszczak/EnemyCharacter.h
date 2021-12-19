#pragma once
#include <SFML/Graphics.hpp>
#include "playerCharacter.h"
#include "Character.h"
#include "StateMachine.h"

#ifndef GAMEENEMY_H
#define GAMEENEMY_H

class EnemyCharacter : public Character{
public:
	EnemyCharacter(std::string, float, float); //constructor: set texture, and x, y
	EnemyCharacter(const EnemyCharacter& e1);
	bool setUpSprite(std::string);	//set texture to sprite
	//float getPosX();
	//float getPosY();
	//int getHP();
	//void setHP(int);


	bool isPlayerOn(PlayerCharacter*, StateMachine*); //if player is on enemy, then set statemachine on battle
};

#endif

