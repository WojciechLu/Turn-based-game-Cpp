#include "EnemyCharacter.h"

EnemyCharacter::EnemyCharacter(std::string textureName, float x, float y) { //constructor: set texture, and x, y
	if (!setUpSprite(textureName)) {
		return;
	}
	pos = sf::Vector2f(x, y); //setting vector of x and y position
	sprite.setPosition(pos); //update the sprite's position
	setUpSprite(textureName); //setting the spire texture
} 

bool EnemyCharacter::setUpSprite(std::string textureName) { //set texture to sprite
	if (!texture.loadFromFile(textureName)) {
		return false;
	}

	texture.setSmooth(true); // antialysing
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(0, 0, 64, 64)); //setting the texture size of 64x64
	return true;
}	

float EnemyCharacter::getPosX() {
	return this->pos.x;
}

float EnemyCharacter::getPosY() {
	return this->pos.y;
}

int EnemyCharacter::getHP() {
	return this->HP;
}

void EnemyCharacter::setHP(int a) {
	this->HP = a;
}

int EnemyCharacter::getAD() {
	return this->attackDamage;
}

void EnemyCharacter::setAD(int a) {
	this->attackDamage = a;
}

sf::Texture EnemyCharacter::getTexture() {
	return this->texture;
}

void EnemyCharacter::setTexture(sf::Texture newTexture) {
	this->texture = newTexture;
}

void EnemyCharacter::setSprite(sf::Sprite newSprite) {
	this->sprite = newSprite;
}
sf::Sprite EnemyCharacter::getSprite() {
	return this->sprite;
}