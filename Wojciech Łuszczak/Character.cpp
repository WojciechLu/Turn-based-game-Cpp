#include "Character.h"

float Character::getPosX() {
	return this->pos.x;
}

void Character::setPosX(int x) {
	this->pos.x = x;
}

float Character::getPosY() {
	return this->pos.y;
}

void Character::setPosY(int y) {
	this->pos.y = y;
}

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