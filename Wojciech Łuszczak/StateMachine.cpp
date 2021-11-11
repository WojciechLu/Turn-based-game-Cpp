#include "StateMachine.h"

StateMachine::StateMachine(bool world, bool battle) {
	this->isWorld = world;
	this->isBattle = battle;
}

void StateMachine::world2Battle() {	//change video to battle
	if (this->isWorld && !this->isInventory) {
		this->isWorld = false;
		this->isBattle = true;
	}
} 
void StateMachine::battle2World() {	//change video to 2d map
	if (this->isBattle && !this->isWorld) {
		this->isBattle = false;
		this->isWorld = true;
	}
} 
void StateMachine::world2Inventory() {	//check if is on map
	if (this->isWorld && !this->isBattle) {
		this->isWorld = false;
		this->isInventory = true;
	}
}
void StateMachine::inventory2World() {	//close inventory
	if (this->isInventory) {
		this->isInventory = false;
		this->isWorld = true;
	}
}

bool StateMachine::getIsWorld(){
	return this->isWorld;
}
bool StateMachine::getIsBattle(){
	return this->isBattle;
}
bool StateMachine::getIsInventory(){
	return this->isInventory;
}