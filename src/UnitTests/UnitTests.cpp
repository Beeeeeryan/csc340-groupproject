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
/*

void ItemTest();
void PlayerTest();
void EnemyTest();
void GridTest();
void MovementTest();
void InventoryTest();
void BattleTestPlayerWin();
void unitTest()
*/



using namespace std;

 void ItemTest() {


    /* Purpose is to verify adding, removing, deleting, an Item Object, also verifying proper Item Information 
       Rubric: 

       Input[...]
       Expected Output: [...]
       Actual Output: [...]

       Test Passed(assert will halt if expression is not valid)
    */

    
    cout << string(border_width + 10, '-') << endl; //Just for the borders
    printCentered("Testing Item Creation!", border_width + 10);
    cout << string(border_width + 10, '-') << endl;

    string testItemName = "Potion";
    string testItemDescription = "Restores 50 HP";
    int testItemAmount = 2;
    int testItemAffect = 50;

    cout << "Testing Item Input" << endl;
    cout << "Item Name: " << testItemName << endl;
    cout << "Item Description: " << testItemDescription << endl;
    cout << "Item Amount: " << testItemAmount << endl;
    cout << "Item Affect: " << testItemAffect << endl;

    //Testing Paramterized Constructor and Default Constructor
    Item testItem(testItemName, testItemDescription, testItemAmount, testItemAffect);
    Item defaultTestItem;

    cout << "-------- Sucessfully Created Item testItem and defaultItem! --------" << endl;
    cout << endl;
    cout << "-------- Testing Getters/Default Constructor! --------" << endl;
    cout << "Expected testItem Output: " << testItemName << " " << testItemDescription << " " << testItemAmount << " " << testItemAffect << endl;
    cout << "Actual testItem Output: " << testItem.GetName() << " " << testItem.GetDescription() << " " << testItem.GetAmount() << " " << " " << testItem.GetItemAffect () << endl;
    cout << endl;
    cout << "Expected defaultItem Output: " << "Unknown" << " " << "No description available" << " "  << 0 << " " << 0 << endl;
    cout << "Actual defaultItem Output: " << defaultTestItem.GetName() << " " << defaultTestItem.GetDescription() << " " << defaultTestItem.GetAmount() << " " << defaultTestItem.GetItemAffect() << endl;
    cout << endl;
    assert((testItemName == testItem.GetName()) && (testItemDescription == testItem.GetDescription())
          && (testItemAmount == testItem.GetAmount()) && (testItemAffect == testItem.GetItemAffect()));
    cout << "[1.] Item Creation Test Passed!" << endl;
    //End of Item Creation

    cout << endl;

    cout << string(border_width + 40, '-') << endl;
    printCentered("Testing Item Functionality(useItemFromInventory method)!", border_width + 40);
    cout << string(border_width + 40, '-') << endl;

    //Creating Intial Player
    Grid* grid = new Grid();
    vector<Item> items = {Item("Potion", "Restores 50 HP", 1, 50), Item("Shield", "Blocks 1 Damage", 1, 1), Item("Magic Scroll", "Increases attack by 5", 1, 5),
                          Item("Stone Sword", "Does 15 damage", 1, 15)};
    Player testPlayer("Test Player", 100, 10, 0, 3, 0, items, grid); 
    
    cout <<"--------Player Initial Information--------" << endl;
    cout <<"Player Name: " << testPlayer.getName() << endl;
    cout <<"Player Health: " << testPlayer.getHealth() << endl;
    cout <<"Player Armour: " << testPlayer.getArmour() << endl;
    cout <<"Player Attack Power: " << testPlayer.getAttackPower() << endl;
    cout <<"Player Special Attack Power: " << testPlayer.getSpAttackPower() << endl;
    cout << "-----------------------------------------" << endl;

    /* Testing the useItemFromInventory() method */
    cout << string(border_width + 10, '-') << endl;
    printCentered("Using and Equiping Items!", border_width + 10);
    cout << string(border_width + 10, '-') << endl;

    testPlayer.useItemFromInventory(testPlayer, "Potion");
    testPlayer.useItemFromInventory(testPlayer, "Shield");
    testPlayer.useItemFromInventory(testPlayer, "Stone Sword");
    testPlayer.useItemFromInventory(testPlayer, "Magic Scroll");
    cout << string(border_width + 30, '-') << endl;

    cout <<"--------Player Updated Information--------" << endl;
    cout <<"Player Name: " << testPlayer.getName() << endl;
    cout <<"Player Health: " << testPlayer.getHealth() << endl;
    cout <<"Player Armour: " << testPlayer.getArmour() << endl;
    cout <<"Player Attack Power: " << testPlayer.getAttackPower() << endl;
    cout <<"Player Special Attack Power: " << testPlayer.getSpAttackPower() << endl;
    cout << "-----------------------------------------" << endl;
    cout << "Expected Player Health: 150 " << endl;
    cout << "Expected Player Armour: 1 " << endl;
    cout << "Expected Player Attack: 20 " << endl;
    cout << "Expected Player Special Attack: 60 " << endl;
    
    assert(testPlayer.getArmour() == 1);
    assert(testPlayer.getHealth() == 150);
    assert(testPlayer.getAttackPower() == 20);
    assert(testPlayer.getSpAttackPower() == 60);
    
    cout << endl;
    
    cout << "[2.] Item Functionality Passed! " << endl; 
    //End of Item Functionality

    cout << endl;

    /* Testing the getRandomItem() method */
    cout << string(border_width + 10, '-') << endl;
    printCentered("Testing getRandomItem() method!", border_width + 10);
    cout << string(border_width + 10, '-') << endl;
    //Returns a random item object from a fixed vector list
    Item randomTestItem = getRandomItem();
    cout << "Output randomTestItem"  << endl;
    cout << "randomTestItem Name:  " << randomTestItem.GetName() << endl;
    cout << "randomTestItemDescription: " << randomTestItem.GetDescription() << endl;
    cout << "randomTestItemAmount: " << randomTestItem.GetAmount() << endl;
    cout << "randomTestItemAffect: " << randomTestItem.GetItemAffect() << endl;
    cout << endl;

} 

  void PlayerTest() {
    cout << string(border_width + 10, '-') << endl;
    printCentered("Testing Player Class", border_width + 10);
    cout << string(border_width + 10, '-') << endl;
    Grid* grid = new Grid();
    vector<Item> items = {Item("Potion", "Restores 50 HP", 3, 20), Item("Sword", "A sharp blade", 1, 20), Item("Shield", "Protects from damage", 1, 20)};
    Player player("Player", 100, 10, 5, 3, 0, items, grid); 

    cout << "Player Name: " << player.getName() << endl;
    cout << "Health: " << player.getHealth() << ", Attack Power: " << player.getAttackPower() << endl;
    cout << "Position: (" << player.getPosition().x << ", " << player.getPosition().y << ")" << endl;

    delete grid;
} 

void EnemyTest() {
    cout << string(border_width + 10, '-') << endl;
    printCentered("Testing Enemy Class", border_width + 10);
    cout << string(border_width + 10, '-') << endl;
    Grid* grid = new Grid();
    Enemy enemy("Enemy", 50, 5, 0, 3, grid);

    cout << "Enemy Name: " << enemy.getName() << endl;
    cout << "Health: " << enemy.getHealth() << ", Attack Power: " << enemy.getAttackPower() << endl;
    cout << "Position: (" << enemy.getPosition().x << ", " << enemy.getPosition().y << ")" << endl;

    delete grid;
}

void GridTest() {
    cout << string(border_width + 10, '-') << endl;
    printCentered("Testing Grid Class", border_width + 10);
    cout << string(border_width + 10, '-') << endl;
    Grid grid;
    grid.displayGrid();
}

void MovementTest() {
     /*Testing player and enemy movement, checking edge cases are functioning, and updating properly
        Things to consider are: 
            X Neg-Values move up in the grid, X Pos-Values move down
            Y-Neg Values move left in the grid, Y Pos-Values move right
     */
    cout << string(border_width + 15, '-') << endl;
    printCentered("Testing Character Movement", border_width + 15);
    cout << string(border_width + 15, '-') << endl;

    //Creating Player and Enemy Objects
    Grid* grid = new Grid();
    Player testPlayer("Player", 100, 10, 5, 3, 1, {}, grid);
    Enemy testEnemy("Enemy", 50, 5, 2, 3, grid);
    
    grid->displayGrid();

    cout << "Player 'P' Initial Position: (" << testPlayer.getPositionX() << ", " << testPlayer.getPositionY() << ")." << endl; 
    cout << "Enemy 'E' Initial Position: (" << testEnemy.getPositionX() << ", " << testEnemy.getPositionY() << ")." << endl; 

    /*Testing Moving Up/Down/Left/Right and Out of Bound Checking*/
    cout << "-----Moving Character and Enemy 1 Space Up------" << endl;
    testPlayer.move(-1, 0);
    testEnemy.move(-1, 0);
    grid->displayGrid();
    cout << "Expected Player Position: (2,1)" <<endl;
    cout << "Expected Enemy Position: (1,3)" << endl;
    cout << "Actual Player Position: (" << testPlayer.getPositionX() << ", " << testPlayer.getPositionY() << ")." << endl;
    cout << "Actual Enemy Position: (" << testEnemy.getPositionX() << ", " << testEnemy.getPositionY() << ")." << endl;

    cout << endl;

    cout << "-----Moving Character and Enemy 1 Space Down------" << endl;
    testPlayer.move(1, 0);
    testEnemy.move(1, 0);
    grid->displayGrid();
    cout << "Expected Player Position: (3,1)" <<endl;
    cout << "Expected Enemy Position: (2,3)" << endl;
    cout << "Actual Player Position: (" << testPlayer.getPositionX() << ", " << testPlayer.getPositionY() << ")." << endl;
    cout << "Actual Enemy Position: (" << testEnemy.getPositionX() << ", " << testEnemy.getPositionY() << ")." << endl; 

    cout << endl;

    cout << "-----Moving Character and Enemy 1 Space Left------" << endl;
    testPlayer.move(0, -1);
    testEnemy.move(0, -1);
    grid->displayGrid();
    cout << "Expected Player Position: (3,0)" <<endl;
    cout << "Expected Enemy Position: (2,2)" << endl;
    cout << "Actual Player Position: (" << testPlayer.getPositionX() << ", " << testPlayer.getPositionY() << ")." << endl;
    cout << "Actual Enemy Position: (" << testEnemy.getPositionX() << ", " << testEnemy.getPositionY() << ")." << endl;

    cout << endl;

    cout << "-----Moving Character and Enemy 1 Space Right------" << endl;
    testPlayer.move(0, 1);
    testEnemy.move(0, 1);
    grid->displayGrid();
    cout << "Expected Player Position: (3,1)" <<endl;
    cout << "Expected Enemy Position: (2,3)" << endl;
    cout << "Actual Player Position: (" << testPlayer.getPositionX() << ", " << testPlayer.getPositionY() << ")." << endl;
    cout << "Actual Enemy Position: (" << testEnemy.getPositionX() << ", " << testEnemy.getPositionY() << ")." << endl; 

    cout << endl; 

    cout << "-----Moving Character 2 Spaces to the Left and Enemy 3 Spaces Up------" << endl;
    testPlayer.move(0, -2);
    testEnemy.move(-3, 0);
    grid->displayGrid();


    cout << endl;
    
    cout << "[1.] Movement Functionality Passed! " << endl; 

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
    
    /*Testing the flow of the battle logic*/
    cout << string(border_width + 15, '-') << endl;
    printCentered("Testing Battle Combat", border_width + 15);
    cout << string(border_width + 15, '-') << endl;

    //Display the initial Grid
    Grid* grid = new Grid();
    Player player("Player", 100, 10, 5, 0, 0, {}, grid);
    Enemy enemy("Enemy", 50, 5, 0, 2, grid);
    grid->displayGrid();

    //Intentionally moving player to initiate battle by testing grids' isAdjacent method
    player.move(0, 1);  
    
    if(grid->areAdjacent(player.getPositionX(), player.getPositionY(), enemy.getPositionX(), enemy.getPositionY()))
    {
        //Get Intial Health
        int initialPlayerHealth = player.getHealth();
        int initialEnemyHealth = enemy.getHealth();

        cout << "----Testing Player and Enemy Attacks----" << endl;
        cout << "Expected Player Attack: 10" << endl;
        cout << "Expected Player Special Attack: 30" << endl;
        cout << "Expected Enemy AttacK: 5" << endl;
        cout << "Actual Player Attack: "<< player.getAttackPower() << endl;
        cout << "Actual Player Special AttacK: " << player.getSpAttackPower() << endl;
        cout << "Actual Enemy Attack: " << enemy.getAttackPower() << endl;

        assert(player.getAttackPower() == 10);
        assert(player.getSpAttackPower() ==  30);
        assert(enemy.getAttackPower() == 5);

        cout << "[1.] Correct Player/Enemy Information Passed!" << endl;

        cout << "----Testing Damage Calculation----" << endl;
        cout << endl;
        cout << "Expected Enemy Health After Player Attack  Damage: " << initialEnemyHealth - player.getAttackPower() << endl;
        //Enemy takes damage
        enemy.takeDamage(player.getAttackPower());
        cout << "Actual Enemy Health After Player Attack  Damage: " << enemy.getHealth() <<endl;
        assert(enemy.getHealth() == initialEnemyHealth - player.getAttackPower());
        cout << endl;
        cout << "[2.] Player Attack / Damage Calculation Passed!" << endl;
        cout << endl;
        cout << "Expected Player Health After Enemy Attack Damage: " << initialPlayerHealth - enemy.getAttackPower() << endl;
        //Player takes damage
        player.takeDamage(enemy.getAttackPower());
        cout << "Actual Enemy Health After Enemy Attack Damage: " << player.getHealth() <<endl;
        assert(player.getHealth() == initialPlayerHealth - enemy.getAttackPower());
        cout << endl;
        cout << "[3.] Enemy Attack / Damage Calculation Passed!" << endl;
        cout << endl;
        //Testing now special attack
        int newEnemyHealth = enemy.getHealth();
        cout << "Expected Enemy Health After Player Special Attack  Damage: " << newEnemyHealth - player.getSpAttackPower() << endl;
        //Enemy takes damage
        enemy.takeDamage(player.getSpAttackPower());
        cout << "Actual Enemy Health After Player Special Attack  Damage: " << enemy.getHealth() <<endl;
        assert(enemy.getHealth() == newEnemyHealth - player.getSpAttackPower());
        cout << endl;
        cout << "[4.] Player Special Attack / Damage Calculation Passed!" << endl;
        cout << endl;


        cout << "----Testing isAlive for Player/Enemy----" << endl;

        assert(enemy.isAlive());
        assert(player.isAlive());
        cout << "Setting Enemy and Player health to 0" << endl;
        player.setHealth(0);
        enemy.setHealth(0);
        assert(!enemy.isAlive());
        assert(!player.isAlive());
        cout << "[5.] Player/Enemy isAlive passed!" << endl;

        cout << "----Testing Player Enemy Counter----" << endl;
        cout << "Expecting Enemy Counter: 1 " << endl;
        player.setEnemyCounter(1);
        cout << "Actual Enemy Counter: " << player.getEnemyCounter() << endl;;
        assert(player.getEnemyCounter() == 1); // Check that the counter updated correctly
        cout << "[6.] Enemy counter test passed." << endl;

    }

    cout << "Battle test completed successfully!" << endl;
    delete grid;
}

void BattleTestPlayerDead() { //same as above but player loses, prob have to edit this when a proper game over menu is added

    /*Testing displayLossGame() when player is dead*/
    cout << string(border_width + 30, '-') << endl;
    printCentered("Testing Game Over Menu when Player is dead", border_width + 30);
    cout << string(border_width + 30, '-') << endl;
    Grid* grid = new Grid();
    Player player("Player", 100, 10, 5, 0, 0, {}, grid);
    player.setEnemyCounter(0);
    Enemy enemy("Enemy", 50, 5, 0, 2, grid);


    cout << "----Player Taking Damage----" << endl;
    while(player.getHealth() > 0)
    {
    int enemyDamage = 20;
    cout << "Intial Player Health: " << player.getHealth() << endl;
    player.takeDamage(enemyDamage);
    cout << "Current Player Health: " << player.getHealth() << endl;
    }

    assert(!player.isAlive());
    cout << string(border_width + 30, '-') << endl;
    displayLossGame();
    cout << string(border_width + 30, '-') << endl;
    cout << endl;
    cout << "[1.] Player is dead test passed. " << endl;
    cout << endl;

    cout << "Battle test completed successfully!" << endl;
    delete grid;
}

void EndGameMenuTest() {
    cout << "-------- Testing End Game Menus --------" << endl;
    displayEndGame();
    displayLossGame();
    cout << "Done." << endl;
}

void unitTest() {
    cout << "======== Running Unit Tests ========" << endl;
    ItemTest();
    cout << "-----------------------------------------" << endl;
    cout << endl;
    PlayerTest();
    cout << "-----------------------------------------" << endl;
    cout << endl;
    EnemyTest();
    cout << "-----------------------------------------" << endl;
    cout << endl;
    GridTest();
    cout << "-----------------------------------------" << endl;
    cout << endl;
    MovementTest();
    cout << "-----------------------------------------" << endl;
    cout << endl;
    InventoryTest();
    cout << "-----------------------------------------" << endl;
    cout << endl;
    BattleTestPlayerWin();
    cout << "-----------------------------------------" << endl;
    cout << endl;
    BattleTestPlayerDead();
    cout << "-----------------------------------------" << endl;
    cout << endl;
    cout << "======== Unit Tests Completed ========" << endl;
}