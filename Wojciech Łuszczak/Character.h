#pragma once
#include <SFML/Graphics.hpp>


#ifndef CHARACTER_H
#define CHARACTER_H

class Character
{
	sf::Texture texture; //texture of the player
	sf::Vector2f pos; //possition of the player
	int HP = 20;
	int attackDamage = 5;

public:
	sf::Sprite sprite;	//sprite of the player
	bool setUpSprite(std::string);	//set texture to sprite
	float getPosX();
	void setPosX(int);
	float getPosY();
	void setPosY(int);
	int getHP();
	void setHP(int);
	int getAD();
	void setAD(int);

};

#endif