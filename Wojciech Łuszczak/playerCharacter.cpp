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
    int x = getPos().x;
    int y = getPos().y;
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

bool PlayerCharacter::isPlayerOnEnemy(EnemyCharacter enemy, StateMachine* state)
{
    if (this->pos == enemy.getPos()) {  //checking if player is on any enemy
        std::cout << "Stepped on sth";
        state->world2Battle();          //turning state to battle
        return true;                    //returning true because player is on enemy
    }
    else return false;                  //returning false because player isnt on enemy
}

sf::Sprite PlayerCharacter::getOrginalSprite()
{
    return this->orginalSprite;
}

//int PlayerCharacter::skill(int a) {
//    switch (a) {
//    case 0:
//        return 0;
//        break;
//    case 1:
//        return 1;
//        break;
//    case 2:
//        return 2;
//        break;
//    case 3:
//        return 3;
//        break;
//    default:
//        return -1;
//    }
//}
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