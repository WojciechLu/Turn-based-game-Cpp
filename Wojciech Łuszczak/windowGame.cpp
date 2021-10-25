#include "windowGame.h"
#include <SFML/Graphics.hpp>

windowGame::windowGame() {

	sf::VideoMode vm(windowWidth, windowHeight);
	sf::RenderWindow window(vm, "Game", sf::Style::Default);

}