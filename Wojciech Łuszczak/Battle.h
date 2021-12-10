#pragma once
#include <SFML/Graphics.hpp>
#include "playerCharacter.h"
#include "EnemyCharacter.h"
#include "Attack.h"
#include "windowGame.h"

#ifndef BATTLE_H
#define BATTLE_H

class Battle
{
	int playerHP{};	//reset the playerHP to 
	sf::Text textPlayerHP;
	sf::Texture texturePlayer;
	sf::Vector2f posPlayer;
	sf::Sprite spritePlayer;
	bool playerTurn = true;
	int battleResult = 0;

	sf::Texture textureBg;		// texture and sprite of the background
	sf::Sprite spriteBg;

	sf::Texture textureActionsMenu;	//texture and sprite of the player's option to attack
	sf::Vector2f posActionsMenu;
	sf::Sprite spriteActionsMenu;
	int attackChoice{};

	int enemyHP{};	//reset the enemyHP to zero
	sf::Text textEnemyHP;
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
	void setUpBackground(std::string, sf::IntRect);
	//ideas to add
	//void setPlayerTurn(); //setting `true` or `false` to playerTurn
	//bool whoWon(); //return true if player won, return false if enemy won
	//void setPlayerSprite(PlayerCharacter* player); //getting player texture and sprite and setting it
	//void setEnemySprite(EnemyCharacter* enemy);

	void actionsMenu(std::string);
	bool setUpSprite(std::string, sf::IntRect, sf::Texture*, sf::Sprite*); //setting texture and then using setUpSprite to set sprite
	void playerAttack(int a);
	void checkWin();
	//unused and undeclared								  
	//void setUpAttackChoice();
	//void updateSpriteAttackChoice();

public:

	

	//void chooseAction(char, Attack); //changing spell choice by 'A' or 'D' key
	void chooseAction(char, PlayerCharacter, Attack*, WindowGame*); //changing texture sprite to next or previous attack, used in StartGame
	Battle(PlayerCharacter); //constructor, get player and enemy informations and setting to battle class

	sf::Sprite getSpriteMenu() const;
	sf::Sprite getSpritePlayer() const;
	sf::Sprite getSpriteEnemy() const;
	sf::Sprite getSpriteAttack() const;
	sf::Sprite getSpriteBg() const;
	int getPlayerHP() const;
	int getEnemyHP() const;
	int getBattleResult() const;
	//Battle();

};

#endif