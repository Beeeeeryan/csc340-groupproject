// Character.h

#ifndef CHARACTER_H
#define CHARACTER_H
#include <iostream>
#include <string>
#include "../Map/Grid.h"  // Include Grid class for composition

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
    Grid& grid;  // Reference to the grid object

public:
    Character(Grid& grid);
    Character(std::string name, int health, int attackPower, int positionX, int positionY, Grid& grid);
    virtual void move(int x, int y) = 0;  // Pure virtual function
    bool isAlive() const;
    std::string getName() const;
    int getAttackPower() const;
    Position getPosition() const;
    int getHealth() const;
    virtual int attack() const;
    virtual int takeDamage(int damage);
};

#endif
