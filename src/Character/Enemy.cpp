// Enemy.cpp

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
Enemy::Enemy(std::string name, int health, int attackPower, int positionX, int positionY): 
    Character(
        name, 
        health, 
        attackPower, 
        positionX, 
        positionY) 
{}

int Enemy::attack() const { // Polymorphism - override the attack function from the Character class.
    std::cout << (*this).name << " attacks with " << (*this).attackPower << " attack power!" << std::endl;
    return attackPower; 
}

int Enemy::takeDamage(int damage) { // Polymorphism - override the takeDamage function from the Character class.
    health -= damage;
    if (health < 0) {
        health = 0;
    }
    return health;
}