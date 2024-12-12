// Character.cpp - Implementation of the abstract base class

#include "Character.h"
#include <iostream>

// Default constructor
Character::Character() {
    this->name = "Default Character";
    this->health = 100;
    this->attackPower = 10;
    this->positionX = 0;
    this->positionY = 0;
    this->grid = grid;  // Default to null if no grid is provided
}

// Default constructor with grid pointer
Character::Character(Grid* grid) {
    this->name = "Default Character";
    this->health = 100;
    this->attackPower = 10;
    this->positionX = 0;
    this->positionY = 0;
    this->grid = grid;  // Initialize the pointer member
}

// Parameterized constructor with grid pointer
Character::Character(std::string name, int health, int attackPower, int positionX, int positionY, Grid* grid) {
    this->name = name;
    this->health = health;
    this->attackPower = attackPower;
    this->positionX = positionX;
    this->positionY = positionY;
    this->grid = grid;
}


bool Character::isAlive() const {
    return health > 0;
}

std::string Character::getName() const {
    return name;
}

int Character::getAttackPower() const {
    return attackPower;
}

Position Character::getPosition() const {
    return {positionX, positionY};  // Return position as a Position struct
}

int Character::getPositionX() const {
    return this->positionX;
}

int Character::getPositionY() const {
    return this->positionY;
}

int Character::getHealth() const {
    return health;
}
void Character::setHealth(int health){
    this->health = health;
}
void Character::setAttackPower(int newAttackPower)
{
    this->attackPower = newAttackPower;
}

int Character::attack() const {
    std::cout << name << " attacks with " << attackPower << " attack power!" << std::endl;
    return attackPower; 
}

int Character::takeDamage(int damage) {
    health -= damage;
    if (health < 0) {
        health = 0;
    }
    return health;
}
