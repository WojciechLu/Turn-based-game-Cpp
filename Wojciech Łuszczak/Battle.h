#pragma once
#include <SFML/Graphics.hpp>
#include "playerCharacter.h"

#ifndef BATTLE_H
#define BATTLE_H

class Battle
{
	int playerHP{};	//reset the playerHP to zero
	int enemyHP{};	//reset the enemyHP to zero
	bool playerTurn = true;

	sf::Texture textureBattleField;		// texture and sprite of the background

	sf::Texture textureActionsPlayer;	//texture and sprite of the player's option to attack
	sf::Vector2f posActionsPlayer;
	int attackChoice{};

	sf::Texture texturePlayer;
	sf::Vector2f posPlayer;

	sf::Texture textureEnemy;
	sf::Vector2f posEnemy;

	void setUpInitialState();
	void setPlayerTurn(); //setting `true` or `false` to playerTurn
	void setPlayerHP(PlayerCharacter* player);	//setting playerHP to current
	//void setEnemyHP(EnemyCharacter* enemy);
	void setPlayerSprite(PlayerCharacter* player); //getting player texture and sprite and setting it
	//void setEnemySprite(EnemyCharacter* enemy);

	void actionsPlayer(std::string, float, float);
	bool setUpSpriteActionsPlayer(std::string);
	void setUpAttackChoice();
	void updateSpriteAttackChoice();

public:
	sf::Sprite spriteBattleField;
	sf::Sprite spriteActionsPlayer;
	sf::Sprite spritePlayer;
	sf::Sprite spriteEnemy;
	void chooseAction(char); //changing spell choice by 'A' or 'D' key
	Battle(); //constructor

};

#endif