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
    tiles.push_back(new GameTile("images/map/coin.png", 3 * 64, 3 * 64, true, false));
    tiles.push_back(new GameTile("images/map/coin.png", 4 * 64, 5 * 64, true, false));
    tiles.push_back(new GameTile("images/map/coin.png", 6 * 64, 7 * 64, true, false));
    numberOfCoinsOnMap = 3;
}

int coins::isPlayerOn(int x, int y, PlayerCharacter *player) { //to improve
    int removeInt = -1;
    for (int i = 0; i < numberOfCoinsOnMap; i++){
        if (tiles[i]->pos.x == x && tiles[i]->pos.y == y) { 
            tiles.erase(tiles.begin() + i);
            numberOfCoinsOnMap--;
            player->AddCoins(50);
        }
    }
    return -1;
}