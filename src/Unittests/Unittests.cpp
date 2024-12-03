#include <iostream>
#include <string>
#include <vector>
#include "Grid.h"
#include "Player.h"
#include "Enemy.h"
#include "Item.h"

using namespace std;

void ItemTest() {
    cout << "-------- Testing Item Class! --------" << endl;
    Item potion("Potion", "Restores 50 HP", 3);
    Item sword("Sword", "A sharp blade", 1);
    Item shield("Shield", "Protects from damage", 1);
}

void PlayerTest() {
    cout << "-------- Testing Player Class! --------" << endl;
    Grid* grid = new Grid();
    vector<Item> items = {Item("Potion", "Restores 50 HP", 3), Item("Sword", "A sharp blade", 1), Item("Shield", "Protects from damage", 1)};
    Player player("Player", 100, 10, 3, 0, items, grid);

    cout << "Player Name: " << player.getName() << endl;
    cout << "Health: " << player.getHealth() << ", Attack Power: " << player.getAttackPower() << endl;
    cout << "Position: (" << player.getPosition().x << ", " << player.getPosition().y << ")" << endl;

    delete grid;
}

void EnemyTest() {
    cout << "-------- Testing Enemy Class! --------" << endl;
    Grid* grid = new Grid();
    Enemy enemy("Enemy", 50, 5, 0, 3, grid);

    cout << "Enemy Name: " << enemy.getName() << endl;
    cout << "Health: " << enemy.getHealth() << ", Attack Power: " << enemy.getAttackPower() << endl;
    cout << "Position: (" << enemy.getPosition().x << ", " << enemy.getPosition().y << ")" << endl;

    delete grid;
}

void GridTest() {
    cout << "-------- Testing Grid Class! --------" << endl;
    Grid grid;
    grid.displayGrid();
}

void MovementTest() {
    cout << "-------- Testing Movement --------" << endl;
    Grid* grid = new Grid();
    Player player("Player", 100, 10, 3, 0, {}, grid);
    Enemy enemy("Enemy", 50, 5, 0, 3, grid);

    cout << "Initial Positions: Player (" << player.getPosition().x << ", " << player.getPosition().y << "), "
         << "Enemy (" << enemy.getPosition().x << ", " << enemy.getPosition().y << ")" << endl;

    player.move(-1, 0);
    enemy.move(0, -1);
    cout << "After Move: Player (" << player.getPosition().x << ", " << player.getPosition().y << "), "
         << "Enemy (" << enemy.getPosition().x << ", " << enemy.getPosition().y << ")" << endl;

    delete grid;
}

void InventoryTest() {
    cout << "-------- Testing Inventory Operations --------" << endl;
    Grid* grid = new Grid();
    vector<Item> items = {Item("Potion", "Restores 50 HP", 3), Item("Sword", "A sharp blade", 1), Item("Shield", "Protects from damage", 1)};
    Player player("Player", 100, 10, 3, 0, items, grid);

    cout << "Initial Inventory: " << endl;
    player.displayInventory();

    player.addItemToInventory(Item("Helmet", "Shiny helmet", 1));
    cout << "After Adding Helmet: " << endl;
    player.displayInventory();

    player.removeItemFromInventory("Potion");
    cout << "After Removing Potion: " << endl;
    player.displayInventory();

    player.sortInventory();
    cout << "After Sorting Inventory: " << endl;
    player.displayInventory();

    delete grid;
}

void unitTest() {
    cout << "======== Running Unit Tests ========" << endl;
    ItemTest();
    PlayerTest();
    EnemyTest();
    GridTest();
    MovementTest();
    InventoryTest();
    cout << "======== Unit Tests Completed ========" << endl;
}
