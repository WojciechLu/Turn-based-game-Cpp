#pragma once
#include <SFML/Graphics.hpp>

#ifndef GAMEENEMY_H
#define GAMEENEMY_H

class EnemyCharacter{
	sf::Texture texture; //texture of the player
	sf::Vector2f pos; //possition of the player
	int HP = 20;
	int attackDamage = 5;

public:
	sf::Sprite sprite;	//sprite of the player
	EnemyCharacter(std::string, float, float); //constructor: set texture, and x, y
	bool setUpSprite(std::string);	//set texture to sprite
	float getPosX();
	float getPosY();
	int getHP();
	void setHP(int);
	int getAD();
	void setAD(int);
	sf::Texture getTexture();
	void setTexture(sf::Texture);
	sf::Sprite getSprite();
	void setSprite(sf::Sprite);
};

#endif

