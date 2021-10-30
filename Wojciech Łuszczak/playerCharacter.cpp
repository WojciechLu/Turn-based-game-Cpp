#include "playerCharacter.h"

PlayerCharacter::PlayerCharacter(std::string textureName, float x, float y) {
    if (!setUpSprite(textureName)) {
        return;
    }
    pos = sf::Vector2f(x, y); //setting vector of x and y position
    sprite.setPosition(pos); //update the sprite's position
    setUpSprite(textureName); //setting the spire texture
}

bool PlayerCharacter::setUpSprite(std::string textureName) {
    if (!texture.loadFromFile(textureName)) {
        return false;
    }

    texture.setSmooth(true); // antialysing
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0, 0, 64, 64)); //setting the texture size of 64x64
    return true;
}

float PlayerCharacter::getPosX() {
    return this->pos.x;
}
float PlayerCharacter::getPosY() {
    return this->pos.y;
}

int PlayerCharacter::getCoins() {
    return this->coinsAmount;
}

void PlayerCharacter::Move(std::string pressedKey) {
    if (pressedKey == "D")
    {
        pos = sf::Vector2f(pos.x + 64, pos.y); //moving player to right
        this->setUpSprite("images/character64.png");
        sprite.setPosition(pos);
    }
    else if (pressedKey == "A")
    {
        pos = sf::Vector2f(pos.x - 64, pos.y); //moving player to left
        this->setUpSprite("images/character64left.png");
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

void PlayerCharacter::AddCoins(int coins) {     //function to add coins to inventory
    this->coinsAmount += coins;
}
/*
void PlayerCharacter::SpendCoins(int price) {   //function to lose coins by buying
    this->coinsAmount -= price;

}
*/