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


windowGame* mainWindow = new windowGame(576, 576, "Game");  // created obj mainWindow with consturcor: size 512x512 with title name: Game
GameWorld gameWorld = GameWorld();                          //world class constructor
PlayerCharacter* player = new PlayerCharacter("images/character64.png", 192, 256); //player character class constructor on pos(192, 256) with texture character64
coins coinsInGame;

void draw2dWorld() {
    mainWindow->window.clear();

    for (int i = 0; i < gameWorld.gridLength; i++) {
        for (int j = 0; j < gameWorld.gridLength; j++) {
            mainWindow->window.draw(gameWorld.tiles[i][j]->sprite);  //tile[0][0] is top left, tile[0][1] is next to right
        }
    }

    for (int i = 0; i < coinsInGame.numberOfCoinsOnMap; i++) { //draw all coins
        mainWindow->window.draw(coinsInGame.tiles[i]->sprite);
    }

    mainWindow->window.draw(player->sprite); //draw player

    mainWindow->window.display(); //display all the sprites on the window
}

void updateInput() {
    sf::Event event;
    
    while (mainWindow->window.pollEvent(event)) {
        //Checking the key and moving the player
        if (event.type == sf::Event::KeyPressed) {

            
            float playerX = player->pos.x / 64, playerY = player->pos.y / 64; //get player pos as value from 0-8

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
            int posCoin = coinsInGame.isPlayerOn(player->pos.x, player->pos.y, player);
            if (posCoin != -1) {
                mainWindow->window.clear();
                draw2dWorld();
            }
        }
        //if Escape do quit game
        if (event.key.code == sf::Keyboard::Escape || event.type == sf::Event::Closed) mainWindow->window.close();
        
    }
}


int main()
{
    mainWindow->window.setFramerateLimit(30);
    while (mainWindow->window.isOpen())
    {
        //update input
        updateInput();

        //update the game
        
        draw2dWorld(); //draw all sprites on 2d map
    }

    return 0;
}