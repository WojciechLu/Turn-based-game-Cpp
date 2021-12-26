#pragma once
#include <SFML/Graphics.hpp>
#include "PlayerCharacter.h"
#include "EnemyCharacter.h"
#include "Attack.h"

#ifndef BATTLE_H
#define BATTLE_H

class Battle
{
	bool playerTurn;
	short battleResult;
	int skillChoice;

	short isOnFire = 0;
	bool isShieldOn = false;

	sf::Texture textureBg;		// texture and sprite of the background
	sf::Sprite spriteBg;

	sf::Texture textureActionsMenu;	//texture and sprite of the player's option to attack
	sf::Vector2f posActionsMenu;
	sf::Sprite spriteActionsMenu;

	sf::Texture textureAttack;
	sf::Vector2f posAttack;
	sf::Sprite attackSprite;


	void setUpBackground(std::string, sf::IntRect);
	bool setUpSprite(std::string, sf::IntRect, sf::Texture& texture, sf::Sprite*); //setting texture and then using setUpSprite to set sprite

	void playerAttack(int a);
	void actionsMenu(std::string);
	void checkWin();

public:
	PlayerCharacter player;
	EnemyCharacter *enemy;

	void chooseAction(sf::Keyboard::Key key, PlayerCharacter player, Attack* attack);
	Battle(PlayerCharacter &playerPattern, Character &enemyPattern);
	sf::Sprite getSpriteMenu() const;
	sf::Sprite getSpriteAttack() const;
	sf::Sprite getSpriteBg() const;

	void enemyAttack(Attack* attack);
	int getBattleResult() const;
	bool isPlayerTurn() const;
	void setPlayerTurn(bool a);
};

#endif