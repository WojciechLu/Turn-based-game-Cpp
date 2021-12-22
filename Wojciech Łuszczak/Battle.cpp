#include "Battle.h"
#include "playerCharacter.h"
#include "EnemyCharacter.h"
#include <iostream>
#include <math.h>

void Battle::setUpBackground(std::string textureName, sf::IntRect rect) {
    if (!setUpSprite(textureName, rect, this->textureBg, &this->spriteBg)) {
        return;
    }
    this->spriteBg.setPosition(sf::Vector2f(0, 0)); //update the sprite's position
    setUpSprite(textureName, rect, this->textureBg, &this->spriteBg); //setting the sprite texture
}

bool Battle::setUpSprite(std::string textureName, sf::IntRect size, sf::Texture &texture, sf::Sprite* sprite) { //load texture and set texture and textureRect
    if (!texture.loadFromFile(textureName)) {
        return false;
    }

    texture.setSmooth(true); // antialysing
    sprite->setTexture(texture);
    sprite->setTextureRect(size); //setting the texture size of 64x64

    return true;
}

void Battle::playerAttack(int a) {
    if (a > 0) {
        if (a >= this->enemy->getHP()) {
            std::cout << "Player DMAGE: " << a << std::endl;
            enemy->setHP(0);
            std::cout << "Enemy HP: " << this->enemy->getHP() << std::endl;

        }
        else {
            std::cout << "Player DMAGE: " << a << std::endl;
            enemy->setHP(this->enemy->getHP() - a);
            std::cout << "Enemy HP: " << this->enemy->getHP() << std::endl;
        }
    }
    else if (a == -1) {
        std::cout << "Missed \n";
    }
    else if (a == -2) {
        std::cout << "Shield \n";
        this->isShieldOn = true;
    }
    else if (a == -3) {
        this->player->setAD(floor(player->getAD() * 1.8));
    }
    else if (a == -4) {
        this->player->setAD(floor(player->getAD() * 2));
    }
}

void Battle::actionsMenu(std::string textureName) { //setting texture and then using setUpSprite to set sprite
    int width = 64 * 4;
    sf::IntRect rect(this->attackChoice * width, 0, width, 64);
    if (!setUpSprite(textureName, rect, textureActionsMenu, &spriteActionsMenu)) {
        return;
    }
    this->posActionsMenu = sf::Vector2f(2.5 * 64, 6 * 64); //setting vector of x and y position
    this->spriteActionsMenu.setPosition(this->posActionsMenu); //update the sprite's position
    setUpSprite(textureName, rect, textureActionsMenu, &spriteActionsMenu); //setting the sprite texture
}

void Battle::checkWin() {
    if (this->enemy->getHP() == 0) {
        this->battleResult = 1;   //player won
        std::cout << this->battleResult << std::endl;
    }
    else if (this->player->getHP() == 0) {
        this->battleResult = -1;  //enemy won
        std::cout << this->battleResult << std::endl;
    }
}

void Battle::enemyAttack(int a)
{
    if (a == -1) {
        std::cout << "Missed \n";
    }
    else {
        if (this->isShieldOn) {
            this->isShieldOn = false;
        }
        else {
            if (a >= this->player->getHP()) {
                std::cout << "Enemy DMAGE: " << a << std::endl;
                player->setHP(0);
                std::cout << "Player HP: " << this->player->getHP() << std::endl;
            }
            else {
                std::cout << "Enemy DMAGE: " << a << std::endl;
                player->setHP(this->player->getHP() - a);
                std::cout << "Player HP: " << this->player->getHP() << std::endl;
            }
        }
    }
}
//void Battle::chooseAction(char key, PlayerCharacter player, Attack* attack, WindowGame* m_window); //changing texture sprite to next or previous attack, used in StartGame
void Battle::chooseAction(char key, PlayerCharacter player, Attack* attack) { //changing texture sprite to next or previous attack, used in StartGame
    if (key == 'A') {
        if (this->attackChoice == 0) {
            this->attackChoice = 3;
            player.setChoiceSkill(attackChoice); //setting the number 0-4, depends on the chosen action
        }
        else {
            this->attackChoice--;
            player.setChoiceSkill(attackChoice);
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
        int damageDealt = attack->doAttack(attackChoice, player.getAD(), this->enemy->getSprite().getPosition()); //giving the number of chosen attack and posiotion to (chosen) enemy then recive damage dealt
        playerAttack(damageDealt);
        //attack->animation(m_window); //making animation based on the above data
        checkWin();
        if (this->battleResult == 1) {
            return;
        }
        sf::Clock clock;
        while (1) {
            if (float time = clock.getElapsedTime() > sf::seconds(0.5f)) {
                break;
            }
        }
        damageDealt = attack->doAttackEnemy(enemy->getAD(), this->player->getSprite().getPosition());
        enemyAttack(damageDealt);
        checkWin();
    }
    std::cout << "SkillChoice: " << this->attackChoice << std::endl;
}

Battle::Battle(PlayerCharacter &playerPattern, EnemyCharacter &enemyPattern)
	:player(&playerPattern), enemy(&enemyPattern){ //wywo³anie konstruktorów kopiuj¹cych dla pól prywatnych klasy bitwy: PlayerCharacter player, EnemyCharacter enemy
   
	this->playerTurn = true; 
    this->battleResult = 0;
    actionsMenu("images/actionMenu/attackSwordsman/interface.png");
    //this->attackChoice = 1;
    sf::IntRect bg(0, 0, 576, 576);
    setUpBackground("images/battle/background.png", bg);
    this->player->setPos(3 * 64, 3 * 64);
    this->enemy->setPos(5 * 64, 3 * 64);
}


sf::Sprite Battle::getSpriteMenu() const
{
    return this->spriteActionsMenu;
}

sf::Sprite Battle::getSpriteAttack() const
{
    return this->attackSprite;
}

sf::Sprite Battle::getSpriteBg() const
{
    return this->spriteBg;
}

int Battle::getBattleResult() const
{
    return this->battleResult;
}


//Battle::Battle(PlayerCharacter player) {  //constructor, get player and enemy informations and setting to battle class
//    actionsMenu("images/actionMenu/attackSwordsman/interface.png");
//    setPlayer(player);
//    sf::IntRect bg(0, 0, 576, 576);
//    setUpBackground("images/battle/background.png", bg);
//    //setEnemy(enemy);
//}
//
//void Battle::setPlayer(PlayerCharacter player) { //setting player data in constructor
//    spritePlayer = player.getOrginalSprite();
//    texturePlayer = player.getTexture();
//    spritePlayer.setPositionada(3 * 64, 3 * 64);
//
//    playerHP = player.getHP();
//}
//void Battle::setEnemy(EnemyCharacter enemy) { //setting enemy data in constructor
//    spriteEnemy = enemy.getSprite();
//    textureEnemy = enemy.getTexture();
//    spriteEnemy.setPosition(5 * 64, 3 * 64);
//
//    enemyHP = enemy.getHP();
//}
//void Battle::setPlayerHP(int a) { //setting playerHP to current
//    playerHP = a;
//}
//void Battle::setEnemyHP(int a) {
//    enemyHP = a;
//}
//
////opisaæ dobrze

//
////opisaæ dobrze
//void Battle::actionsMenu(std::string textureName) { //setting texture and then using setUpSprite to set sprite
//    int width = 64 * 4;
//    sf::IntRect rect(this->attackChoice * width, 0, width, 64);
//    if (!setUpSprite(textureName, rect, &textureActionsMenu, &spriteActionsMenu)) {
//        return;
//    }
//    this->posActionsMenu = sf::Vector2f(2.5 * 64, 6 * 64); //setting vector of x and y position
//    this->spriteActionsMenu.setPosition(this->posActionsMenu); //update the sprite's position
//    setUpSprite(textureName, rect, &textureActionsMenu, &spriteActionsMenu); //setting the sprite texture
//}
//
////NIE ZJEBAÆ OPISU FUNKCJI, NIE POWALIÆ SIÊ W &, * ORAZ ->

//

//
//void Battle::checkWin() {
//    if (enemyHP == 0) {
//        this->battleResult = 1;   //player won
//        std::cout << battleResult << std::endl;
//    }
//    else if (playerHP == 0) {
//        this->battleResult = -1;  //enemy won
//        std::cout << battleResult << std::endl;
//    }
//}
//
////public functions
//void Battle::chooseAction(char key, PlayerCharacter player, Attack* attack, WindowGame* m_window) { //changing texture sprite to next or previous attack, used in StartGame
//    if (key == 'A') {
//        if (this->attackChoice == 0) {
//            this->attackChoice = 3;
//            //player.setChoiceSkill(attackChoice); //setting the number 0-4, depends on the chosen action
//        }
//        else {
//            this->attackChoice--;
//            //player.setChoiceSkill(attackChoice);
//        }
//        actionsMenu("images/actionMenu/attackSwordsman/interface.png"); //update the choice of attack
//    }
//    else if (key == 'D') {
//        if (this->attackChoice == 3) {
//            this->attackChoice = 0;
//            //player.setChoiceSkill(attackChoice);
//        }
//        else {
//            this->attackChoice++;
//            //player.setChoiceSkill(attackChoice);
//        }
//        actionsMenu("images/actionMenu/attackSwordsman/interface.png"); //update the choice of attack
//    }
//    else if (key == 'E') {
//        int damageDealt = attack->doAttack(attackChoice, player.getAttackDamage(), this->spriteEnemy.getPosition()); //giving the number of chosen attack and posiotion to (chosen) enemy then recive damage dealt
//        playerAttack(damageDealt);
//        attack->animation(m_window); //making animation based on the above data
//        checkWin();
//    }
//}
//
////getters functions to return private variables outside class
//sf::Sprite Battle::getSpriteMenu() const{
//    return this->spriteActionsMenu;
//}
//sf::Sprite Battle::getSpritePlayer() const{
//    return this->spritePlayer;
//}
//sf::Sprite Battle::getSpriteEnemy() const{
//    return this->spriteEnemy;
//}
//sf::Sprite Battle::getSpriteAttack() const{
//    return this->attackSprite;
//}
//sf::Sprite Battle::getSpriteBg() const{
//    return this->spriteBg;
//}
//int Battle::getPlayerHP() const{
//    return this->playerHP;
//}
//int Battle::getEnemyHP() const{
//    return this->enemyHP;
//}
//int Battle::getBattleResult() const{
//    return this->battleResult;
//}
