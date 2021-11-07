#pragma once
#include <SFML/Graphics.hpp>
#ifndef WINDOWGAME_H
#define WINDOWGAME_H

class WindowGame{
	int windowHeight;
	int windowWidth;

public:
	sf::VideoMode vm;
	sf::RenderWindow window;
	void setWindowSize(int, int);
	WindowGame(int, int, std::string); //constructor: set title, width, height
};

#endif