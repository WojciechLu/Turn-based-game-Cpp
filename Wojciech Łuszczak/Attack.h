#pragma once
#include <SFML/Graphics.hpp>
#include "windowGame.h"

#ifndef ATTACK_H
#define ATTACK_H

class Attack
{
	sf::Vector2f posAttack;
	sf::Texture textureAttack;
	sf::Sprite spriteAttack;
	std::vector<sf::Sprite> spriteAnimation; //vector containing frames of animated attack

public:
	sf::Sprite getSprite(); //return sprite of attack
	sf::Texture getTexture(); //return texture of attack
	void setUpInitial(std::string, float, float); //setting string texture path, position x,y to set attack
	void doAttack(int, sf::Vector2f); //in the future add switch case to set adequate texturepath to chosen action, set postion where should be displeyed
	bool setUpSprite(std::string);	//set texture to sprite
	Attack(); //constructor
	void animation(WindowGame*); //not working proprely animation, frames animation overlap
};

#endif