#pragma once
#include <SFML/Graphics.hpp>
#include "Character.h"

#ifndef GAMEPLAYER_H
#define GAMEPLAYER_H

//class PlayerCharacter : Character
class PlayerCharacter : public Character{

	sf::Texture orginalTexture; //texture of the player
	sf::Texture texture; //texture of the player
	int coinsAmount{}; //setting the coinAmount value to 0
	sf::Vector2f pos; //possition of the player
	sf::Sprite orginalSprite;
	sf::Sprite sprite;	//sprite of the player
	int HP;
	int attackDamage;
	int choiceSkill{};


public:
	PlayerCharacter(std::string textureName, float x, float y, int HP, int DMG); //constructor: set texture, and x, y
	PlayerCharacter(const PlayerCharacter& p1);
	bool setUpSprite(std::string, sf::Texture*, sf::Sprite*);	//set texture to sprite
	//bool setUpSpriteAttack(std::string);
	//float getPosX() const;
	//float getPosY() const;
	//int getHP() const;
	int getAttackDamage() const;

	void setCoins(int coins);
	int getCoins() const;

	sf::Texture getTexture() const;
	void setSprite(sf::Sprite);
	sf::Sprite getOrginalSprite() const;
	sf::Sprite getSprite() const;

	void setChoiceSkill(int);
	int getChoiceSkill() const;
	
	//skill set

	int skill(int);
	void swordAttack();
	void block();
	void aim();
	void bash();
	
	void Move(std::string); //check if key pressed, get key pressed, set possition


	//void SpendCoins(int); //function to lose coins by buying

};

#endif