#include "Character.h"

sf::Vector2f Character::getPos() {
	return this->pos;
}

void Character::setPos(int x, int y) {
	this->pos = sf::Vector2f(x, y); //setting vector of x and y position
}

//float Character::getPosX() {
//	return this->pos.x;
//}
//
//void Character::setPosX(int x) {
//	this->pos.x = x;
//}
//
//float Character::getPosY() {
//	return this->pos.y;
//}
//
//void Character::setPosY(int y) {
//	this->pos.y = y;
//}

int Character::getHP() {
	return this->HP;
}

void Character::setHP(int a) {
	this->HP = a;
}

int Character::getAD() {
	return this->attackDamage;
}

void Character::setAD(int a) {
	this->attackDamage = a;
}

bool Character::setUpSprite(std::string textureName) { //set texture to sprite
	if (!texture.loadFromFile(textureName)) {
		return false;
	}

	texture.setSmooth(true); // antialysing
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(0, 0, 64, 64)); //setting the texture size of 64x64
	return true;
}