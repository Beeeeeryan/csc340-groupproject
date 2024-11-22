#include "Enemy.h"

// Default Constructor
// Calls the default constructor of Character.h
Enemy::Enemy()
    : Character() {  
        name = "Enemy";
        // set default position to top right coner of 3x3 grid.
        positionX = 2;
        positionY = 2;
        health = 200;
}

// Inherits from Character and initializes base class attributes (name, health, attackPower, positionX, positionY)
Enemy::Enemy(std::string name, int health, int attackPower, int positionX, int positionY)
    : Character(name, health, attackPower, positionX, positionY) {
}
