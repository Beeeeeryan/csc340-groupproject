// Enemy.cpp

#include "Enemy.h"
#include <iostream>

// Default constructor: initialize with a predefined position and grid
Enemy::Enemy(Grid* grid) {
    this->name = "Enemy";
    this->health = 200;
    this->attackPower = 10;
    this->positionX = 2;
    this->positionY = 2;
    this->grid = grid;
    
    grid->setEnemyPosition(positionX, positionY);  // Set initial position on the grid
}

// Parameterized constructor: custom enemy attributes
Enemy::Enemy(std::string name, int health, int attackPower, int positionX, int positionY, Grid* grid) {
    this->name = name;
    this->health = health;
    this->attackPower = attackPower;
    this->positionX = positionX;
    this->positionY = positionY;
    this->grid = grid;

    grid->setEnemyPosition(positionX, positionY);  // Set initial position on the grid
}

// Enemy attack method
int Enemy::attack() const {
    return attackPower; 
}

// Handle taking damage
int Enemy::takeDamage(int damage) {
    health -= damage;
    if (health < 0) {
        health = 0;
    }
    return health;
}

// void Character::move(int x, int y) {
//     positionX += x;
//     positionY += y;
//     if (grid.isValidPosition(positionX, positionY)) {
//         std::cout << name << " moved to (" << positionX << ", " << positionY << ")" << std::endl;
//     } else {
//         std::cout << name << " cannot move to (" << positionX << ", " << positionY << ") - out of bounds!" << std::endl;
//         positionX -= x;
//         positionY -= y;
//     }
// }

// Move method to update enemy's position on the grid
void Enemy::move(int x, int y) {
    grid->clearPosition(positionX, positionY);  // Clear current position

    int newX = positionX + x;
    int newY = positionY + y;

    if (grid->isValidPosition(newX, newY)) {
        positionX = newX;
        positionY = newY;
    } else {
        std::cout << name << " cannot move to (" << newX << ", " << newY << ") - out of bounds!" << std::endl;
    }

    grid->setEnemyPosition(positionX, positionY);  // Update grid with new position
}
