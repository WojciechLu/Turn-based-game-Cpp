#include "windowGame.h"
#include <SFML/Graphics.hpp>
#include <iostream>

WindowGame::WindowGame(int height, int width, std::string name) {
	this->vm.height = height;
	this->vm.width = width;
	
	this->window.create(this->vm, name);
}

void WindowGame::draw2dWorld(GameWorld gameWorld, PlayerCharacter player, EnemyCharacter &enemiesInGame, Coins coinsInGame) {
    this->window.clear();

    for (int i = 0; i < gameWorld.gridLength; i++) {
        for (int j = 0; j < gameWorld.gridLength; j++) {
            this->window.draw(gameWorld.tiles[i][j]->sprite);  //tile[0][0] is top left, tile[0][1] is next to right
        }
    }

    for (int i = 0; i < coinsInGame.getNumberOfCoins(); i++) { //draw all coins
        this->window.draw(coinsInGame.tiles[i]->sprite);
    }
    for (int i = 0; i < enemiesInGame.getNumberOfEnemies(); i++) { //draw all enemies
        this->window.draw(enemiesInGame.tiles[i]->sprite);
    }

    this->window.draw(player.getSprite()); //draw player
    //this->window.draw(enemy1.getSprite());

    this->window.display(); //display all the sprites on the window
}

void WindowGame::updateInputWorld(PlayerCharacter* player, EnemyCharacter &enemiesInGame, GameWorld gameWorld, StateMachine &states, Coins &coinsInGame, std::vector<Battle*> battlesInGame) {
    sf::Event event;

    int which = enemiesInGame.isPlayerOn(player, &states);
    if (which != -1) {
        battlesInGame[which]->isCurrent = true;
    }

    while (window.pollEvent(event)) {
        //Checking the key and moving the player
        if (event.type == sf::Event::KeyPressed) {


            float playerX = player->getPos().x / 64, playerY = player->getPos().y / 64; //get player pos as value from 0-8

            if (event.key.code == sf::Keyboard::D) {
                if (gameWorld.tiles[playerY][playerX + 1]->isPassable) player->Move("D"); //checking if next tile is passable

            }
            if (event.key.code == sf::Keyboard::A) {
                if (gameWorld.tiles[playerY][playerX - 1]->isPassable) player->Move("A");//checking if next tile is passable

            }
            if (event.key.code == sf::Keyboard::W) {
                if (gameWorld.tiles[playerY - 1][playerX]->isPassable) player->Move("W");//checking if next tile is passable

            }
            if (event.key.code == sf::Keyboard::S) {
                if (gameWorld.tiles[playerY + 1][playerX]->isPassable) player->Move("S");//checking if next tile is passable

            }

        }
        coinsInGame.isPlayerOn(player);
        if (event.key.code == sf::Keyboard::Escape || event.type == sf::Event::Closed) this->window.close(); //if Escape do quit game

    }
}

void WindowGame::drawBattle(Battle battle)
{
    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        return;
    }    
    sf::Text textEnemyHP;
    sf::Text textPlayerHP;

    textPlayerHP.setFont(font); // font is a sf::Font
    textEnemyHP.setFont(font);
    
    textPlayerHP.setString(std::to_string(battle.player.getHP())); // set the string to display
    textEnemyHP.setString(std::to_string(battle.enemy->getHP()));
    
    textPlayerHP.setCharacterSize(24); // set the character size
    textEnemyHP.setCharacterSize(24);
    
    textPlayerHP.setFillColor(sf::Color::Red); // set the color
    textEnemyHP.setFillColor(sf::Color::Red);

    textPlayerHP.setPosition(3.5 * 64, 4 * 64);
    textEnemyHP.setPosition(5.5 * 64, 4 * 64);

	this->window.clear(sf::Color(37, 19, 26));
	this->window.draw(battle.getSpriteBg());


    this->window.draw(battle.getSpriteMenu()); //drawing sprite of actions to choose
    if (battle.isShieldOn > 0) {
        this->window.draw(battle.getSpriteIconShield());
        sf::Text shield = DrawNumber(battle.isShieldOn, 2.5 * 64 + 32, 2.5 * 64);
        shield.setFont(font);
        this->window.draw(shield);
    }
    if (battle.isBuffOn > 0) {
        this->window.draw(battle.getSpriteIconBuff());
        sf::Text buff = DrawNumber(battle.isBuffOn, 2.5 * 64, 2.5 * 64);
        buff.setFont(font);
        this->window.draw(buff);
    }
	this->window.draw(battle.player.getSprite());
	this->window.draw(battle.enemy->getSprite());    //drawing enemy on the screen
	this->window.draw(textPlayerHP);
	this->window.draw(textEnemyHP);
	this->window.display();
}


void WindowGame::animation(Attack attackAnimation) { //repair in the future 
	sf::Clock clock;
	sf::IntRect rectSourceSprite(0, 0, 64, 64);
	sf::Sprite sprite(attackAnimation.getTexture(), rectSourceSprite);
	sprite.setPosition(attackAnimation.getSprite().getPosition());
	rectSourceSprite.left = 0;

	std::vector<sf::Sprite> spriteAnimation; //vector containing frames of animated attack
	spriteAnimation.clear();

	for (int i = 0; i < 7; i++) {
		sprite.setTextureRect(rectSourceSprite);
		spriteAnimation.push_back(sprite);
		rectSourceSprite.left += 64;
	}

	//m_window->window.draw(spriteAnimation[0]);
	for (int i = 1; i < 7; i++) {
		//if (clock.getElapsedTime().asSeconds() > 0.05f) {
		//	//spriteAnimation.erase(spriteAnimation.begin());
		//	clock.restart();
		//}
		//spriteAnimation[i-1].setColor(sf::Color::Transparent);
		//m_window->window.draw(spriteAnimation[i-1]);
		this->window.draw(spriteAnimation[i]);
		this->window.display();
	}
	attackAnimation.setUpInitial("images/attackAnimation/blank.png", attackAnimation.getSprite().getPosition().x, attackAnimation.getSprite().getPosition().y);
}

void WindowGame::battleUpdate(Battle &battle, Attack attack, StateMachine &states)
{
    sf::Event event;
    if (battle.getBattleResult() == 1) {
        std::cout << "\nEnemy 0HP\nYou won\n";
        battle.isCurrent = false;
        states.battle2World();
        //return;
    }
    else if (battle.getBattleResult() == -1) {
        std::cout << "\nPlayer 0HP\nYou lost\n";
        this->window.close();
        states.battle2World();
        //return;
    }
    else {
        while (this->window.pollEvent(event)) {
            if (battle.isPlayerTurn()) {
                if (event.type == sf::Event::KeyPressed) {
                    battle.chooseAction(event.key.code, battle.player, &attack);
                }
            }
        }
        if (!battle.isPlayerTurn()) {
            battle.enemyAttack(&attack);
            battle.setPlayerTurn(true);
        }
        if (event.key.code == sf::Keyboard::Escape || event.type == sf::Event::Closed) this->window.close(); //if escape, exit game
    }
    
}

sf::Text WindowGame::DrawNumber(int a, int x, int y) {
    sf::Text number;
    number.setString(std::to_string(a));
    number.setCharacterSize(12);
    number.setFillColor(sf::Color::White);
    number.setPosition(x, y);
    return number;
}