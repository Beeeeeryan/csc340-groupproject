// Player.h 
// Subclass of Character

#ifndef PLAYER_H
#define PLAYER_H
#include "Character.h"
#include "../SpecialAbilities/SpecialAttack.h"

class Player : public Character {
public:
    Player(Grid* grid);
    Player(std::string name, int health, int attackPower, int positionX, int positionY, Grid* grid);
    int attack() const override;
    int takeDamage(int damage) override;
    int getSpAttackPower() const;
    void move(int x, int y);
    SpecialAttack specialAttack;
};

#endif
