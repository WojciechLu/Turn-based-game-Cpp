#include "playerCharacter.h"
#include <iostream>



//bool PlayerCharacter::setUpSprite(std::string textureName) {
//    if (!this->texture.loadFromFile(textureName)) {
//        return false;
//    }
//
//    this->texture.setSmooth(true); // antialysing
//    this->sprite.setTexture(this->texture);
//    this->sprite.
//}


PlayerCharacter::PlayerCharacter(std::string textureName, float x, float y, int HP, int DMG)
{
    if (!setUpSprite(textureName, &orginalTexture, &orginalSprite)) {
        return;
    }
    setPos(x, y);
    orginalSprite.setPosition(getPos()); //update the sprite's position
    setUpSprite(textureName, &orginalTexture, &orginalSprite); //setting the spire texture

    sprite.setPosition(getPos());
    setUpSprite(textureName, &texture, &sprite);
}

PlayerCharacter::PlayerCharacter(PlayerCharacter &p1) {
    this->orginalTexture = p1.texture;
    this->texture = this->orginalTexture;
    setPos(p1.getPos().x, p1.getPos().y);
    setSprite(p1.getSprite());
    this->orginalSprite = getSprite();
    setHP(p1.getHP());
    setAD(p1.getAD());
}

bool PlayerCharacter::setUpSprite(std::string textureName, sf::Texture* texture, sf::Sprite* sprite) { //load texture and set texture and textureRect
    if (!texture->loadFromFile(textureName)) {
        return false;
    }

    texture->setSmooth(true); // antialysing
    sprite->setTexture(*texture);
    sprite->setTextureRect(sf::IntRect(0, 0, 64, 64)); //setting the texture size of 64x64
    setSprite(this->sprite);
    return true;
}


//float PlayerCharacter::getPosX() const {
//    return this->pos.x;
//}
//float PlayerCharacter::getPosY() const {
//    return this->pos.y;
//}
//int PlayerCharacter::getHP() const {
//    return this->HP;
//}

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
    int x = getPos().x;
    int y = getPos().y;
    if (pressedKey == "D")
    {
        setPos(x + 64, y);
        //pos = sf::Vector2f(pos.x + 64, pos.y); //moving player to right
        this->setUpSprite("images/character64.png", &texture, &sprite);
        sprite.setPosition(getPos());
        setSprite(this->sprite);
    }
    else if (pressedKey == "A")
    {
        setPos(x -+ 64, y);
        //pos = sf::Vector2f(pos.x - 64, pos.y); //moving player to left
        this->setUpSprite("images/character64left.png", &texture, &sprite);
        sprite.setPosition(getPos());
        setSprite(this->sprite);
    }
    else if (pressedKey == "W")
    {
        setPos(x, y - 64);
        //pos = sf::Vector2f(pos.x, pos.y - 64); //moving player to up
        sprite.setPosition(getPos());
        setSprite(this->sprite);
    }
    else if (pressedKey == "S")
    {
        setPos(x, y + 64);
        //pos = sf::Vector2f(pos.x, pos.y + 64); //moving player to down
        sprite.setPosition(getPos());
        setSprite(this->sprite);
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