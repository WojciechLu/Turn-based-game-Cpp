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
	std::vector<sf::Sprite> spriteAnimation;

public:
	sf::Sprite getSprite();
	sf::Texture getTexture();
	void setUpInitial(std::string, float, float);
	void doAttack(int, sf::Vector2f);
	bool setUpSprite(std::string);	//set texture to sprite
	Attack();
	void animation(windowGame*);
};

#endif