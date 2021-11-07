#include "windowGame.h"
#include <SFML/Graphics.hpp>

WindowGame::WindowGame(int height, int width, std::string name) {
	this->vm.height = height;
	this->vm.width = width;
	
	this->window.create(this->vm, name);
}