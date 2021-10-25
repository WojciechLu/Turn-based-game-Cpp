#include "gameTile.h"

//constructor
GameTile::GameTile(std::string textureName, float x, float y, bool passable, bool exit) {
    if (!setUpSprite(textureName)) {
        return;
    }
    pos = sf::Vector2f(x, y); //setting vector of x and y position
    sprite.setPosition(pos); //update the sprite's position
	isPassable = passable;
    isExit = exit;
}

//setting the spire texture
bool GameTile::setUpSprite(std::string textureName) {
    if (!texture.loadFromFile(textureName)) {
        return false;
    }

    texture.setSmooth(true);
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0, 0, 64, 64)); //setting the texture size of 64x64
    return true;
}