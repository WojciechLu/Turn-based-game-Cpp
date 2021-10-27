#pragma once
#include <SFML/Graphics.hpp>

#ifndef GAMEPLAYER_H
#define GAMEPLAYER_H

class PlayerCharacter {
public:
	sf::Vector2f pos; //possition of the player
	sf::Texture texture; //texture of the player
	sf::Sprite sprite;	//sprite of the player


	PlayerCharacter(std::string, float, float); //constructor: set texture, and x, y
	bool setUpSprite(std::string);	//set texture to sprite
	void Move(std::string); //check if key pressed, get key pressed, set possition
};

#endif