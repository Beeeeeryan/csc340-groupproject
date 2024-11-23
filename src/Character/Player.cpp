// Player.cpp

#include "Player.h"
#include "../Map/Grid.h"                        // Include Grid class

// Default Constructor
// Calls the default constructor of Character.h

Player::Player(Grid& grid)
    : Character(grid),
      specialAttack(0)
{
    name = "Player";
    positionX = 0;
    positionY = 0;
}

// Inherits from Character and initializes base class attributes (name, health, attackPower, positionX, positionY)
Player::Player(std::string name, int health, int attackPower, int positionX, int positionY, Grid& grid)
    : Character(name, health, attackPower, positionX, positionY, grid),
      specialAttack(attackPower)
{}

int Player::attack() const {
    std::cout << (*this).name << " attacks with " << (*this).attackPower << " attack power!" << std::endl;
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
    grid.clearPosition(positionX, positionY);

    int newX = positionX + x;
    int newY = positionY + y;

    if (grid.isValidPosition(newX, newY)) {
        positionX = newX;
        positionY = newY;
    } else {
        std::cout << name << " cannot move to (" << newX << ", " << newY << ") - out of bounds!" << std::endl;
    }

    grid.setPlayerPosition(positionX, positionY);
}
