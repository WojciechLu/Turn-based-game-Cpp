#pragma once
#include <SFML/Graphics.hpp>
//#include "Character.h"

#ifndef GAMEPLAYER_H
#define GAMEPLAYER_H

//class PlayerCharacter : Character
class PlayerCharacter{
	sf::Texture texture; //texture of the player
	int coinsAmount{}; //setting the coinAmount value to 0
	sf::Vector2f pos; //possition of the player
	sf::Sprite sprite;	//sprite of the player
	int HP = 20;
	int attackDamage = 6;
	int choiceSkill{};


public:
	PlayerCharacter(std::string, float, float); //constructor: set texture, and x, y
	bool setUpSprite(std::string);	//set texture to sprite
	//bool setUpSpriteAttack(std::string);
	float getPosX() const;
	float getPosY() const;
	int getHP() const;
	int getAttackDamage() const;

	void setCoins(int coins);
	int getCoins() const;

	sf::Texture getTexture() const;
	void setSprite(sf::Sprite);
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