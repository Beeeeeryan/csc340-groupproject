// SpeciaAttack.h

#ifndef SPECIAL_ATTACK_H
#define SPECIAL_ATTACK_H

#include <iostream>

class SpecialAttack {
private:
    int attackPower;                    // Store the attack power passed from Player

public:
    SpecialAttack(); //Default constructor
    SpecialAttack(int attackPower);     // Constructor accepts attackPower
    void setSpAttackPower(int newSpAttackPower);//Setter for spAttackPower
    int getSpAttackPower();       // Getter for attackPower
};

#endif 
