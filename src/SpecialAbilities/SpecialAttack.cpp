// SpeciaAttack.cpp

#include "SpecialAttack.h"

// Constructor that takes attack power as a parameter
// Triples the attack power and makes it the special attack power.
SpecialAttack::SpecialAttack(int attackPower) : 
    attackPower(attackPower*3) 
{}

void SpecialAttack::SpAttack() const {
    std::cout << "Special attack performed with " << attackPower << " attack power!" << std::endl;
}

int SpecialAttack::getAttackPower() const {
    return (*this).attackPower;
}