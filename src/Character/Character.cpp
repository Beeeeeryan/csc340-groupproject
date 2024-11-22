#include "Character.h"

// Default Constructor
Character::Character():
    name("Player"), 
    health(100), 
    attackPower(10), 
    positionX(0), 
    positionY(0) 
{}

void Character::move(int x, int y) {
    positionX += x;
    positionY += y;
}

bool Character::isAlive() const {
    return health > 0;
}