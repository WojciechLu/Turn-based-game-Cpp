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

	sf::Texture textureBg;		// texture and sprite of the background
	sf::Sprite spriteBg;

	sf::Texture textureActionsMenu;	//texture and sprite of the player's option to attack
	sf::Vector2f posActionsMenu;
	sf::Sprite spriteActionsMenu;

	sf::Texture textureAttack;
	sf::Vector2f posAttack;
	sf::Sprite attackSprite;

	sf::Sprite buffIcon;
	sf::Texture buffIconTexture;

	sf::Sprite shieldIcon;
	sf::Texture shieldIconTexture;

	void setUpBackground(std::string, sf::IntRect);
	bool setUpSprite(std::string, sf::IntRect, sf::Texture& texture, sf::Sprite*); //setting texture and then using setUpSprite to set sprite

	void playerAttack(int a);
	void actionsMenu(std::string);
	void checkWin();

public:
	PlayerCharacter player;
	EnemyCharacter *enemy;
	sf::Sprite spriteEnemy;
	bool isCurrent = false;
	int isShieldOn = 0;
	int isBuffOn = 0;
	void chooseAction(sf::Keyboard::Key key, PlayerCharacter player, Attack* attack);
	Battle(PlayerCharacter &playerPattern, sf::Sprite spriteEnemy);
	sf::Sprite getSpriteMenu() const;
	sf::Sprite getSpriteAttack() const;
	sf::Sprite getSpriteBg() const;
	sf::Sprite getSpriteIconShield() const;
	sf::Sprite getSpriteIconBuff() const;

	void enemyAttack(Attack* attack);
	int getBattleResult() const;
	bool isPlayerTurn() const;
	void setPlayerTurn(bool a);
};

#endif