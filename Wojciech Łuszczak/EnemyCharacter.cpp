#include "EnemyCharacter.h"

EnemyCharacter::EnemyCharacter(std::string textureName, float x, float y) { //constructor: set texture, and x, y
	if (!setUpSprite(textureName)) {
		return;
	}
	pos = sf::Vector2f(x, y); //setting vector of x and y position
	sprite.setPosition(pos); //update the sprite's position
	setUpSprite(textureName); //setting the spire texture

	setHP(20);
	setAD(5);
} 

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