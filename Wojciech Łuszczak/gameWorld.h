#pragma once
#include <SFML/Graphics.hpp>
#include "gameTile.h"
#include <vector>
	
#ifndef GAMEWORLD_H
#define GAMEWORLD_H


class GameWorld {
	sf::Vector2i exitPos;
	sf::Vector2i playerPos;
	std::vector<sf::Vector2i> enemyPositions; //vector of Vector2i with enemies' possition
	std::vector<sf::Vector2i> coinPossition; //vector of Vector2i with coins' possition
	void setUpInitialState();
	void setUpEnemyPositions();
	void setUpCoinPositions();
	void setUpTiles();

public:
	std::vector< std::vector<GameTile *> > tiles; // vector of vector of GameTile class chyba
	int gridLength;
	GameWorld();
};

#endif


//https://www.geeksforgeeks.org/vector-of-vectors-in-c-stl-with-examples/ o to chodzi z tymi < >	
/*
Once the header is included, it checks if a unique value (in this case HEADERFILE_H) is defined. Then if it's not defined,
it defines it and continues to the rest of the page.
When the code is included again, the first ifndef fails, resulting in a blank file.
That prevents double declaration of any identifiers such as types, enums and static variables.*/
//https://cpp0x.pl/dokumentacja/standard-C++/vector/819