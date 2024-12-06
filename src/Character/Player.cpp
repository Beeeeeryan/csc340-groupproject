// Player.cpp

#include "Player.h"
#include "../Map/Grid.h"
#include <string>
#include <iostream>
using namespace std;

// Default Constructor
Player::Player(Grid* grid) {

    // Initialize Player-specific members
    this->name = "Player";
    this->positionX = 0;
    this->positionY = 0;
    this->specialAttack;
    this->grid = grid;

    // Set initial position on the grid
    grid->setPlayerPosition(this->positionX, this->positionY);
}

Player::Player(string name, int health, int attackPower, int armour, int positionX, int positionY, const vector<Item>& items, Grid* grid) {
    this->name = name;
    this->health = health;
    this->attackPower = attackPower;
    this->positionX = positionX;
    this->positionY = positionY;
    this->grid = grid;

    // Initialize Player-specific members
    this->specialAttack = attackPower;
    this->armour = armour;

    // Initialize a player's inventory
    // We use the vector of items passed to this constructor to initialize inventory
    inventory =  new Inventory(items);  // Inventory takes ownership of items passed by reference

    // Set initial position on the grid
    grid->setPlayerPosition(this->positionX, this->positionY);
}
Player::~Player(){
    delete inventory;
}


int Player::attack() const {
    return attackPower;  // Return the attack power (int)
}

int Player::getSpAttackPower() const {
    return specialAttack.getSpAttackPower();  // Return the special attack power (int)
}

void Player::setEnemyCounter(int newEnemyCounter){
    this->enemyCounter = newEnemyCounter;
}
int Player::getEnemyCounter() const
{
    return this->enemyCounter;
}
void Player::setArmour(int armour){
    this->armour = armour;
}
int Player::getArmour() const{
    return this->armour;
}
void Player::setPlayerHealth(int health){
    this->health = health;
}

int Player::takeDamage(int damage) { // Polymorphism - override the takeDamage function from the Character class.
    health -= damage;
    if (health < 0) {
        health = 0;
    }
    return health;
}

void Player::move(int x, int y) {
    grid->clearPosition(positionX, positionY);

    int newX = positionX + x;
    int newY = positionY + y;

    if (grid->isValidPosition(newX, newY)) {
        positionX = newX;
        positionY = newY;
    } else {
        cout << name << " cannot move to (" << newX << ", " << newY << ") - out of bounds!" << endl;
    }

    grid->setPlayerPosition(positionX, positionY);
}

void Player::addItemToInventory(const Item& newItem){
    inventory->addItem(newItem);
}
void Player::removeItemFromInventory(const string &itemName){
    inventory->removeItem(itemName);
}
void Player::displayInventory() const {
    inventory->displayInventory();
}
void Player::sortInventory(){
    inventory->sortItems();
}
void Player::useItemFromInventory(Player &player, const string& itemName){
    Item* targetItem = inventory->searchItem(itemName);
    bool found = inventory->useItem(*targetItem, player);
    if(!found)
        cout << "Sorry couldn't find your item" << endl;
}