// Player.h 
// Subclass of Character

#ifndef PLAYER_H
#define PLAYER_H
#include "Character.h"
#include "../SpecialAbilities/SpecialAttack.h"
#include "../Inventory/Inventory.h"

class Player : public Character {
private:
Inventory* inventory;
int enemyCounter = 0;
int armour = 3;
public:
    Player(Grid* grid);
    Player(std::string name, int health, int attackPower, int armour, int positionX, int positionY, const std::vector<Item>& items,Grid* grid);
    ~Player();
    int attack() const override;
    int takeDamage(int damage) override;
    int getSpAttackPower() const;
    void setEnemyCounter(int newEnemyCounter);
    int getEnemyCounter() const;
    void setArmour(int armour);
    int getArmour() const;
    void setPlayerHealth(int health);
    void move(int x, int y);
    SpecialAttack specialAttack;
    void addItemToInventory(const Item& newItem);
    void removeItemFromInventory(const std::string &itemName);
    void displayInventory()const;
    void sortInventory();
    void useItemFromInventory(Player &player, const std::string& itemName);
};

#endif
