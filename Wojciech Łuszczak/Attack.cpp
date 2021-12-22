#include "Attack.h"
#include <iostream>
#include <cstdlib>

int Attack::SwordAttack(int a) {
	srand(time(NULL));
	int missed = rand() % 5;
	int crit = 1 + rand() % 100;

	if (missed == 0) {
		return -1;
	}
	else {
		if (crit > 90) {
			return 1.5 * a;
		}
		else {
			return a;
		}
	}
}

int Attack::BlockSkill() {
	return -2;
}

int Attack::PowerBuff()
{
	srand(time(NULL));
	int crit = rand() % 5;
	if (crit == 0) {
		return -4;
	}
	else return -3;
}

int Attack::BashAttack(int a) {
	srand(time(NULL));
	int missed = rand() % 3;
	int crit = 1 + rand() % 100;

	if (missed == 0) {
		return -1;
	}
	else {
		if (crit > 70) {
			return 2 * a;
		}
		else {
			return 0.5 * a;
		}
	}
}

Attack::Attack() {
	setUpInitial("", 0, 0);
}

sf::Sprite Attack::getSprite() {
	return this->spriteAttack;
}
sf::Texture Attack::getTexture() {
	return this->textureAttack;
}

int Attack::doAttack(int a, int ad, sf::Vector2f pos){ //set postion where should be displeyed, get attack damage
	switch (a) {
	case 0:
		std::cout << "You chose sword attack" << std::endl;
		return SwordAttack(ad);
		break;
	case 1:
		std::cout << "You chose block" << std::endl;
		return BlockSkill();
		break;
	case 2:
		std::cout << "You chose buff" << std::endl;
		return PowerBuff();
		break;
	case 3:
		std::cout << "You chose bash" << std::endl;
		return BashAttack(ad);
		break;
	// case 4, case 5, ...
	}
	setUpInitial("images/attackAnimation/swordAttack.png", pos.x, pos.y);
	return -1;
}

int Attack::doAttackEnemy(int ad, sf::Vector2f pos)
{
	srand(time(NULL));
	int missed = rand() % 5;
	int crit = 1 + rand() % 100;

	if (missed == 0) {
		return -1;
	}
	else {
		if (crit > 90) {
			return 1.5 * ad;
		}
		else {
			return ad;
		}
	}
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
//void Attack::animation(WindowGame* m_window) { //repair in the future 
//	sf::Clock clock;
//	sf::IntRect rectSourceSprite(0, 0, 64, 64);
//	sf::Sprite sprite(textureAttack, rectSourceSprite);
//	sprite.setPosition(spriteAttack.getPosition());
//	rectSourceSprite.left = 0;s
//
//	spriteAnimation.clear();
//
//	for (int i = 0; i < 7; i++) {
//		sprite.setTextureRect(rectSourceSprite);
//		spriteAnimation.push_back(sprite);
//		rectSourceSprite.left += 64;
//	}
//
//	//m_window->window.draw(spriteAnimation[0]);
//	for (int i = 1; i < 7; i++) {
//		//if (clock.getElapsedTime().asSeconds() > 0.05f) {
//		//	//spriteAnimation.erase(spriteAnimation.begin());
//		//	clock.restart();
//		//}
//		//spriteAnimation[i-1].setColor(sf::Color::Transparent);
//		//m_window->window.draw(spriteAnimation[i-1]);
//		m_window->window.draw(spriteAnimation[i]);
//		m_window->window.display();
//	}
//	setUpInitial("images/attackAnimation/blank.png", spriteAttack.getPosition().x, spriteAttack.getPosition().y);
//
//}