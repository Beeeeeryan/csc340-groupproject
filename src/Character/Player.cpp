#include "Player.h"

// Default Constructor
// Calls the default constructor of Character.h

Player::Player()
    : Character(), 
        specialAttack(0) {  
        name = "Player";

        positionX = 0;      // set position to bottom left corner of 3x3 grid.
        positionY = 0;
}

// Inherits from Character and initializes base class attributes (name, health, attackPower, positionX, positionY)
Player::Player(std::string name, int health, int attackPower, int positionX, int positionY)
    : Character(
        name, 
        health, 
        attackPower, 
        positionX, 
        positionY),  
        specialAttack(attackPower) {}  // Pass attackPower to SpecialAttack constructor

int Player::attack() const {
    std::cout << (*this).name << " attacks with " << (*this).attackPower << " attack power!" << std::endl;
    return attackPower;  // Return the attack power (int)
}
