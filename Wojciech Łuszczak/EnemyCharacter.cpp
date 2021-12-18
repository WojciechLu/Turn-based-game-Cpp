#include "EnemyCharacter.h"

EnemyCharacter::EnemyCharacter(std::string textureName, float x, float y) { //constructor: set texture, and x, y
	if (!setUpSprite(textureName)) {
		return;
	}
	pos = sf::Vector2f(x, y); //setting vector of x and y position
	sprite.setPosition(pos); //update the sprite's position
	setUpSprite(textureName); //setting the spire texture
} 

EnemyCharacter::EnemyCharacter(const EnemyCharacter& e1) {
	return;
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



void EnemyCharacter::isPlayerOn(PlayerCharacter* player, StateMachine* state) { // get pos x, y, get pointer to obj of class player to give coins to inventory
	//if(pos.x == player->getPos().x && pos.y == player->getPos().y){
	if (pos == player->getPos()) {
		state->world2Battle();
	}
}