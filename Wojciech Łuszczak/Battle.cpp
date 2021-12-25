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
        this->player.setAD(floor(player.getAD() * 1.8));
    }
    else if (a == -4) {
        this->player.setAD(floor(player.getAD() * 2));
    }
}

void Battle::actionsMenu(std::string textureName) { //setting texture and then using setUpSprite to set sprite
    int width = 64 * 4;
    sf::IntRect rect(this->skillChoice * width, 0, width, 64);
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
    else if (this->player.getHP() == 0) {
        this->battleResult = -1;  //enemy won
        std::cout << this->battleResult << std::endl;
    }
}

void Battle::enemyAttack(Attack* attack)
{
    sf::Clock clock;
    while (1) {
        if (float time = clock.getElapsedTime() > sf::seconds(0.5f)) {
            break;
        }
    }
    int damageDealt = attack->doAttackEnemy(enemy->getAD(), this->player.getSprite().getPosition());
    if (damageDealt == -1) {
        std::cout << "Missed \n";
    }
    else {
        if (this->isShieldOn) {
            std::cout << "Shield delete" << std::endl;
            this->isShieldOn = false;
        }
        else {
            if (damageDealt >= this->player.getHP()) {
                std::cout << "Enemy DMAGE: " << damageDealt << std::endl;
                this->player.setHP(0);
                std::cout << "Player HP: " << this->player.getHP() << std::endl;
            }
            else {
                std::cout << "Enemy DMAGE: " << damageDealt << std::endl;
                this->player.setHP(this->player.getHP() - damageDealt);
                std::cout << "Player HP: " << this->player.getHP() << std::endl;
            }
        }
    }
    checkWin();
}
void Battle::chooseAction(sf::Keyboard::Key key, PlayerCharacter p, Attack* attack) {
    if (key == sf::Keyboard::A) {
        if (this->skillChoice <= 0) {
            this->skillChoice = 3;
        }
        else{
            this->skillChoice--;
        }
    }
    else if (key == sf::Keyboard::D) {
        if (this->skillChoice >= 3) {
            this->skillChoice = 0;
        }
        else {
            this->skillChoice++;
        }
    }
    else if (key == sf::Keyboard::E) {
        int damageDealt = attack->doAttack(this->skillChoice, player.getAD(), this->enemy->getSprite().getPosition()); //giving the number of chosen attack and posiotion to (chosen) enemy then recive damage dealt
        playerAttack(damageDealt);
        //attack->animation(m_window); //making animation based on the above data
        checkWin();
        if (this->battleResult == 1) {
            return;
        }
        setPlayerTurn(false);
    }
    actionsMenu("images/actionMenu/attackSwordsman/interface.png");
}

Battle::Battle(PlayerCharacter &playerPattern, EnemyCharacter &enemyPattern)
	:player(playerPattern), enemy(&enemyPattern){ //wywo³anie konstruktorów kopiuj¹cych dla pól prywatnych klasy bitwy: PlayerCharacter player, EnemyCharacter enemy

    this->skillChoice = 0;
	this->playerTurn = true; 
    this->battleResult = 0;
    actionsMenu("images/actionMenu/attackSwordsman/interface.png");
    sf::IntRect bg(0, 0, 576, 576);
    setUpBackground("images/battle/background.png", bg);
    this->player.setPos(3 * 64, 3 * 64);
    this->enemy->setPos(5 * 64, 3 * 64);
    std::cout << "X: " << player.getPos().x << " Y: " << player.getPos().y << std::endl;
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

bool Battle::isPlayerTurn() const
{
    return this->playerTurn;
}

void Battle::setPlayerTurn(bool a)
{
    this->playerTurn = a;
}

