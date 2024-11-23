// Enemy.h

#ifndef ENEMY_H
#define ENEMY_H
#include "Character.h"

class Enemy : public Character {
public:
    Enemy(Grid& grid);
    Enemy(std::string name, int health, int attackPower, int positionX, int positionY, Grid& grid);
    int attack() const override;
    int takeDamage(int damage) override;
    void move(int x, int y) override;  // Override the pure virtual function
};
#endif
