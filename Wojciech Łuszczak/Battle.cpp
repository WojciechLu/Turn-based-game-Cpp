#include "Battle.h"
#include <iostream>

Battle::Battle(PlayerCharacter player) {  //constructor, get player and enemy informations and setting to battle class
    actionsMenu("images/actionMenu/attackSwordsman/interface.png");
    setPlayer(player);
    sf::IntRect bg(0, 0, 576, 576);
    setUpBackground("images/battle/background.png", bg);
    //setEnemy(enemy);
}

void Battle::setPlayer(PlayerCharacter player) { //setting player data in constructor
    spritePlayer = player.getOrginalSprite();
    texturePlayer = player.getTexture();
    spritePlayer.setPosition(3 * 64, 3 * 64);

    playerHP = player.getHP();
}
void Battle::setEnemy(EnemyCharacter enemy) { //setting enemy data in constructor
    spriteEnemy = enemy.getSprite();
    textureEnemy = enemy.getTexture();
    spriteEnemy.setPosition(5 * 64, 3 * 64);

    enemyHP = enemy.getHP();
}
void Battle::setPlayerHP(int a) { //setting playerHP to current
    playerHP = a;
}
void Battle::setEnemyHP(int a) {
    enemyHP = a;
}

//opisaæ dobrze
void Battle::setUpBackground(std::string textureName, sf::IntRect rect) {
    if (!setUpSprite(textureName, rect, &this->textureBg, &this->spriteBg)) {
        return;
    }
    this->spriteBg.setPosition(sf::Vector2f(0, 0)); //update the sprite's position
    setUpSprite(textureName, rect, &this->textureBg, &this->spriteBg); //setting the sprite texture
}

//opisaæ dobrze
void Battle::actionsMenu(std::string textureName) { //setting texture and then using setUpSprite to set sprite
    int width = 64 * 4;
    sf::IntRect rect(this->attackChoice * width, 0, width, 64);
    if (!setUpSprite(textureName, rect, &textureActionsMenu, &spriteActionsMenu)) {
        return;
    }
    this->posActionsMenu = sf::Vector2f(2.5 * 64, 6 * 64); //setting vector of x and y position
    this->spriteActionsMenu.setPosition(this->posActionsMenu); //update the sprite's position
    setUpSprite(textureName, rect, &textureActionsMenu, &spriteActionsMenu); //setting the sprite texture
}

//NIE ZJEBAÆ OPISU FUNKCJI, NIE POWALIÆ SIÊ W &, * ORAZ ->
bool Battle::setUpSprite(std::string textureName, sf::IntRect size, sf::Texture* texture, sf::Sprite* sprite) { //load texture and set texture and textureRect
    if (!texture->loadFromFile(textureName)) {
        return false;
    }

    texture->setSmooth(true); // antialysing
    sprite->setTexture(*texture);
    sprite->setTextureRect(size); //setting the texture size of 64x64

    return true;
}

void Battle::playerAttack(int a) {
    if (a > 0) {
        if (a >= enemyHP) {
            std::cout << "DMAGE: " << a << std::endl;
            setEnemyHP(0);
            std::cout << "HP: " << enemyHP << std::endl;

        }
        else {
            setEnemyHP(enemyHP - a);
            std::cout << "enemy HP: " << enemyHP << std::endl;
        }
    }
    else {
        std::cout << "Missed \n";
    }
}

void Battle::checkWin() {
    if (enemyHP == 0) {
        this->battleResult = 1;   //player won
        std::cout << battleResult << std::endl;
    }
    else if (playerHP == 0) {
        this->battleResult = -1;  //enemy won
        std::cout << battleResult << std::endl;
    }
}

//public functions
void Battle::chooseAction(char key, PlayerCharacter player, Attack* attack, WindowGame* m_window) { //changing texture sprite to next or previous attack, used in StartGame
    if (key == 'A') {
        if (this->attackChoice == 0) {
            this->attackChoice = 3;
            //player.setChoiceSkill(attackChoice); //setting the number 0-4, depends on the chosen action
        }
        else {
            this->attackChoice--;
            //player.setChoiceSkill(attackChoice);
        }
        actionsMenu("images/actionMenu/attackSwordsman/interface.png"); //update the choice of attack
    }
    else if (key == 'D') {
        if (this->attackChoice == 3) {
            this->attackChoice = 0;
            //player.setChoiceSkill(attackChoice);
        }
        else {
            this->attackChoice++;
            //player.setChoiceSkill(attackChoice);
        }
        actionsMenu("images/actionMenu/attackSwordsman/interface.png"); //update the choice of attack
    }
    else if (key == 'E') {
        int damageDealt = attack->doAttack(attackChoice, player.getAttackDamage(), this->spriteEnemy.getPosition()); //giving the number of chosen attack and posiotion to (chosen) enemy then recive damage dealt
        playerAttack(damageDealt);
        attack->animation(m_window); //making animation based on the above data
        checkWin();
    }
}

//getters functions to return private variables outside class
sf::Sprite Battle::getSpriteMenu() const{
    return this->spriteActionsMenu;
}
sf::Sprite Battle::getSpritePlayer() const{
    return this->spritePlayer;
}
sf::Sprite Battle::getSpriteEnemy() const{
    return this->spriteEnemy;
}
sf::Sprite Battle::getSpriteAttack() const{
    return this->attackSprite;
}
sf::Sprite Battle::getSpriteBg() const{
    return this->spriteBg;
}
int Battle::getPlayerHP() const{
    return this->playerHP;
}
int Battle::getEnemyHP() const{
    return this->enemyHP;
}
int Battle::getBattleResult() const{
    return this->battleResult;
}
