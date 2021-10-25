//include lib
#include <SFML/Graphics.hpp>
#include <iostream>
//include classes
#include "gameWorld.h"
#include "gameTile.h"
#include "playerCharacter.h"
#include "StateMachine.h"
#include "windowGame.h"


windowGame window = windowGame(); //ups, zrobic ponownie window
//kurwa
GameWorld gameWorld = GameWorld();
PlayerCharacter* player = new PlayerCharacter("images/character64.png", 192, 256);

void drawWorld() {
    for (int i = 0; i < gameWorld.gridLength; i++) {
        for (int j = 0; j < gameWorld.gridLength; j++) {
            window.draw(gameWorld.tiles[i][j]->sprite);  //tile[0][0] is top left, tile[0][1] is next to right
        }
    }
    window.draw(player->sprite);
}


void updateInput() {
    sf::Event event;
    
    while (window.pollEvent(event)) {
        //Checking the key and moving the player
        if (event.type == sf::Event::KeyPressed) {


            int playerX = player->pos.x / 64, playerY = player->pos.y / 64; //get player pos as value from 0-8
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
        //if Escape do quit game
        if (event.key.code == sf::Keyboard::Escape || event.type == sf::Event::Closed) window.close();
    }
}


int main()
{
    window.setFramerateLimit(30);
    while (window.isOpen())
    {
        //update input
        updateInput();

        //update the game
        window.clear();
        drawWorld(); //draw all sprites on 2d map
        window.display(); //display all the sprites on the window
    }

    return 0;
}