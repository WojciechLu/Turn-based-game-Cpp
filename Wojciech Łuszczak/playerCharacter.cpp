#include "playerCharacter.h"
#include <iostream>

PlayerCharacter::PlayerCharacter(std::string textureName, float x, float y)
{
    if (!setUpSprite(textureName, &orginalTexture, &orginalSprite)) {
        return;
    }
    setPos(x, y);
    this->orginalSprite.setPosition(getPos()); //update the sprite's position
    setUpSprite(textureName, &orginalTexture, &orginalSprite); //setting the spire texture

    this->sprite.setPosition(getPos());
    setUpSprite(textureName, &texture, &sprite);

    setHP(20);
    setAD(6);
}

PlayerCharacter::PlayerCharacter(const PlayerCharacter &p1) {
    this->orginalTexture = p1.orginalTexture;
    this->texture = p1.texture;
    this->pos = p1.pos;
    this->orginalSprite = p1.orginalSprite;
    this->sprite = p1.sprite;
    this->HP = p1.HP;
    this->attackDamage = p1.attackDamage;
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


void PlayerCharacter::setCoins(int coins) {     //function to add coins to inventory
    this->coinsAmount += coins;
}
int PlayerCharacter::getCoins() const {
    return this->coinsAmount;
}

void PlayerCharacter::Move(std::string pressedKey) {
    float x = getPos().x;
    float y = getPos().y;
    if (pressedKey == "D")
    {
        setPos(x + 64, y);
        //pos = sf::Vector2f(pos.x + 64, pos.y); //moving player to right
        this->setUpSprite("images/character64.png", &texture, &sprite);
        this->sprite.setPosition(getPos());
        setSprite(this->sprite);
    }
    else if (pressedKey == "A")
    {
        setPos(x -+ 64, y);
        //pos = sf::Vector2f(pos.x - 64, pos.y); //moving player to left
        setUpSprite("images/character64left.png", &texture, &sprite);
        this->sprite.setPosition(getPos());
        setSprite(this->sprite);
    }
    else if (pressedKey == "W")
    {
        setPos(x, y - 64);
        //pos = sf::Vector2f(pos.x, pos.y - 64); //moving player to up
        this->sprite.setPosition(getPos());
        setSprite(this->sprite);
    }
    else if (pressedKey == "S")
    {
        setPos(x, y + 64);
        //pos = sf::Vector2f(pos.x, pos.y + 64); //moving player to down
        this->sprite.setPosition(getPos());
        setSprite(this->sprite);
    }
}

sf::Sprite PlayerCharacter::getOrginalSprite()
{
    return this->orginalSprite;
}
