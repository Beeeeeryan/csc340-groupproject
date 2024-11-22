// Character.cpp - Implementation of the abstract base class

#include "Character.h"


Character::Character(): // Default Constructor
    name("Character"), 
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

void Character::attack() const {
    // We use (*this) to access the object's members when the function is marked as const because this is treated as a pointer to a constant object.
    std::cout << (*this).name << " attacks with " << (*this).attackPower << " attack power!" << std::endl;
}
