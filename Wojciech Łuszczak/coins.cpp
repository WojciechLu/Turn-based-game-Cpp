#include "coins.h"
#include <iostream>
#include "windowGame.h"

//void coins::setUpInitialState() {	//setting the values of coin
//    if (!setUpSprite("images/map/coin.png")) {
//        return;
//    }
//    pos = sf::Vector2f(3*64, 3*64); //setting vector of x and y position
//    sprite.setPosition(pos); //update the sprite's position
//    setUpSprite("images/map/coin.png"); //setting the spire texture
//    numberOfCoinsOnMap = 3;
//}
//
//bool coins::setUpSprite(std::string textureName) {
//    if (!texture.loadFromFile(textureName)) {
//        return false;
//    }
//
//    texture.setSmooth(true); // antialysing
//    sprite.setTexture(texture);
//    sprite.setTextureRect(sf::IntRect(0, 0, 64, 64)); //setting the texture size of 64x64
//    return true;
//}

coins::coins() {
    setUpTiles();
}

void coins::setUpTiles() {
    tiles.clear();
    tiles.push_back(new GameTile("images/map/coin.png", 3 * 64, 3 * 64, true, false)); //set texture of coin, set position, passable and not exit
    tiles.push_back(new GameTile("images/map/coin.png", 4 * 64, 5 * 64, true, false));
    tiles.push_back(new GameTile("images/map/coin.png", 6 * 64, 7 * 64, true, false));
    numberOfCoinsOnMap = tiles.size(); //set the number of 
}

int coins::getNumberOfCoins() {
    return this->numberOfCoinsOnMap;
}

void coins::setNumberOfCoins(int a) {
    this->numberOfCoinsOnMap = a;
}

void coins::isPlayerOn(PlayerCharacter *player) { // get pos x, y, get pointer to obj of class player to give coins to inventory
    for (int i = 0; i < numberOfCoinsOnMap; i++){
        if (tiles[i]->pos.x == player->getPosX() && tiles[i]->pos.y == player->getPosY()) { //for each coin in vector tiles, checking if player is on this coin
            tiles.erase(tiles.begin() + i); //deleting the coin from vector
            this->setNumberOfCoins(this->tiles.size()); //set the number of coins
            player->AddCoins(50); //adding the number of coins to player
            break; //if player was on the coin, then break loop
        }
    }
}