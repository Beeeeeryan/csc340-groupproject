// Enemy.h
// Subclass of Character

#ifndef ENEMY_H
#define ENEMY_H
#include "Character.h"  

class Enemy: public Character {
    private:

    public:
        Enemy();    // Default Constructor
                    // calls the default constructor of Character.h
        Enemy(std::string name, int health, int attackPower, int positionX, int positionY);
        int attack() const override;            // Polymorphism - override the attack function from the Character class.
        int takeDamage(int damage) override;    // Polymorphism - override the takeDamage function from the Character class.
};
#endif