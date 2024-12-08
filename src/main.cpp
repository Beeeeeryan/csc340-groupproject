// main.cpp

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib> 
#include <ctime>   
#include <limits>
#include "Character.h"
#include "Player.h"
#include "Enemy.h"
#include "Grid.h"
#include "UserInterface.h"
#include "Inventory.h"
#include "Item.h"
#include "Node.h"
#include "UnitTests.h"

using namespace std;


// Generate a random number inclusive
int getRandomValue(int min, int max) {
    return rand() % (max - min + 1) + min;  
}
int getMenuChoice() {
    int userInput;
    // Print the top border
    cout << string(border_width, '-') << endl;
    printCentered(" >> [Menu] Enter a choice", border_width);
    // Print the bottom border
    cout << string(border_width, '-') << endl;
    cin >> userInput;
    // Check if input was successful
        if (cin.fail()) {  // If cin fails to read an integer
            cin.clear();  // Clear the error state
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard invalid input
            cout << "Invalid input. Please enter a valid integer.\n";
            return getMenuChoice();
        }

    if (userInput < min_menu_option - 2 || userInput > max_menu_option) {
        cout << "Error! Input must be a number between " << min_menu_option << " and " << max_menu_option
             << " ,or " << min_menu_option - 1 << " to exit." << endl;
        return getMenuChoice(); 
    }
   
    return userInput;
}

void unitTest() {
    Grid* grid = new Grid ();
    string playerName = "Player";
    string enemyName = "Slime";
    // Create some items
    Item potion("Potion", "Restores 50 HP", 3, 50);
    Item sword("Sword", "A sharp blade adds 2 attack power", 1, 2);
    Item shield("Shield", "Blocks 3 damage", 1, 3);
    // Create a vector of items
    vector<Item> items = {potion, sword, shield};

    Player player1(playerName, 100, 12, 3, 3, 0, items, grid);
    player1.displayInventory();
    Enemy enemy(enemyName, 50, 5, 0, 3, grid);

    
    // Display player and enemy details
    cout << "-------- Testing Player Class! --------" << endl;
    cout << endl;
    Position pos2 = player1.getPosition();
    cout << "Welcome " << player1.getName() + "!" << endl;
    cout << "Is " << player1.getName() << " alive? " << (player1.isAlive() ? "Yes" : "No") << endl;
    cout << player1.getName() << " has " << player1.getHealth() << " health!" << endl;
    cout << player1.getName() << " has " << player1.getAttackPower() << " attack power!" << endl;
    player1.attack();
    cout << player1.getName() << " is positioned at (" << pos2.x << ", " << pos2.y << ")" << endl;
    cout << endl;

    cout << "-------- Testing Enemy Class! --------" << endl;
    cout << endl;
    Position pos3 = enemy.getPosition();
    cout << "Welcome " << enemy.getName() + "!" << endl;
    cout << "Is " << enemy.getName() << " alive? " << (enemy.isAlive() ? "Yes" : "No") << endl;
    cout << enemy.getName() << " has " << enemy.getHealth() << " health!" << endl;
    cout << enemy.getName() << " has " << enemy.getAttackPower() << " attack power!" << endl;
    enemy.attack();
    cout << enemy.getName() << " is positioned at (" << pos3.x << ", " << pos3.y << ")" << endl;
    cout << endl;

    // Display the initial grid
    cout << "-------- Initial Grid State --------" << endl;
    cout << endl;
    grid->displayGrid();
    cout << endl;


    cout << "-------- Testing Player Movement! --------" << endl;
    // grid.setPlayerPosition(player1.getPosition().x, player1.getPosition().y);
    // grid.setEnemyPosition(enemy.getPosition().x, enemy.getPosition().y);

    grid->displayGrid();
    cout << endl;

    //X Neg-Values move up in the grid, X Pos-Values move down
    //Y-Neg Values move left in the grid, Y Pos-Values move right
  
    cout << "P moves up one Spaces, E moves left one spaces" << endl;
    player1.move(-1, 0);
    enemy.move(0, -1); 

    grid->displayGrid();
    cout << endl;

    cout << "P moves up one Spaces, E moves left one spaces" << endl; //Should expect battle interface 
    player1.move(-1, 0);
    enemy.move(0, -1); 
    grid->displayGrid();

    
    cout << endl;


    cout << "P moves up one Spaces, E moves left one spaces" << endl;
    player1.move(-1, 0);
    enemy.move(0, -1); 

 
    cout << endl;
    cout <<"Checking players inventory----------" << endl;
    cout << endl;
    cout <<"Player's inventory: "<< endl;
    player1.displayInventory();
    cout << endl;
    cout <<"Checking add item in player inventory-------" << endl;
    Item blackShield("Black Shield", "Shiny helmet blocks 5 damage", 1, 5);
    player1.addItemToInventory(blackShield);
    cout << endl;
    cout << "Added checking player inventory-----" << endl;
    player1.displayInventory();
    cout << "Removing an item named Potion" << endl;
    player1.removeItemFromInventory("Potion");
    cout << "Displaying player inventory after deletion" << endl;
    player1.displayInventory();
    cout << "Test sorted inventory alphabetically" << endl;
    player1.sortInventory();
    player1.displayInventory();
 


    cout << "Unit Test Concluded!" <<endl;
    cout << endl;


}

int choiceAfterStartGame() {
    int userInput;
    
    cout << "Attack or Special Attack?" << endl;
    cout << "(" << ATTACK << ")" << " ATTACK" << endl;
    cout << "(" << SPECIAL_ATTACK << ")" << " SPECIAL ATTACK" << endl;


    cin >> userInput; 

    if (userInput < 1|| userInput > 2) {
        cout << "Error! Input must be a number between " << 1 << " and " << 2
             << " ,or " << 0 << " to exit." << endl;
        return choiceAfterStartGame(); 
    }
   
    return userInput;
}

void startGame() {
    int choice;
    Grid *grid =  new Grid();
    string playerName = "Player";
    string enemyName = "Slime";
    // Create some items
    Item potion("Potion", "Restores 50 HP", 3, 50);
    Item sword("Sword", "A sharp blade adds 2 attack power", 1, 2);
    Item shield("Wooden Shield", "Blocks 4 damage", 1, 4); //type of armour
    // Create a vector of items
    vector<Item> items = {potion, sword, shield};
    Player player(playerName, 100, 13, 0, 3, 0, items, grid); //Starting pos bottom left
    Enemy enemy(enemyName, 50, 5, 0, 3, grid); //Starting pos top right
    

    do
    {
        //What will always displays
        grid->displayGrid();
        cout << "-------------------------------" << endl;
        displayMovementOption();
        cout << "-------------------------------" << endl;
        cout << "Player health: " << player.getHealth() << endl;
        cout << "Armour Rating: " << player.getArmour() << endl;
        cout << "Enemy health: " << enemy.getHealth() << endl;
        cout << "Enemies defeated: " << player.getEnemyCounter() << endl;
        cout << "-------------------------------" << endl;


    

        choice = getMovementOption();
        //Update movement on the grid
        //X Neg-Values move up in the grid, X Pos-Values move down
        //Y-Neg Values move left in the grid, Y Pos-Values move right
        srand(time(0));
        int x = getRandomValue(-1, 1);
        int y = getRandomValue(-1, 1);
        if(choice == UP)
        {
            player.move(-1, 0);
            //Enemy moves randomly
            enemy.move(-x, 0);
           
        }
        else if (choice == DOWN)
        {
            player.move(1, 0);
            //Enemy moves randomly
            enemy.move(x, 0);
        }else if (choice == LEFT)
        {
            player.move(0, -1);
            //Enemy moves randomly
            enemy.move(0,-y);
        }else if (choice == RIGHT)
        {
            player.move(0, 1);
            //Enemy moves randomly
            enemy.move(0, y);
        }else if(choice == INVENTORY)
        {
            displayInventoryOption(player);
        }
        
        
        if(grid->areAdjacent(player.getPositionX(), player.getPositionY(), enemy.getPositionX(), enemy.getPositionY()))
        {
           cout <<"Enterting Battle!!!!!" << endl;
          displayBattleLog(player, enemy);
            //Checks as long as player is still alive create more enemies
          if(player.isAlive() && choice != QUIT)
          {
            //clear enemygrid position
            grid->clearPosition(enemy.getPositionX(), enemy.getPositionY());
            //re-initialize the same enemy with a random position in the grid
            do
            {   
                //Create a random enemy
                enemy = getRandomEnemy(grid);
                srand(time(0));
                int x = getRandomValue(0, 7);
                int y = getRandomValue(0, 7);
                cout << x << y << endl;
                //clear enemygrid position (bug an extra enemy will spawn)
                grid->clearPosition(enemy.getPositionX(), enemy.getPositionY());
                // Update the enemy's position
                 enemy = Enemy(enemy.getName(), enemy.getHealth(), enemy.getAttackPower(), x, y, grid);

                 // Update the grid's enemy position
                 grid->setEnemyPosition(x, y);
                //Makes sure the positions arent overlapped and doesnt spawn right next to the player
            } while (player.getPositionX() == enemy.getPositionX() && player.getPositionY() == enemy.getPositionY() && !(grid->areAdjacent(player.getPositionX(), player.getPositionY(), enemy.getPositionX(), enemy.getPositionY())));
            
          }
        }

    } while (choice != QUIT);
    

 /*

   do {
        if (choice == ATTACK) {
            player.attack();
            enemy.takeDamage(player.attack());
            cout << player.getName() << " attacks with " << player.getAttackPower() << " attack power!" << endl;
            cout << "Enemy health: " << enemy.getHealth() << endl;
            if (enemy.getHealth() == 0) {
                cout << "Enemy defeated!" << endl;
                break;
            }
            enemy.attack();
            player.takeDamage(enemy.attack());
            cout << enemy.getName() << " attacks with " << enemy.getAttackPower() << " attack power!" << endl;
            cout << "Player health: " << player.getHealth() << endl;
            if (player.getHealth() == 0) {
                cout << "Player defeated!" << endl;
                break;
            }
        } else {
            int specialDamage = player.getSpAttackPower();
            cout << player.getName() << " attacks with " << specialDamage << " special attack power!" << endl;
            enemy.takeDamage(specialDamage);
            cout << "Enemy health: " << enemy.getHealth() << endl;
            if (enemy.getHealth() == 0) {
                cout << "Enemy defeated!" << endl;
                break;
            }
            enemy.attack();
            player.takeDamage(enemy.attack());
            cout << enemy.getName() << " attacks with " << enemy.getAttackPower() << " attack power!" << endl;
            cout << "Player health: " << player.getHealth() << endl;
            if (player.getHealth() == 0) {
                cout << "Player defeated!" << endl;
                break;
            }
        } 
        choice = choiceAfterStartGame();
    } while (choice != QUIT);
 */ 


}

int main() {
    int choice;

    do {
        displayStartGame();
        cout << endl;
        choice = getMenuChoice();
        cout << choice << endl;
        switch (choice) {
            case START_GAME:
                startGame();
                break;
            case UNIT_TEST:
                cout << endl;
                unitTest();
                break;
            default:
                cout << "Exiting Game!" << endl;
        }
    } while (choice != static_cast<int>(Actions::QUIT));


    return 0;
}
