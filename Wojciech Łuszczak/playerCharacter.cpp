#include "playerCharacter.h"
#include <iostream>

PlayerCharacter::PlayerCharacter(std::string textureName, float x, float y) {
    if (!setUpSprite(textureName, &orginalTexture, &orginalSprite)) {
        return;
    }
    pos = sf::Vector2f(x, y); //setting vector of x and y position
    orginalSprite.setPosition(pos); //update the sprite's position
    setUpSprite(textureName, &orginalTexture, &orginalSprite); //setting the spire texture

    sprite.setPosition(pos);
    setUpSprite(textureName, &texture, &sprite);
}

//bool PlayerCharacter::setUpSprite(std::string textureName) {
//    if (!this->texture.loadFromFile(textureName)) {
//        return false;
//    }
//
//    this->texture.setSmooth(true); // antialysing
//    this->sprite.setTexture(this->texture);
//    this->sprite.
//}

bool PlayerCharacter::setUpSprite(std::string textureName, sf::Texture* texture, sf::Sprite* sprite) { //load texture and set texture and textureRect
    if (!texture->loadFromFile(textureName)) {
        return false;
    }

    texture->setSmooth(true); // antialysing
    sprite->setTexture(*texture);
    sprite->setTextureRect(sf::IntRect(0, 0, 64, 64)); //setting the texture size of 64x64

    return true;
}


float PlayerCharacter::getPosX() const {
    return this->pos.x;
}
float PlayerCharacter::getPosY() const {
    return this->pos.y;
}
int PlayerCharacter::getHP() const {
    return this->HP;
}
int PlayerCharacter::getAttackDamage() const {
    return this->attackDamage;
}
sf::Texture PlayerCharacter::getTexture() const {
    return this->texture;
}

void PlayerCharacter::setSprite(sf::Sprite newSprite) {
    this->sprite = newSprite;
}

sf::Sprite PlayerCharacter::getOrginalSprite() const {
    return this->orginalSprite;
}
sf::Sprite PlayerCharacter::getSprite() const {
    return this->sprite;
}

void PlayerCharacter::setChoiceSkill(int a) {
    this->choiceSkill = a;
}
int PlayerCharacter::getChoiceSkill() const {
    return this->choiceSkill;
}

void PlayerCharacter::setCoins(int coins) {     //function to add coins to inventory
    this->coinsAmount += coins;
}
int PlayerCharacter::getCoins() const {
    return this->coinsAmount;
}

void PlayerCharacter::Move(std::string pressedKey) {
    if (pressedKey == "D")
    {
        pos = sf::Vector2f(pos.x + 64, pos.y); //moving player to right
        this->setUpSprite("images/character64.png", &texture, &sprite);
        sprite.setPosition(pos);
    }
    else if (pressedKey == "A")
    {
        pos = sf::Vector2f(pos.x - 64, pos.y); //moving player to left
        this->setUpSprite("images/character64left.png", &texture, &sprite);
        sprite.setPosition(pos);
    }
    else if (pressedKey == "W")
    {
        pos = sf::Vector2f(pos.x, pos.y - 64); //moving player to up
        sprite.setPosition(pos);
    }
    else if (pressedKey == "S")
    {
        pos = sf::Vector2f(pos.x, pos.y + 64); //moving player to down
        sprite.setPosition(pos);
    }
}

int PlayerCharacter::skill(int a) {
    switch (a) {
    case 0:
        return 0;
        break;
    case 1:
        return 1;
        break;
    case 2:
        return 2;
        break;
    case 3:
        return 3;
        break;
    default:
        return -1;
    }
}
//void PlayerCharacter::swordAttack() {
//    std::cout << "You chose sword attack" << std::endl;
//}
//
//void PlayerCharacter::block() {
//    std::cout << "You chose block" << std::endl;
//
//}
//void PlayerCharacter::aim() {
//    std::cout << "You chose aim" << std::endl;
//
//}
//void PlayerCharacter::bash() {
//    std::cout << "You chose bash" << std::endl;
//}