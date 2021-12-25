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
GameWorld gameWorld = GameWorld();  //world class constructor
StateMachine states(true, false); //2dWorldState, BattleState
PlayerCharacter* player = new PlayerCharacter("images/character64.png", 192, 256); //player character class constructor on pos(192, 256) with texture character64
EnemyCharacter* enemy1 = new EnemyCharacter("images/enemyWarrior64.png", 256, 192);
Coins coinsInGame;
Attack* attack = new Attack();

//update input 2d map
void updateInputWorld() {
    sf::Event event;

    //if(player->getPosX == )
    //if (enemy1->isPlayerOn(*player, &states)) {
    //    std::cout << "You stepped on sth" << std::endl;
    //    std::cout << "Coins: " << player->getCoins() << std::endl;
    //}
    
    player->isPlayerOnEnemy(*enemy1, &states);
    while (mainWindow->window.pollEvent(event)) {
        //Checking the key and moving the player
        if (event.type == sf::Event::KeyPressed) {

            
            float playerX = player->getPos().x / 64, playerY = player->getPos().y / 64; //get player pos as value from 0-8

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

int main()
{
    Battle* battle1 = new Battle(*player, *enemy1);

    mainWindow->window.setFramerateLimit(20);
    while (mainWindow->window.isOpen())
    {

       if (states.getIsBattle()) { //render battle
           mainWindow->drawBattle(*battle1);
           mainWindow->battleUpdate(*battle1, *attack, states);
        }
        
        else if (states.getIsWorld()) { //render 2d world
            mainWindow->updateInputWorld(player, enemy1, gameWorld, states, coinsInGame);
            mainWindow->draw2dWorld(gameWorld, *player, *enemy1, coinsInGame);
        }

    }
    return 0;
}