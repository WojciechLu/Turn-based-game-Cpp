#include "Attack.h"
#include <iostream>

Attack::Attack() {
	setUpInitial("", 0, 0);
}

sf::Sprite Attack::getSprite() {
	return this->spriteAttack;
}
sf::Texture Attack::getTexture() {
	return this->textureAttack;
}

void Attack::doAttack(int a, sf::Vector2f pos){ //in the future switch(a) to set adequate texture path, set postion where should be displeyed
	setUpInitial("images/attackAnimation/swordAttack.png", pos.x, pos.y);
}

void Attack::setUpInitial(std::string textureName, float x, float y) {
	if (!setUpSprite(textureName)) {
		return;
	}
	this->posAttack = sf::Vector2f(x, y);
	this->spriteAttack.setPosition(this->posAttack); //update the sprite's position
	setUpSprite(textureName); //setting the sprite texture
}

bool Attack::setUpSprite(std::string textureName){
	if (!textureAttack.loadFromFile(textureName)) {
		return false;
	}

	this->textureAttack.setSmooth(true); // antialysing
	this->spriteAttack.setTexture(this->textureAttack);
	this->spriteAttack.setTextureRect(sf::IntRect(0, 0, 64, 64)); //setting the texture size of 64x64
	return true;
}

//				TO DO!!!
//				  !!!!
void Attack::animation(WindowGame* m_window) { //repair in the future 
	sf::Clock clock;
	sf::IntRect rectSourceSprite(0, 0, 64, 64);
	sf::Sprite sprite(textureAttack, rectSourceSprite);
	sprite.setPosition(spriteAttack.getPosition());
	rectSourceSprite.left = 0;

	spriteAnimation.clear();

	for (int i = 0; i < 7; i++) {
		sprite.setTextureRect(rectSourceSprite);
		spriteAnimation.push_back(sprite);
		rectSourceSprite.left += 64;
	}

	//m_window->window.draw(spriteAnimation[0]);
	for (int i = 1; i < 7; i++) {
		//if (clock.getElapsedTime().asSeconds() > 0.05f) {
		//	//spriteAnimation.erase(spriteAnimation.begin());
		//	clock.restart();
		//}
		//spriteAnimation[i-1].setColor(sf::Color::Transparent);
		//m_window->window.draw(spriteAnimation[i-1]);
		m_window->window.draw(spriteAnimation[i]);
		m_window->window.display();
	}
	setUpInitial("images/attackAnimation/blank.png", spriteAttack.getPosition().x, spriteAttack.getPosition().y);

}