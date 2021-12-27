#include "gameWorld.h"
#include <iostream>

GameWorld::GameWorld() {
	gridLength = 9;
	setUpInitialState();
}

void GameWorld::setUpInitialState() {
	//exitPos = sf::Vector2i(2, 0);
	setUpTiles();

}


//0, 64, 128, 192, 256, 320, 384
void GameWorld::setUpTiles() {
	tiles.clear();
	// push_back - Metoda, która dodaje nowy element na koñcu kontenera vector.
	//Tworzony jest wektor firstRow zawieraj¹cy wskaŸnik do GameTiles, a nastêpnie tworzon¹ s¹ elementy z danymi
	//texture's string, x, y, isPassable, isExit
	char path[12] = "images/map/";
	char extension[5] = ".png";
	for (int y = 0; y < this->gridLength; y++) {
		std::vector<GameTile*> row;
		for (int x = 0; x < this->gridLength; x++) {
			bool isPassable = true;
			int currentTile = this->lvl1[x + y * gridLength];
			for (int ip : this->impassable) {
				if (currentTile == ip) {
					isPassable = false;
					break;
				}
			}
			row.push_back(new GameTile(path+std::to_string(this->lvl1[y + x * gridLength])+extension, y * 64, x * 64, isPassable, false));
		}
		this->tiles.push_back(row);
	}
}