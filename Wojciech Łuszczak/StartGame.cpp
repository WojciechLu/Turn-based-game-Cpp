//include lib
#include <SFML/Graphics.hpp>
#include <iostream>
//include classes
#include "gameWorld.h"
#include "gameTile.h"
#include "playerCharacter.h"
#include "EnemyCharacter.h"
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
//EnemyCharacter* enemy1 = new EnemyCharacter("images/enemyWarrior64.png", 256, 192);
EnemyCharacter enemiesInGame;
Coins coinsInGame;
Attack* attack = new Attack();
std::vector<Battle*> battlesInGame;

int main()
{
    //for (int i = 0; i < enemiesInGame.getNumberOfEnemies(); i++) { //draw all enemies
    //    battlesInGame.push_back(new Battle(player, enemiesInGame.tiles[i]->sprite));
    //}
    mainWindow->window.setFramerateLimit(20);
    while (mainWindow->window.isOpen())
    {

       //if (states.getIsBattle()) { //render battle
       //    mainWindow->drawBattle(*battle1);
       //    mainWindow->battleUpdate(*battle1, *attack, states);
       // }
        
        //else if (states.getIsWorld()) { //render 2d world
        if (states.getIsWorld()) { //render 2d world
            mainWindow->updateInputWorld(player, enemiesInGame, gameWorld, states, coinsInGame);
            mainWindow->draw2dWorld(gameWorld, *player, enemiesInGame, coinsInGame);
        }

    }
    return 0;
}