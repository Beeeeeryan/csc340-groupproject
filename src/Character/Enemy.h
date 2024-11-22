#ifndef ENEMY_H
#define ENEMY_H

#include "Character.h"  

class Enemy: public Character {
    private:

    public:
        Enemy();    // Default Constructor
                    // calls the default constructor of Character.h

        Enemy(std::string name, int health, int attackPower, int positionX, int positionY);
};
#endif