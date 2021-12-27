#pragma once
#include <SFML/Graphics.hpp>
#include "gameTile.h"
#include <vector>
	
#ifndef GAMEWORLD_H
#define GAMEWORLD_H


class GameWorld {
	sf::Vector2i exitPos;
	void setUpInitialState();
	void setUpTiles();
	int lvl1[81] = { 
		0, 1, 2, 3, 4, 2, 6, 0, 0,
		7, 2, 8, 10, 9, 11, 4, 18, 0,
		13, 14, 16, 16, 15, 15, 17, 24, 0,
		19, 14, 15, 16, 16, 15, 17, 5, 18,
		7, 14, 16, 15, 16, 16, 15, 17, 6,
		13, 14, 15, 16, 16, 15, 16, 17, 12,
		7, 20, 21, 16, 16, 15, 16, 23, 12,
		25, 29, 27, 20, 21, 22, 23, 31, 32,
		0, 0, 0, 29, 28, 26, 28, 30, 0 };
	int impassable[21] = { 0, 1, 2, 3, 4, 5, 6, 7, 12, 13, 18, 19, 24, 25, 26, 27, 28, 29, 30, 31, 32 };
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