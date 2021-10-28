#pragma once
#include <SFML/Graphics.hpp>
#include "gameTile.h"
#include "playerCharacter.h"

#ifndef COINS_H
#define COINS_H

class coins
{
	sf::Vector2f pos;
	sf::Texture texture; //texture of coins
	void setUpTiles();
public:
	std::vector<GameTile*> tiles;
	sf::Sprite sprite;	//sprite of coins
	int numberOfCoinsOnMap; //how many coins are on the map
	
	coins();
	int isPlayerOn(int, int, PlayerCharacter *player);
};

#endif