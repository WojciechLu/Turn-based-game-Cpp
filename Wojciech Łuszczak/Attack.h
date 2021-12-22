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



public:
	sf::Sprite getSprite(); //return sprite of attack
	sf::Texture getTexture(); //return texture of attack
	void setUpInitial(std::string, float, float); //setting string texture path, position x,y to set attack
	int doAttack(int a, int ad, sf::Vector2f pos); //set postion where should be displeyed
	int doAttackEnemy(int ad, sf::Vector2f pos);
	bool setUpSprite(std::string);	//set texture to sprite
	Attack(); //constructor
	//void animation(WindowGame*); //not working proprely animation, frames animation overlap

	//attacks
	int SwordAttack(int);
	int BlockSkill();
	int PowerBuff();
	int BashAttack(int);
};

#endif