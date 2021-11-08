//include lib
#include <SFML/Graphics.hpp>
#include <iostream>
//include classes
#include "gameWorld.h"
#include "gameTile.h"
#include "playerCharacter.h"
#include "StateMachine.h"
#include "windowGame.h"
#include "coins.h"
#include "Battle.h"
#include "Character.h"
#include "Attack.h"


WindowGame* mainWindow = new WindowGame(576, 576, "Game");  // created obj mainWindow with consturcor: size 512x512 with title name: Game
GameWorld gameWorld = GameWorld();                          //world class constructor
PlayerCharacter* player = new PlayerCharacter("images/character64.png", 192, 256); //player character class constructor on pos(192, 256) with texture character64
EnemyCharacter* enemy1 = new EnemyCharacter("images/enemyWarrior64.png", 256, 192);
Coins coinsInGame;
Attack* attack = new Attack();
Battle* battle = new Battle(*player, *enemy1);

int stage = 0; //0 - battle, 1 - 2d word
//Battle* battle = new Battle();

void draw2dWorld() {
    mainWindow->window.clear();

    for (int i = 0; i < gameWorld.gridLength; i++) {
        for (int j = 0; j < gameWorld.gridLength; j++) {
            mainWindow->window.draw(gameWorld.tiles[i][j]->sprite);  //tile[0][0] is top left, tile[0][1] is next to right
        }
    }

    for (int i = 0; i < coinsInGame.getNumberOfCoins(); i++) { //draw all coins
        mainWindow->window.draw(coinsInGame.tiles[i]->sprite);
    }

    mainWindow->window.draw(player->getSprite()); //draw player

    mainWindow->window.display(); //display all the sprites on the window
}

void drawBattle() {
    //sf::Text textEnemyHP = battle->getTextEnemyHP();
    //sf::Text textPlayerHP = battle->getTextPlayerHP();

    mainWindow->window.clear(sf::Color::White);
    mainWindow->window.draw(battle->getSpriteMenu()); //drawing sprite of actions to choose
    mainWindow->window.draw(battle->getSpritePlayer());   //drawing player on the screen
    mainWindow->window.draw(battle->getSpriteEnemy());    //drawing enemy on the screen
    //mainWindow->window.draw(textEnemyHP);
    //mainWindow->window.draw(textPlayerHP);
    //mainWindow->window.draw(battle->getTextEnemyHP());
    //mainWindow->window.draw(battle->getTextPlayerHP());
    mainWindow->window.display();
}

//update input 2d map
void updateInput() {
    sf::Event event;
    
    while (mainWindow->window.pollEvent(event)) {
        //Checking the key and moving the player
        if (event.type == sf::Event::KeyPressed) {

            
            float playerX = player->getPosX() / 64, playerY = player->getPosY() / 64; //get player pos as value from 0-8

            if (event.key.code == sf::Keyboard::D) {
                if (gameWorld.tiles[playerY][playerX + 1]->isPassable) player->Move("D"); //checking if next tile is passable

            }
            if (event.key.code == sf::Keyboard::A) {
                if (gameWorld.tiles[playerY][playerX-1]->isPassable) player->Move("A");//checking if next tile is passable

            }
            if (event.key.code == sf::Keyboard::W) {
                if (gameWorld.tiles[playerY - 1][playerX]->isPassable) player->Move("W");//checking if next tile is passable

            }
            if (event.key.code == sf::Keyboard::S) {
                if (gameWorld.tiles[playerY + 1][playerX]->isPassable) player->Move("S");//checking if next tile is passable

            }
            
        }
        coinsInGame.isPlayerOn(player);
        //if Escape do quit game
        if (event.key.code == sf::Keyboard::Escape || event.type == sf::Event::Closed) mainWindow->window.close();
        
    }
}

//update input battle
void updateInputBattle() {
    sf::Event event;
    if (battle->getBattleResult() == 1) {
        std::cout << "\nEnemy 0HP\nYou won\n";
        stage = 1;
    }
    else if (battle->getBattleResult() == -1) {
        std::cout << "\nPlayer 0HP\nYou lost\n";
        stage = 1;
    }
    else {
        while (mainWindow->window.pollEvent(event)) {
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::A) {
                    battle->chooseAction('A', *player, attack, mainWindow); //if A, change chosen action to the left
                }
                if (event.key.code == sf::Keyboard::D) {
                    battle->chooseAction('D', *player, attack, mainWindow); //if D, change chosen action to the right
                }
                if (event.key.code == sf::Keyboard::E) {
                    battle->chooseAction('E', *player, attack, mainWindow); //if E, do action
                }
            }
            if (event.key.code == sf::Keyboard::Escape || event.type == sf::Event::Closed) mainWindow->window.close(); //if escape, exit game
        }
    }
}

int main()
{
    mainWindow->window.setFramerateLimit(20);
    while (mainWindow->window.isOpen())
    {

        if (stage == 0) { //render battle
            updateInputBattle();
            drawBattle();
        }
        else if (stage == 1) { //render 2d world
            updateInput();
            draw2dWorld();
        }
    }

    return 0;
}