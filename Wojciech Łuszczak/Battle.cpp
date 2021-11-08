#include "Battle.h"
#include <iostream>

Battle::Battle(PlayerCharacter player, EnemyCharacter enemy) {  //constructor, get player and enemy informations and setting to battle class
    actionsMenu("images/actionMenu/attackSwordsman/interface.png", 2.5 * 64, 6 * 64);
    setPlayer(player);
    setEnemy(enemy);
    initText();
}

void Battle::setPlayer(PlayerCharacter player) { //setting player data in constructor
    spritePlayer = player.getSprite();
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
sf::Text Battle::getTextEnemyHP() {
    return this->textEnemyHP;
}
sf::Text Battle::getTextPlayerHP() {
    return this->textPlayerHP;
}
int Battle::getBattleResult() {
    return this->battleResult;
}

void Battle::chooseAction(char key, PlayerCharacter player, Attack *attack, WindowGame *m_window) { //changing texture sprite to next or previous attack, used in StartGame
    if (key == 'A') {
        if (this->attackChoice == 0) {
            this->attackChoice = 3;
            //player.setChoiceSkill(attackChoice); //setting the number 0-4, depends on the chosen action
        }
        else {
            this->attackChoice--;
            //player.setChoiceSkill(attackChoice);
        }
        setUpSpriteActionsMenu("images/actionMenu/attackSwordsman/interface.png"); //update the choice of attack
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
        setUpSpriteActionsMenu("images/actionMenu/attackSwordsman/interface.png"); //update the choice of attack
    }
    else if (key == 'E') {
        int damageDealt = attack->doAttack(attackChoice, player.getAttackDamage(), this->spriteEnemy.getPosition()); //giving the number of chosen attack and posiotion to (chosen) enemy then recive damage dealt
        playerAttack(damageDealt);
        attack->animation(m_window); //making animation based on the above data
        checkWin();
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

void Battle::initText() {
    sf::Font font;
    font.loadFromFile("arial.ttf");
    textPlayerHP.setFont(font); // font is a sf::Font
    textEnemyHP.setFont(font);
    
    textPlayerHP.setString(std::to_string(playerHP)); // set the string to display
    textEnemyHP.setString(std::to_string(enemyHP));
    
    textPlayerHP.setCharacterSize(24); // set the character size
    textEnemyHP.setCharacterSize(24);
    
    textPlayerHP.setFillColor(sf::Color::Red); // set the color
    textEnemyHP.setFillColor(sf::Color::Red);

    textPlayerHP.setPosition(3 * 64, 4 * 64);
    textEnemyHP.setPosition(5 * 64, 4 * 64);
}