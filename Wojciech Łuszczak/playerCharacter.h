#pragma once
#include <SFML/Graphics.hpp>

#ifndef GAMEPLAYER_H
#define GAMEPLAYER_H

class PlayerCharacter {
	sf::Texture texture; //texture of the player
	int coinsAmount;

public:
	std::vector<sf::Vector2i> coins; //vector of each coin
	sf::Vector2f pos; //possition of the player
	sf::Sprite sprite;	//sprite of the player
	PlayerCharacter(std::string, float, float); //constructor: set texture, and x, y
	bool setUpSprite(std::string);	//set texture to sprite
	void Move(std::string); //check if key pressed, get key pressed, set possition
	/*
	void AddCoins(int); //function to add coins to inventory
	void SpendCoins(int); //function to lose coins by buying
	*/
};

#endif