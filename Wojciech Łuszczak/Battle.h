#pragma once
#include <SFML/Graphics.hpp>
#include "playerCharacter.h"
#include "EnemyCharacter.h"
#include "Attack.h"

#ifndef BATTLE_H
#define BATTLE_H

class Battle
{
	int playerHP{};	//reset the playerHP to 
	sf::Texture texturePlayer;
	sf::Vector2f posPlayer;
	sf::Sprite spritePlayer;
	bool playerTurn = true;

	sf::Texture textureBattleField;		// texture and sprite of the background
	sf::Sprite spriteBattleField;

	sf::Texture textureActionsMenu;	//texture and sprite of the player's option to attack
	sf::Vector2f posActionsMenu;
	sf::Sprite spriteActionsMenu;
	int attackChoice{};

	int enemyHP{};	//reset the enemyHP to zero
	sf::Texture textureEnemy;
	sf::Vector2f posEnemy;
	sf::Sprite spriteEnemy;

	sf::Texture textureAttack;
	sf::Vector2f posAttack;
	sf::Sprite attackSprite;

	void setPlayer(PlayerCharacter);
	void setEnemy(EnemyCharacter);


	//void setPlayerTurn(); //setting `true` or `false` to playerTurn
	//void setPlayerHP(PlayerCharacter* player);	//setting playerHP to current
	//void setEnemyHP(EnemyCharacter* enemy);
	//void setPlayerSprite(PlayerCharacter* player); //getting player texture and sprite and setting it
	//void setEnemySprite(EnemyCharacter* enemy);

	void actionsMenu(std::string, float, float);
	bool setUpSpriteActionsMenu(std::string);
	void setUpAttackChoice();
	void updateSpriteAttackChoice();

public:

	

	//void chooseAction(char, Attack); //changing spell choice by 'A' or 'D' key
	void chooseAction(char, PlayerCharacter, Attack*, windowGame*);
	Battle(PlayerCharacter, EnemyCharacter); //constructor
	sf::Sprite getSpriteMenu();
	sf::Sprite getSpritePlayer();
	sf::Sprite getSpriteEnemy();
	sf::Sprite getSpriteAttack();
	//Battle();

};

#endif