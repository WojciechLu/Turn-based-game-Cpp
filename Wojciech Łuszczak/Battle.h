#pragma once
#include <SFML/Graphics.hpp>
#include "PlayerCharacter.h"
#include "EnemyCharacter.h"
#include "Attack.h"
#include "windowGame.h"

#ifndef BATTLE_H
#define BATTLE_H

class Battle
{
	PlayerCharacter player;
	EnemyCharacter enemy;

	bool playerTurn;
	int battleResult;

	sf::Texture textureBg;		// texture and sprite of the background
	sf::Sprite spriteBg;

	sf::Texture textureActionsMenu;	//texture and sprite of the player's option to attack
	sf::Vector2f posActionsMenu;
	sf::Sprite spriteActionsMenu;
	int attackChoice{};

	sf::Texture textureAttack;
	sf::Vector2f posAttack;
	sf::Sprite attackSprite;

	void setUpBackground(std::string, sf::IntRect);
	void playerAttack(int a);
	void checkWin();


	//int playerHP{};	//reset the playerHP to 
	//sf::Text textPlayerHP;
	//sf::Texture texturePlayer;
	//sf::Vector2f posPlayer;
	//sf::Sprite spritePlayer;
	//bool playerTurn = true;
	//int battleResult = 0;

	//sf::Texture textureBg;		// texture and sprite of the background
	//sf::Sprite spriteBg;

	//sf::Texture textureActionsMenu;	//texture and sprite of the player's option to attack
	//sf::Vector2f posActionsMenu;
	//sf::Sprite spriteActionsMenu;
	//int attackChoice{};

	//EnemyCharacter e1;
	//int enemyHP{};	//reset the enemyHP to zero
	//sf::Text textEnemyHP;
	//sf::Texture textureEnemy;
	//sf::Vector2f posEnemy;
	//sf::Sprite spriteEnemy;

	//sf::Texture textureAttack;
	//sf::Vector2f posAttack;
	//sf::Sprite attackSprite;

	//void setPlayer(PlayerCharacter);
	//void setEnemy(EnemyCharacter);
	//void setPlayerHP(int);	//setting playerHP to current
	//void setEnemyHP(int);
	//void setUpBackground(std::string, sf::IntRect);
	//ideas to add
	//void setPlayerTurn(); //setting `true` or `false` to playerTurn
	//void setPlayerSprite(PlayerCharacter* player); //getting player texture and sprite and setting it
	//void setEnemySprite(EnemyCharacter* enemy);

	//void actionsMenu(std::string);
	//bool setUpSprite(std::string, sf::IntRect, sf::Texture*, sf::Sprite*); //setting texture and then using setUpSprite to set sprite
	//void playerAttack(int a);
	//void checkWin();


public:
	void chooseAction(char key, PlayerCharacter player, Attack* attack, WindowGame* m_window);
	Battle(PlayerCharacter p, EnemyCharacter e);

	sf::Sprite getSpriteMenu() const;
	sf::Sprite getSpritePlayer() const;
	sf::Sprite getSpriteEnemy() const;
	sf::Sprite getSpriteAttack() const;
	sf::Sprite getSpriteBg() const;
	int getPlayerHP() const;
	int getEnemyHP() const;
	int getBattleResult() const;
	

	//void chooseAction(char, PlayerCharacter, Attack*, WindowGame*); //changing texture sprite to next or previous attack, used in StartGame
	//Battle(PlayerCharacter p, EnemyCharacter e);
	//Battle(PlayerCharacter); //constructor, get player and enemy informations and setting to battle class

	//sf::Sprite getSpriteMenu() const;
	//sf::Sprite getSpritePlayer() const;
	//sf::Sprite getSpriteEnemy() const;
	//sf::Sprite getSpriteAttack() const;
	//sf::Sprite getSpriteBg() const;
	//int getPlayerHP() const;
	//int getEnemyHP() const;
	//int getBattleResult() const;
	//Battle();

};

#endif