#include "Battle.h"
#include <iostream>

Battle::Battle(PlayerCharacter player, EnemyCharacter enemy) {
    actionsMenu("images/actionMenu/interface.png", 2.5 * 64, 6 * 64);
    setPlayer(player);
    setEnemy(enemy);
}

void Battle::setPlayer(PlayerCharacter player) {
    spritePlayer = player.getSprite();
    texturePlayer = player.getTexture();
    spritePlayer.setPosition(3 * 64, 3 * 64);
}

void Battle::setEnemy(EnemyCharacter enemy) {
    spriteEnemy = enemy.getSprite();
    textureEnemy = enemy.getTexture();
    spriteEnemy.setPosition(5 * 64, 3 * 64);
}

void Battle::actionsMenu(std::string textureName, float x, float y) {
    if (!setUpSpriteActionsMenu(textureName)) {
        return;
    }
    posActionsMenu = sf::Vector2f(x, y); //setting vector of x and y position
    spriteActionsMenu.setPosition(posActionsMenu); //update the sprite's position
    setUpSpriteActionsMenu(textureName); //setting the sprite texture
}

bool Battle::setUpSpriteActionsMenu(std::string textureName) {
    if (!textureActionsMenu.loadFromFile(textureName)) {
        return false;
    }

    textureActionsMenu.setSmooth(true); // antialysing
    spriteActionsMenu.setTexture(textureActionsMenu);
    spriteActionsMenu.setTextureRect(sf::IntRect(this->attackChoice * 64 * 4, 0, 64 * 4, 64)); //setting the texture size of 64x64

    return true;
}

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

void Battle::chooseAction(char key, PlayerCharacter player, Attack *attack, windowGame *m_window) {
    if (key == 'A') {
        if (this->attackChoice == 0) {
            this->attackChoice = 3;
            player.setChoiceSkill(attackChoice);
        }
        else {
            this->attackChoice--;
            player.setChoiceSkill(attackChoice);
        }
        setUpSpriteActionsMenu("images/actionMenu/interface.png"); //update the choice of attack
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
        setUpSpriteActionsMenu("images/actionMenu/interface.png"); //update the choice of attack
    }
    else if (key == 'E') {
        attack->doAttack(player.skill(attackChoice), this->spriteEnemy.getPosition());
        attack->animation(m_window);
    }
}
