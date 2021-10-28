#include "gameWorld.h"

GameWorld::GameWorld() {
	gridLength = 9;
	setUpInitialState();
}

void GameWorld::setUpInitialState() {
	//exitPos = sf::Vector2i(2, 0);
	setUpEnemyPositions();
	setUpTiles();

}

void GameWorld::setUpEnemyPositions() {
	enemyPositions.clear();
	//enemyPositions.push_back(sf::Vector2i(6, 0)); set in this way positions' of enemies
}

//0, 64, 128, 192, 256, 320, 384
void GameWorld::setUpTiles() {
	tiles.clear();

	std::vector<GameTile *> firstRow;
	// push_back - Metoda, która dodaje nowy element na koñcu kontenera vector.
	//Tworzony jest wektor firstRow zawieraj¹cy wskaŸnik do GameTiles, a nastêpnie tworzon¹ s¹ elementy z danymi
	//texture's string, x, y, isPassable, isExit
	firstRow.push_back(new GameTile("images/map/gray.png", 0, 0, false, false));
	firstRow.push_back(new GameTile("images/map/1.png", 64, 0, false, false));
	firstRow.push_back(new GameTile("images/map/2.png", 128, 0, false, false));
	firstRow.push_back(new GameTile("images/map/3.png", 192, 0, false, false));
	firstRow.push_back(new GameTile("images/map/4.png", 256, 0, false, false));
	firstRow.push_back(new GameTile("images/map/2.png", 320, 0, false, false));
	firstRow.push_back(new GameTile("images/map/6.png", 384, 0, true, false));
	firstRow.push_back(new GameTile("images/map/gray.png", 448, 0, false, false));
	firstRow.push_back(new GameTile("images/map/gray.png", 512, 0, false, false));
	tiles.push_back(firstRow);

	std::vector< GameTile*> secondRow;
	secondRow.push_back(new GameTile("images/map/7.png", 0, 64, false, false));
	secondRow.push_back(new GameTile("images/map/2.png", 64, 64, false, false));
	secondRow.push_back(new GameTile("images/map/8.png", 128, 64, true, false));
	secondRow.push_back(new GameTile("images/map/10.png", 192, 64, true, false));
	secondRow.push_back(new GameTile("images/map/9.png", 256, 64, true, false));
	secondRow.push_back(new GameTile("images/map/11.png", 320, 64, true, false));
	secondRow.push_back(new GameTile("images/map/4.png", 384, 64, false, false));
	secondRow.push_back(new GameTile("images/map/18.png", 448, 64, false, false));
	secondRow.push_back(new GameTile("images/map/gray.png", 512, 64, false, false));
	tiles.push_back(secondRow);

	std::vector< GameTile*> thirdRow;
	thirdRow.push_back(new GameTile("images/map/13.png", 0, 128, false, false));
	thirdRow.push_back(new GameTile("images/map/14.png", 64, 128, true, false));
	thirdRow.push_back(new GameTile("images/map/16.png", 128, 128, true, false));
	thirdRow.push_back(new GameTile("images/map/16.png", 192, 128, true, false));
	thirdRow.push_back(new GameTile("images/map/15.png", 256, 128, true, false));
	thirdRow.push_back(new GameTile("images/map/15.png", 320, 128, true, false));
	thirdRow.push_back(new GameTile("images/map/17.png", 384, 128, true, false));
	thirdRow.push_back(new GameTile("images/map/24.png", 448, 128, false, false));
	thirdRow.push_back(new GameTile("images/map/gray.png", 512, 128, false, false));
	tiles.push_back(thirdRow);

	std::vector< GameTile*> fourthRow;
	fourthRow.push_back(new GameTile("images/map/19.png", 0, 192, false, false));
	fourthRow.push_back(new GameTile("images/map/14.png", 64, 192, true, false));
	fourthRow.push_back(new GameTile("images/map/15.png", 128, 192, true, false));
	fourthRow.push_back(new GameTile("images/map/16.png", 192, 192, true, false));
	fourthRow.push_back(new GameTile("images/map/16.png", 256, 192, true, false));
	fourthRow.push_back(new GameTile("images/map/15.png", 320, 192, true, false));
	fourthRow.push_back(new GameTile("images/map/17.png", 384, 192, true, false));
	fourthRow.push_back(new GameTile("images/map/5.png", 448, 192, false, false));
	fourthRow.push_back(new GameTile("images/map/18.png", 512, 192, false, false));
	tiles.push_back(fourthRow);

	std::vector< GameTile*> fifthRow;
	fifthRow.push_back(new GameTile("images/map/7.png", 0, 256, false, false));
	fifthRow.push_back(new GameTile("images/map/14.png", 64, 256, true, false));
	fifthRow.push_back(new GameTile("images/map/16.png", 128, 256, true, false));
	fifthRow.push_back(new GameTile("images/map/15.png", 192, 256, true, false));
	fifthRow.push_back(new GameTile("images/map/16.png", 256, 256, true, false));
	fifthRow.push_back(new GameTile("images/map/16.png", 320, 256, true, false));
	fifthRow.push_back(new GameTile("images/map/15.png", 384, 256, true, false));
	fifthRow.push_back(new GameTile("images/map/17.png", 448, 256, true, false));
	fifthRow.push_back(new GameTile("images/map/6.png", 512, 256, false, false));
	tiles.push_back(fifthRow);

	std::vector< GameTile*> sixthRow;
	sixthRow.push_back(new GameTile("images/map/13.png", 0, 320, false, false));
	sixthRow.push_back(new GameTile("images/map/14.png", 64, 320, true, false));
	sixthRow.push_back(new GameTile("images/map/15.png", 128, 320, true, false));
	sixthRow.push_back(new GameTile("images/map/16.png", 192, 320, true, false));
	sixthRow.push_back(new GameTile("images/map/16.png", 256, 320, true, false));
	sixthRow.push_back(new GameTile("images/map/15.png", 320, 320, true, false));
	sixthRow.push_back(new GameTile("images/map/16.png", 384, 320, true, false));
	sixthRow.push_back(new GameTile("images/map/17.png", 448, 320, true, false));
	sixthRow.push_back(new GameTile("images/map/12.png", 512, 320, false, false));
	tiles.push_back(sixthRow);

	std::vector< GameTile*> seventhRow;
	seventhRow.push_back(new GameTile("images/map/7.png", 0, 384, false, false));
	seventhRow.push_back(new GameTile("images/map/20.png", 64, 384, true, false));
	seventhRow.push_back(new GameTile("images/map/21.png", 128, 384, true, false));
	seventhRow.push_back(new GameTile("images/map/16.png", 192, 384, true, false));
	seventhRow.push_back(new GameTile("images/map/16.png", 256, 384, true, false));
	seventhRow.push_back(new GameTile("images/map/15.png", 320, 384, true, false));
	seventhRow.push_back(new GameTile("images/map/16.png", 384, 384, true, false));
	seventhRow.push_back(new GameTile("images/map/23.png", 448, 384, true, false));
	seventhRow.push_back(new GameTile("images/map/12.png", 512, 384, false, false));
	tiles.push_back(seventhRow);
	
	std::vector< GameTile*> eighthRow;
	eighthRow.push_back(new GameTile("images/map/25.png", 0, 448, false, false));
	eighthRow.push_back(new GameTile("images/map/29.png", 64, 448, false, false));
	eighthRow.push_back(new GameTile("images/map/27.png", 128, 448, false, false));
	eighthRow.push_back(new GameTile("images/map/20.png", 192, 448, true, false));
	eighthRow.push_back(new GameTile("images/map/21.png", 256, 448, true, false));
	eighthRow.push_back(new GameTile("images/map/22.png", 320, 448, true, false));
	eighthRow.push_back(new GameTile("images/map/23.png", 384, 448, true, false));
	eighthRow.push_back(new GameTile("images/map/31.png", 448, 448, false, false));
	eighthRow.push_back(new GameTile("images/map/32.png", 512, 448, false, false));
	tiles.push_back(eighthRow);

	std::vector< GameTile*> ninthRow;
	ninthRow.push_back(new GameTile("images/map/gray.png", 0, 512, false, false));
	ninthRow.push_back(new GameTile("images/map/gray.png", 64, 512, false, false));
	ninthRow.push_back(new GameTile("images/map/gray.png", 128, 512, false, false));
	ninthRow.push_back(new GameTile("images/map/29.png", 192, 512, false, false));
	ninthRow.push_back(new GameTile("images/map/28.png", 256, 512, false, false));
	ninthRow.push_back(new GameTile("images/map/26.png", 320, 512, false, false));
	ninthRow.push_back(new GameTile("images/map/28.png", 384, 512, false, false));
	ninthRow.push_back(new GameTile("images/map/30.png", 448, 512, false, false));
	ninthRow.push_back(new GameTile("images/map/gray.png", 512, 512, false, false));
	tiles.push_back(ninthRow);

}