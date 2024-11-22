#include "Player.h"

// Default Constructor
// Calls the default constructor of Character.h

Player::Player()
    : Character() {  
        name = "Player";

        positionX = 0;      // set position to bottom left corner of 3x3 grid.
        positionY = 0;
}

// Inherits from Character and initializes base class attributes (name, health, attackPower, positionX, positionY)
Player::Player(std::string name, int health, int attackPower, int positionX, int positionY)
    : Character(name, health, attackPower, positionX, positionY) {
}

void Player::attack() const {
    // We use (*this) to access the object's members when the function is marked as const because this is treated as a pointer to a constant object.
    std::cout << (*this).name << " attacks with " << (*this).attackPower << " attack power!" << std::endl;
}