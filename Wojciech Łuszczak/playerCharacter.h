#pragma once
#include <SFML/Graphics.hpp>

#ifndef GAMEPLAYER_H
#define GAMEPLAYER_H

class PlayerCharacter {
	sf::Texture texture; //texture of the player
	int coinsAmount{}; //setting the coinAmount value to 0
	sf::Vector2f pos; //possition of the player
	int HP = 20;
	int attackDamage = 6;

public:
	sf::Sprite sprite;	//sprite of the player
	PlayerCharacter(std::string, float, float); //constructor: set texture, and x, y
	bool setUpSprite(std::string);	//set texture to sprite
	float getPosX();
	float getPosY();
	int getHP();
	int getAttackDamage();
	int getCoins();
	
	void Move(std::string); //check if key pressed, get key pressed, set possition
	void AddCoins(int coins);

	//void SpendCoins(int); //function to lose coins by buying

};

#endif