#pragma once
#include <SFML/Graphics.hpp>
#include "gameTile.h"
#include "playerCharacter.h"

#ifndef COINS_H
#define COINS_H

class Coins
{
	sf::Vector2f pos;
	sf::Texture texture; //texture of coins
	int numberOfCoinsOnMap; //how many coins are on the map
	void setUpTiles();
public:
	std::vector<GameTile*> tiles;
	sf::Sprite sprite;	//sprite of coins
	
	Coins();
	int getNumberOfCoins(); //return the number of coins on the map
	void setNumberOfCoins(int); //set the number of coins on the map
	void isPlayerOn(PlayerCharacter *player); //if player is on coin, then remove coin from vector using erase
};

#endif