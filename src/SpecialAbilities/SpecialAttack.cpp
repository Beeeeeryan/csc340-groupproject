// SpeciaAttack.cpp

#include "SpecialAttack.h"

// Constructor that takes attack power as a parameter
// Triples the attack power and makes it the special attack power.
SpecialAttack::SpecialAttack(int attackPower) : 
    attackPower(attackPower*3) 
{}

int SpecialAttack::getSpAttackPower() const {
    return attackPower;
}