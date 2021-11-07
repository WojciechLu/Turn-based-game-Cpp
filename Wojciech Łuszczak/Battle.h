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
	void setPlayerHP(int);	//setting playerHP to current
	void setEnemyHP(int);

	//ideas to add
	//void setPlayerTurn(); //setting `true` or `false` to playerTurn
	//bool whoWon(); //return true if player won, return false if enemy won
	//void setPlayerSprite(PlayerCharacter* player); //getting player texture and sprite and setting it
	//void setEnemySprite(EnemyCharacter* enemy);

	void actionsMenu(std::string, float, float);
	bool setUpSpriteActionsMenu(std::string); //setting texture and then using setUpSprite to set sprite
	
	//unused and undeclared								  
	//void setUpAttackChoice();
	//void updateSpriteAttackChoice();

public:

	

	//void chooseAction(char, Attack); //changing spell choice by 'A' or 'D' key
	void chooseAction(char, PlayerCharacter, Attack*, WindowGame*); //changing texture sprite to next or previous attack, used in StartGame
	Battle(PlayerCharacter, EnemyCharacter); //constructor, get player and enemy informations and setting to battle class

	sf::Sprite getSpriteMenu();
	sf::Sprite getSpritePlayer();
	sf::Sprite getSpriteEnemy();
	sf::Sprite getSpriteAttack();
	//Battle();

};

#endif