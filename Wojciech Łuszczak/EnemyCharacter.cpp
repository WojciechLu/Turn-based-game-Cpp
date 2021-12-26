#include "EnemyCharacter.h"
#include <iostream>

//EnemyCharacter::EnemyCharacter(std::string textureName, float x, float y) { //constructor: set texture, and x, y
//	if (!setUpSprite(textureName)) {
//		return;
//	}
//	pos = sf::Vector2f(x, y); //setting vector of x and y position
//	sprite.setPosition(pos); //update the sprite's position
//	setUpSprite(textureName); //setting the spire texture
//
//	setHP(20);
//	setAD(5);
//} 

EnemyCharacter::EnemyCharacter(const EnemyCharacter& e1) {
	setTexture(e1.texture);
	setPos(e1.pos.x, e1.pos.y);
	setSprite(e1.sprite);
	setHP(e1.HP);
	setAD(e1.attackDamage);
}

bool EnemyCharacter::setUpSprite(std::string textureName) { //set texture to sprite
	if (!texture.loadFromFile(textureName)) {
		return false;
	}

	texture.setSmooth(true); // antialysing
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(0, 0, 64, 64)); //setting the texture size of 64x64
	setSprite(this->sprite);

	return true;
}	

EnemyCharacter::EnemyCharacter() {
	setUpTiles();
}

void EnemyCharacter::setUpTiles() {
	tiles.clear();
	tiles.push_back(new GameTile("images/enemyWarrior64.png", 4 * 64, 3 * 64, true, false)); //set texture of enemies, set position, passable and not exit
	tiles.push_back(new GameTile("images/enemyVampire64.png", 5 * 64, 1 * 64, true, false)); //set texture of enemies, set position, passable and not exit
	numberOfEnemiesOnMap = tiles.size(); //set the number of 
}

int EnemyCharacter::getNumberOfEnemies() {
	return this->numberOfEnemiesOnMap;
}

void EnemyCharacter::setNumberOfEnemies(int a) {
	this->numberOfEnemiesOnMap = a;
}

bool EnemyCharacter::isPlayerOn(PlayerCharacter* player) { // get pos x, y, get pointer to obj of class player to give coins to inventory
	for (int i = 0; i < getNumberOfEnemies(); i++) {
		float x = player->getPos().x;
		float y = player->getPos().y;
		if (tiles[i]->pos.x == x && tiles[i]->pos.y == y) { //for each coin in vector tiles, checking if player is on this coin

			tiles.erase(tiles.begin() + i); //deleting the coin from vector
			setNumberOfEnemies(this->tiles.size()); //set the number of coins
			return true;
			//break; //if player was on the coin, then break loop
		}
	}
	return false;
}