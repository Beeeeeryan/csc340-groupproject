// Player.cpp

#include "Player.h"
#include "../Map/Grid.h"  // Include Grid class

// Default Constructor
Player::Player(Grid* grid) {

    // Initialize Player-specific members
    this->name = "Player";
    this->positionX = 0;
    this->positionY = 0;
    this->specialAttack;
    this->grid = grid;

    // Set initial position on the grid
    grid->setPlayerPosition(this->positionX, this->positionY);
}

// Parameterized Constructor
Player::Player(std::string name, int health, int attackPower, int positionX, int positionY, Grid* grid) {
    this->name = name;
    this->health = health;
    this->attackPower = attackPower;
    this->positionX = positionX;
    this->positionY = positionY;
    this->grid = grid;

    // Initialize Player-specific members
    this->specialAttack = attackPower;

    // Set initial position on the grid
    grid->setPlayerPosition(this->positionX, this->positionY);
}


int Player::attack() const {
    return attackPower;  // Return the attack power (int)
}

int Player::getSpAttackPower() const {
    return specialAttack.getSpAttackPower();  // Return the special attack power (int)
}

int Player::takeDamage(int damage) { // Polymorphism - override the takeDamage function from the Character class.
    health -= damage;
    if (health < 0) {
        health = 0;
    }
    return health;
}

void Player::move(int x, int y) {
    grid->clearPosition(positionX, positionY);

    int newX = positionX + x;
    int newY = positionY + y;

    if (grid->isValidPosition(newX, newY)) {
        positionX = newX;
        positionY = newY;
    } else {
        std::cout << name << " cannot move to (" << newX << ", " << newY << ") - out of bounds!" << std::endl;
    }

    grid->setPlayerPosition(positionX, positionY);
}
