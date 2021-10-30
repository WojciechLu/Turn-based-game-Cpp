#include "Battle.h"
#include <iostream>

Battle::Battle() {
    actionsPlayer("images/chooseAction/interface.png", 2.5 * 64, 6 * 64);
}

void Battle::actionsPlayer(std::string textureName, float x, float y) {
    if (!setUpSpriteActionsPlayer(textureName)) {
        return;
    }
    posActionsPlayer = sf::Vector2f(x, y); //setting vector of x and y position
    spriteActionsPlayer.setPosition(posActionsPlayer); //update the sprite's position
    setUpSpriteActionsPlayer(textureName); //setting the spire texture
}

bool Battle::setUpSpriteActionsPlayer(std::string textureName) {
    if (!textureActionsPlayer.loadFromFile(textureName)) {
        return false;
    }

    textureActionsPlayer.setSmooth(true); // antialysing
    spriteActionsPlayer.setTexture(textureActionsPlayer);
    setUpAttackChoice();
    return true;
}

void Battle::setUpAttackChoice() {
    spriteActionsPlayer.setTextureRect(sf::IntRect(this->attackChoice * 64 * 4, 0, 64 * 4, 64)); //setting the texture size of 64x64
}

void Battle::updateSpriteAttackChoice() {
    setUpSpriteActionsPlayer("images/chooseAction/interface.png");
}

void Battle::chooseAction(char key) {
    if (key == 'A') {
        if (this->attackChoice == 0) {
            this->attackChoice = 3;
            
        }
        else {
            this->attackChoice--;
        }
        updateSpriteAttackChoice();
    }
    else if (key == 'D') {
        if (this->attackChoice == 3) {
            this->attackChoice = 0;
        }
        else {
            this->attackChoice++;
        }
        updateSpriteAttackChoice();
    }
}