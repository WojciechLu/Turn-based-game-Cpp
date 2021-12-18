#pragma once
#include <SFML/Graphics.hpp>


#ifndef CHARACTER_H
#define CHARACTER_H

class Character
{
protected:
	sf::Texture texture; //texture of the player
	sf::Vector2f pos; //possition of the player
	int HP;
	int attackDamage;
	sf::Sprite sprite;	//sprite of the player

public:
	//bool setUpSprite(std::string);	//set texture to sprite
	sf::Vector2f getPos();
	void setPos(int, int);
	//float getPosY();
	//void setPosY(int);
	int getHP();
	void setHP(int);
	int getAD();
	void setAD(int);
	sf::Texture getTexture();
	void setTexture(sf::Texture);
	sf::Sprite getSprite();
	void setSprite(sf::Sprite);

	bool setUpSprite(std::string textureName);

};

#endif