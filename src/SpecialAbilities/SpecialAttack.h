// SpeciaAttack.h

#ifndef SPECIAL_ATTACK_H
#define SPECIAL_ATTACK_H

#include <iostream>

class SpecialAttack {
private:
    int attackPower;  // Store the attack power passed from Player

public:
    SpecialAttack(int attackPower);  // Constructor accepts attackPower
    int getSpAttackPower() const; // Getter for attackPower
};

#endif 
