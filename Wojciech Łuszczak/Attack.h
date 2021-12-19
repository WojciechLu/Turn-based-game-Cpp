#pragma once
#include <SFML/Graphics.hpp>
#include "playerCharacter.h"

#ifndef ATTACK_H
#define ATTACK_H

class Attack
{
	sf::Vector2f posAttack;
	sf::Texture textureAttack;
	sf::Sprite spriteAttack;
	int damage;



public:
	sf::Sprite getSprite(); //return sprite of attack
	sf::Texture getTexture(); //return texture of attack
	void setUpInitial(std::string, float, float); //setting string texture path, position x,y to set attack
	int doAttack(int, int, sf::Vector2f); //set postion where should be displeyed
	bool setUpSprite(std::string);	//set texture to sprite
	Attack(); //constructor
	//void animation(WindowGame*); //not working proprely animation, frames animation overlap

	//attacks
	int SwordAttack(int);
	int BlockSkill();
	int BashAttack(int);
};

#endif