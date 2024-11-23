// Character.cpp - Implementation of the abstract base class

#include "Character.h"


Character::Character(): // Default Constructor
    name("Default Character"), 
    health(100), 
    attackPower(10), 
    positionX(0), 
    positionY(0) 
{}

Character::Character(std::string name, int health, int attackPower, int positionX, int positionY): 
    name(name), 
    health(health), 
    attackPower(attackPower), 
    positionX(positionX), 
    positionY(positionY) 
{}

void Character::move(int x, int y) {
    positionX += x;
    positionY += y;
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

int Character::getHealth() const {
    return health;
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