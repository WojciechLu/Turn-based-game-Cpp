#pragma once
#include <SFML/Graphics.hpp>

#ifndef GAMETILE_H
#define GAMETILE_H

class GameTile {
public:
	bool isPassable; //can player go to the tile?
	bool isExit; //is the tile the exit?
	sf::Vector2f pos; //possition of the tile
	sf::Texture texture; //texture of the tile
	sf::Sprite sprite; //sprite of the tile

	GameTile(std::string, float, float, bool, bool); //constructor: set the string texture, set x, set y, check if passable, check if exit
	bool setUpSprite(std::string); // get the string texture and set the sprite
};

#endif