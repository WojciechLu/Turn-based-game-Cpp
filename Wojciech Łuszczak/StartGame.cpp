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
EnemyCharacter enemiesInGame;
Coins coinsInGame;

Attack* attack = new Attack();
std::vector<Battle*> battlesInGame;
int battlesInGameNum = 0;

int main()
{
    //Battle* battle1 = new Battle(*player, enemy1->getSprite());
    
    battlesInGame.clear();
    for (int i = 0; i < enemiesInGame.getNumberOfEnemies(); i++) {
        battlesInGame.push_back(new Battle(*player, enemiesInGame.tiles[i]->sprite));
    }
    battlesInGameNum = battlesInGame.size();

    mainWindow->window.setFramerateLimit(20);
    while (mainWindow->window.isOpen())
    {
        for (int i = 0; i < battlesInGameNum; i++) {
            if (battlesInGame[i]->getBattleResult() == 1) {
                battlesInGame.erase(battlesInGame.begin() + i);
                battlesInGameNum = battlesInGame.size();
                states.battle2World();
            }
        }
        if (states.getIsBattle()) { //render battle
            for (int i = 0; i < battlesInGameNum; i++) {
                if (battlesInGame[i]->isCurrent) {
                    mainWindow->drawBattle(*battlesInGame[i]);
                    mainWindow->battleUpdate(*battlesInGame[i], *attack, states);
                }
            }
        }
       
        
        else if (states.getIsWorld()) { //render 2d world
            mainWindow->updateInputWorld(player, enemiesInGame, gameWorld, states, coinsInGame, battlesInGame);
            mainWindow->draw2dWorld(gameWorld, *player, enemiesInGame, coinsInGame);
        }

    }
    return 0;
}