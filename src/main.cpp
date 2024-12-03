// main.cpp

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib> 
#include <ctime>   
#include "Character.h"
#include "Player.h"
#include "Enemy.h"
#include "Grid.h"
#include "UserInterface.h"
#include "Inventory.h"
#include "Item.h"
#include "Node.h"
#include "Unittests.h"

using namespace std;


// Generate a random number inclusive
int getRandomValue(int min, int max) {
    return rand() % (max - min + 1) + min;  
}
int getMenuChoice() {
    int userInput;

    cin >> userInput; 

    if (userInput < min_menu_option - 1 || userInput > max_menu_option) {
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
    string enemyName = "Enemy";
    // Create some items
    Item potion("Potion", "Restores 50 HP", 3);
    Item sword("Sword", "A sharp blade", 1);
    Item shield("Shield", "Protects from damage", 1);
    // Create a vector of items
    vector<Item> items = {potion, sword, shield};
    Player player(playerName, 100, 10, 3, 0, items, grid); //Starting pos bottom left
    Enemy enemy(enemyName, 50, 5, 0, 3, grid); //Starting pos top right
    

    do
    {
        //What will always displays
        grid->displayGrid();
        cout << "-------------------------------" << endl;
        displayMovementOption();
        cout << "-------------------------------" << endl;
        cout << "Player health: " << player.getHealth() << endl;
        cout << "Enemy health: " << enemy.getHealth() << endl;
        cout << "-------------------------------" << endl;


    

        choice = getMovementOption();
        //Update movement on the grid
        //X Neg-Values move up in the grid, X Pos-Values move down
        //Y-Neg Values move left in the grid, Y Pos-Values move right
        if(choice == UP)
        {
            player.move(-1, 0);
           
        }
        else if (choice == DOWN)
        {
            player.move(1, 0);
        }else if (choice == LEFT)
        {
            player.move(0, -1);
        }else if (choice == RIGHT)
        {
            player.move(0, 1);
        }else if(choice == INVENTORY)
        {
            displayInventoryOption(player);
        }
        
        
        if(grid->areAdjacent(player.getPositionX(), player.getPositionY(), enemy.getPositionX(), enemy.getPositionY()))
        {
           cout <<"Enterting Battle!!!!!" << endl;
          displayBattleLog(player, enemy);
            //Checks as long as player is still alive create more enemies
          if(player.isAlive())
          {
            //clear enemygrid position
            grid->clearPosition(enemy.getPositionX(), enemy.getPositionY());
            //re-initialize the same enemy with a random position in the grid
            do
            {
                srand(time(0));
                int x = getRandomValue(0, 3);
                int y = getRandomValue(0, 3);
                cout << x << y << endl;
                enemy = Enemy(enemyName, 50, 5, x, y, grid);
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

    displayStartGame();
    cout << endl;

    do {
        choice = getMenuChoice();
        switch (choice) {
            case START_GAME:
                startGame();
                break;
            case UNIT_TEST:
                cout << endl;
                unitTest();
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != static_cast<int>(Actions::QUIT));


    return 0;
}
