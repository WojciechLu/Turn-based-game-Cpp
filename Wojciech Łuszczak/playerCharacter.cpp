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

    texture.setSmooth(true); // tu nie wiem co jest
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0, 0, 64, 64)); //setting the texture size of 64x64
    return true;
}

void PlayerCharacter::Move(std::string pressedKey) {
    if (pressedKey == "D")
    {
        pos = sf::Vector2f(pos.x + 64, pos.y); //moving player to right
        sprite.setPosition(pos);
    }
    else if (pressedKey == "A")
    {
        pos = sf::Vector2f(pos.x - 64, pos.y); //moving player to left
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
