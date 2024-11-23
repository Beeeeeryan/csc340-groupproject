// Player.h 
// Subclass of Character

#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"  
#include "../SpecialAbilities/SpecialAttack.h" // Include SpecialAttack class

class Player : public Character {
    public:
        Player();   
        Player(std::string name, int health, int attackPower, int positionX, int positionY);
        int attack() const override;                // Override the attack function from Character
        SpecialAttack specialAttack;                // Composition - Player has a SpecialAttack object
        int takeDamage(int damage) override;        // Override the takeDamage function from Character
        int getSpAttackPower() const;               // Communicate with SpecialAttack class
};

#endif
