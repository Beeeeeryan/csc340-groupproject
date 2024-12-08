#include <iostream>
#include <string>
#include <vector>
#include <cstdlib> 
#include <ctime>   
#include <cassert>
#include "../Character/Character.h"
#include "../Character/Player.h"
#include "../Character/Enemy.h"
#include "../Map/Grid.h"
#include "../UI/UserInterface.h"
#include "../Inventory/Inventory.h"
#include "../Inventory/Item.h"
#include "../Inventory/Node.h"
#include "UnitTests.h"

using namespace std;

 void ItemTest() {
    cout << "-------- Testing Item Class! --------" << endl;
        std::vector<Item> Itemtesting = { // It would be easier to test this if the items were global so I don't have to hardcode this, but it should work for now
        Item("Health Potion", "Restores 50 HP", 1, 50),
        Item("Mana Potion", "Restores 30 MP", 1, 30),
        Item("Gold Coin", "A shiny gold coin", 10, 20),
        Item("Magic Scroll", "Contains an ancient spell", 1, 20),
        Item("Magic Scroll", "Contains an ancient spell", 1, 20),
        Item("Iron Sword", "A sturdy weapon with extra damage", 1, 20),
        Item("Shield", "Provides extra defense in battle", 1, 20)
    };

    for (const Item& item : Itemtesting) {
        std::cout << "Name: " << item.GetName() << std::endl;
        std::cout << "Description: " << item.GetDescription() << std::endl;
        std::cout << "Quantity: " << item.GetAmount() << std::endl;
        std::cout << "-------------------------------" << std::endl;
    }

    cout << "-------- Testing Item Functionality! --------" << endl;

    Grid* grid = new Grid();
    vector<Item> items = {Item("Potion", "Restores 50 HP", 1, 50), Item("Shield", "Protects from damage", 1, 1)};
    Player player("Player", 100, 10, 5, 3, 0, items, grid); 
    int initialPlayerHealth = player.getHealth();
    int initialPlayerArmor = player.getArmour();

    player.useItemFromInventory(player, "Potion");
    assert(player.getHealth() == initialPlayerHealth + 50);
    cout << "Potion test passed." << std::endl;

    player.useItemFromInventory(player, "Shield");
    assert(player.getArmour() == initialPlayerArmor + 1);
    cout << "Armor test passed." << std::endl;

} 

  void PlayerTest() {
    cout << "-------- Testing Player Class! --------" << endl;
    Grid* grid = new Grid();
    vector<Item> items = {Item("Potion", "Restores 50 HP", 3, 20), Item("Sword", "A sharp blade", 1, 20), Item("Shield", "Protects from damage", 1, 20)};
    Player player("Player", 100, 10, 5, 3, 0, items, grid); 

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
    Player player("Player", 100, 10, 5, 3, 0, {}, grid);
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
    vector<Item> items = {Item("Potion", "Restores 50 HP", 3, 50), Item("Sword", "A sharp blade", 1, 50), Item("Shield", "Protects from damage", 1, 50)};
    Player player("Player", 100, 10, 5, 3, 0, items, grid);

    cout << "Initial Inventory: " << endl;
    player.displayInventory();

    player.addItemToInventory(Item("Helmet", "Shiny helmet", 1, 50));
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

void BattleTestPlayerWin() { //might change this if attack and special attack are changed to be in a function, but should work
    cout << "-------- Testing Battle (Player Win) --------" << endl;
    Grid* grid = new Grid();
    Player player("Player", 100, 10, 5, 0, 0, {}, grid);
    player.setEnemyCounter(0);
    Enemy enemy("Enemy", 50, 5, 0, 2, grid);
    player.move(1, 0);
    displayBattleLog(player, enemy);

    int initialPlayerHealth = player.getHealth();
    int initialEnemyHealth = enemy.getHealth();

    cout << "Testing Player and Enemy attacks..." << std::endl;

    int playerDamage = player.attack();
    enemy.takeDamage(playerDamage);
    assert(enemy.getHealth() == initialEnemyHealth - playerDamage);
    cout << "Player attack test passed." << std::endl;

    int enemyDamage = enemy.attack();
    player.takeDamage(enemyDamage);
    assert(player.getHealth() == initialPlayerHealth - enemyDamage);
    cout << "Enemy attack test passed." << std::endl;

    cout << "Testing special attack..." << std::endl;
    int specialDamage = player.getSpAttackPower();
    enemy.takeDamage(specialDamage);
    assert(enemy.getHealth() <= 0); // Enemy Dead?
    cout << "Special attack test passed." << std::endl;

    assert(player.isAlive());
    std::cout << "Player is alive test passed." << std::endl;

    player.setEnemyCounter(player.getEnemyCounter() + 1);
    assert(player.getEnemyCounter() == 1); // Check that the counter updated correctly
    std::cout << "Enemy counter test passed." << std::endl;

    std::cout << "Battle test completed successfully!" << std::endl;
    delete grid;
}

void BattleTestPlayerDead() { //same as above but player loses, prob have to edit this when a proper game over menu is added
    cout << "-------- Testing Battle (Player Lose) --------" << endl;
    Grid* grid = new Grid();
    Player player("Player", 1, 10, 5, 0, 0, {}, grid);
    player.setEnemyCounter(0);
    Enemy enemy("Enemy", 50, 5, 0, 2, grid);
    player.move(1, 0);
    displayBattleLog(player, enemy);

    cout << "Testing Enemy attacks..." << std::endl;

    int enemyDamage = enemy.attack();
    player.takeDamage(enemyDamage);

    assert(!player.isAlive());
    std::cout << "Player is dead test passed." << std::endl;

    std::cout << "Battle test completed successfully!" << std::endl;
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
    BattleTestPlayerWin();
    BattleTestPlayerDead();
    cout << "======== Unit Tests Completed ========" << endl;
}
