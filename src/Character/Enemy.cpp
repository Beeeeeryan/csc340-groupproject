// Enemy.cpp

#include "Enemy.h"

Enemy::Enemy(Grid& grid)
    : Character(grid)
{
    name = "Enemy";
    positionX = 2;
    positionY = 2;
    health = 200;
    grid.setEnemyPosition(positionX, positionY);  // Set initial position on the grid
}

Enemy::Enemy(std::string name, int health, int attackPower, int positionX, int positionY, Grid& grid)
    : Character(name, health, attackPower, positionX, positionY, grid)
{
    grid.setEnemyPosition(positionX, positionY);  // Set initial position on the grid
}

int Enemy::attack() const {
    return attackPower; 
}

int Enemy::takeDamage(int damage) {
    health -= damage;
    if (health < 0) {
        health = 0;
    }
    return health;
}

void Enemy::move(int x, int y) {
    grid.clearPosition(positionX, positionY);

    int newX = positionX + x;
    int newY = positionY + y;

    if (grid.isValidPosition(newX, newY)) {
        positionX = newX;
        positionY = newY;
    } else {
        std::cout << name << " cannot move to (" << newX << ", " << newY << ") - out of bounds!" << std::endl;
    }

    grid.setEnemyPosition(positionX, positionY);
}