#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"  

class Player: public Character {
    public:
        
        Player();   // Default Constructor
                    // calls the default constructor of Character.h
                    
        Player(std::string name, int health, int attackPower, int positionX, int positionY);
};
#endif