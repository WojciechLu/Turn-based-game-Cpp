#pragma once
#include <SFML/Graphics.hpp>
#include "playerCharacter.h"
#include "Character.h"
#include "StateMachine.h"

#ifndef GAMEENEMY_H
#define GAMEENEMY_H

class EnemyCharacter : public Character{
	sf::Texture texture; //texture of the player
	sf::Vector2f pos; //possition of the player
	int HP = 20;
	int attackDamage = 5;

public:
	sf::Sprite sprite;	//sprite of the player
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

