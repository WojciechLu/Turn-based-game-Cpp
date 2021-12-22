#include "windowGame.h"
#include <SFML/Graphics.hpp>

WindowGame::WindowGame(int height, int width, std::string name) {
	this->vm.height = height;
	this->vm.width = width;
	
	this->window.create(this->vm, name);
}

//void WindowGame::drawBattle(Battle& battle) {
//    sf::Font font;
//    if (!font.loadFromFile("arial.ttf")) {
//        return;
//    }
//    std::vector<sf::Text> textHP;
//    sf::Text textEnemyHP;
//    sf::Text textPlayerHP;
//
//    textPlayerHP.setFont(font); // font is a sf::Font
//    textEnemyHP.setFont(font);
//
//    textPlayerHP.setString(std::to_string(battle.player.getHP())); // set the string to display
//    textEnemyHP.setString(std::to_string(battle.enemy.getHP()));
//
//    textPlayerHP.setCharacterSize(24); // set the character size
//    textEnemyHP.setCharacterSize(24);
//
//    textPlayerHP.setFillColor(sf::Color::Red); // set the color
//    textEnemyHP.setFillColor(sf::Color::Red);
//
//    textPlayerHP.setPosition(3.5 * 64, 4 * 64);
//    textEnemyHP.setPosition(5.5 * 64, 4 * 64);
//
//
//    this->window.clear(sf::Color(37, 19, 26));
//    this->window.draw(battle.getSpriteBg());
//    this->window.draw(battle.getSpriteMenu()); //drawing sprite of actions to choose
//    this->window.draw(battle.player.getSprite());   //drawing player on the screen
//    this->window.draw(battle.enemy.getSprite());    //drawing enemy on the screen
//    this->window.draw(textEnemyHP);
//    this->window.draw(textPlayerHP);
//    //this->window.draw(battle->getTextEnemyHP());
//    //this->window.draw(battle->getTextPlayerHP());
//    this->window.display();
//}

void WindowGame::draw2dWorld(GameWorld gameWorld, PlayerCharacter player, EnemyCharacter enemy1, Coins coinsInGame) {
    this->window.clear();

    for (int i = 0; i < gameWorld.gridLength; i++) {
        for (int j = 0; j < gameWorld.gridLength; j++) {
            this->window.draw(gameWorld.tiles[i][j]->sprite);  //tile[0][0] is top left, tile[0][1] is next to right
        }
    }

    for (int i = 0; i < coinsInGame.getNumberOfCoins(); i++) { //draw all coins
        this->window.draw(coinsInGame.tiles[i]->sprite);
    }

    this->window.draw(player.getSprite()); //draw player
    this->window.draw(enemy1.getSprite());

    this->window.display(); //display all the sprites on the window
}

void WindowGame::drawBattle(Battle battle)
{
    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        return;
    }    
    std::vector<sf::Text> textHP;
    sf::Text textEnemyHP;
    sf::Text textPlayerHP;

    textPlayerHP.setFont(font); // font is a sf::Font
    textEnemyHP.setFont(font);
    
    textPlayerHP.setString(std::to_string(battle.player->getHP())); // set the string to display
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
	this->window.draw(battle.player->getSprite());
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

void WindowGame::battleUpdate(Battle battle, Attack attack)
{
    sf::Event event;
    if (battle.getBattleResult() == 1) {
        //std::cout << "\nEnemy 0HP\nYou won\n";
        //states.battle2World();
        return;
    }
    else if (battle.getBattleResult() == -1) {
        //std::cout << "\nPlayer 0HP\nYou lost\n";
        //states.battle2World();
        return;
    }
    else {
        while (this->window.pollEvent(event)) {
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::A) {
                    battle.chooseAction('A', *battle.player, &attack); //if A, change chosen action to the left
                }
                if (event.key.code == sf::Keyboard::D) {
                    battle.chooseAction('D', *battle.player, &attack); //if D, change chosen action to the right
                }
                if (event.key.code == sf::Keyboard::E) {
                    battle.chooseAction('E', *battle.player, &attack); //if E, do action
                }
            }
            if (event.key.code == sf::Keyboard::Escape || event.type == sf::Event::Closed) this->window.close(); //if escape, exit game
        }
    }
}
