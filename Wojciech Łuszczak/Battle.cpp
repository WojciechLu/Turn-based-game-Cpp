#include "Battle.h"
#include <iostream>

Battle::Battle(PlayerCharacter player, EnemyCharacter enemy) {  //constructor, get player and enemy informations and setting to battle class
    actionsMenu("images/actionMenu/attackSwordsman/interface.png", 2.5 * 64, 6 * 64);
    setPlayer(player);
    setEnemy(enemy);
}

void Battle::setPlayer(PlayerCharacter player) { //setting player data in constructor
    spritePlayer = player.getSprite();
    texturePlayer = player.getTexture();
    spritePlayer.setPosition(3 * 64, 3 * 64);
}

void Battle::setEnemy(EnemyCharacter enemy) { //setting enemy data in constructor
    spriteEnemy = enemy.getSprite();
    textureEnemy = enemy.getTexture();
    spriteEnemy.setPosition(5 * 64, 3 * 64);
}

void Battle::actionsMenu(std::string textureName, float x, float y) { //setting texture and then using setUpSprite to set sprite
    if (!setUpSpriteActionsMenu(textureName)) {
        return;
    }
    posActionsMenu = sf::Vector2f(x, y); //setting vector of x and y position
    spriteActionsMenu.setPosition(posActionsMenu); //update the sprite's position
    setUpSpriteActionsMenu(textureName); //setting the sprite texture
}

bool Battle::setUpSpriteActionsMenu(std::string textureName) { //load texture and set texture and textureRect
    if (!textureActionsMenu.loadFromFile(textureName)) {
        return false;
    }

    textureActionsMenu.setSmooth(true); // antialysing
    spriteActionsMenu.setTexture(textureActionsMenu);
    spriteActionsMenu.setTextureRect(sf::IntRect(this->attackChoice * 64 * 4, 0, 64 * 4, 64)); //setting the texture size of 64x64

    return true;
}

//getters functions to return private variables outside class
sf::Sprite Battle::getSpriteMenu() {
    return this->spriteActionsMenu;
}
sf::Sprite Battle::getSpritePlayer() {
    return this->spritePlayer;
}
sf::Sprite Battle::getSpriteEnemy() {
    return this->spriteEnemy;
}
sf::Sprite Battle::getSpriteAttack() {
    return this->attackSprite;
}

void Battle::chooseAction(char key, PlayerCharacter player, Attack *attack, WindowGame *m_window) { //changing texture sprite to next or previous attack, used in StartGame
    if (key == 'A') {
        if (this->attackChoice == 0) {
            this->attackChoice = 3;
            player.setChoiceSkill(attackChoice); //setting the number 0-4, depends on the chosen action
        }
        else {
            this->attackChoice--;
            player.setChoiceSkill(attackChoice);
        }
        setUpSpriteActionsMenu("images/actionMenu/attackSwordsman/interface.png"); //update the choice of attack
    }
    else if (key == 'D') {
        if (this->attackChoice == 3) {
            this->attackChoice = 0;
            player.setChoiceSkill(attackChoice);
        }
        else {
            this->attackChoice++;
            player.setChoiceSkill(attackChoice);
        }
        setUpSpriteActionsMenu("images/actionMenu/attackSwordsman/interface.png"); //update the choice of attack
    }
    else if (key == 'E') {
        attack->doAttack(player.skill(attackChoice), this->spriteEnemy.getPosition()); //getting the number of chosen attack and posiotion to (chosen) enemy
        attack->animation(m_window); //making animation based on the above data
    }
}
