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
    Item sword("Sword", "A sharp blade does 20 attack power", 1, 20);
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
