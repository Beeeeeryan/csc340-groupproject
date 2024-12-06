// Character.h

#ifndef CHARACTER_H
#define CHARACTER_H
#include <iostream>
#include <string>
#include "../Map/Grid.h"  // Include Grid class for composition

// Struct to represent a character's position
struct Position {
    int x;
    int y;
};

class Character {
protected:
    std::string name; 
    int health;
    int attackPower;
    int positionX;
    int positionY;
    Grid* grid;  // Pointer to the grid object

public:
    Character();  // Default constructor
    Character(Grid* grid);
    Character(std::string name, int health, int attackPower, int positionX, int positionY, Grid* grid);
    virtual void move(int x, int y) = 0;  // Pure virtual function
    bool isAlive() const;
    std::string getName() const;
    int getAttackPower() const;
    Position getPosition() const;
    int getHealth() const;
    void setHealth(int health);
    int getPositionX() const;
    int getPositionY() const;
    
    virtual int attack() const;
    virtual int takeDamage(int damage);
};

#endif // CHARACTER_H


