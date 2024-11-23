#include <iostream>
#include "Character.h"
#include "Player.h"
#include "Enemy.h"
#include "Grid.h"

using namespace std;

enum Actions {
    QUIT = 0,
    START_GAME = 1,
    UNIT_TEST = 2,
};

enum Movement {
    UP = 1,
    DOWN = 2,
    LEFT = 3,
    RIGHT = 4,
};

enum Options {
    BACK = 0,
    ATTACK = 1,
    SPECIAL_ATTACK = 2,
};

const int min_menu_option = 1;
const int max_menu_option = 2;

int getMenuChoice() {
    int userInput;

    cout << "--------------------------------------------" << endl;
    cout << "Tactical Role-Playing Game" << endl;
    cout << "(" << START_GAME << ")" << " Start Game" << endl;
    cout << "(" << UNIT_TEST << ")" << " Unit Test" << endl;
    cout << "Enter a number from " << min_menu_option << " to " << max_menu_option << ", or " 
         << min_menu_option - 1 << " to exit: " << endl;

    cin >> userInput; 

    if (userInput < min_menu_option - 1 || userInput > max_menu_option) {
        cout << "Error! Input must be a number between " << min_menu_option << " and " << max_menu_option
             << " ,or " << min_menu_option - 1 << " to exit." << endl;
        return getMenuChoice(); 
    }
   
    return userInput;
}

void unitTest() {
    Grid grid;
    string playerName = "Player";
    string enemyName = "Enemy";

    Player player1(playerName, 100, 10, 3, 0, grid);
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
    grid.displayGrid();
    cout << endl;


    cout << "-------- Testing Player Movement! --------" << endl;
    // grid.setPlayerPosition(player1.getPosition().x, player1.getPosition().y);
    // grid.setEnemyPosition(enemy.getPosition().x, enemy.getPosition().y);

    grid.displayGrid();
    cout << endl;

    player1.move(-1, 0);  
    enemy.move(0, -2);   

    grid.displayGrid();
    cout << endl;
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
    Grid grid;
    string playerName = "Player";
    string enemyName = "Enemy";
    Player player(playerName, 100, 10, 3, 0, grid);
    Enemy enemy(enemyName, 50, 5, 0, 3, grid);
    grid.displayGrid();
    cout << "--------------------------------------------" << endl;
    cout << "Player health: " << player.getHealth() << endl;
    cout << "Enemy health: " << enemy.getHealth() << endl;
    choice = choiceAfterStartGame();
    cout << "--------------------------------------------" << endl;

    do {
        if (choice == ATTACK) {
            player.attack();
            enemy.takeDamage(player.attack());
            cout << playerName << " attacks with " << player.getAttackPower() << " attack power!" << endl;
            cout << "Enemy health: " << enemy.getHealth() << endl;
            if (enemy.getHealth() == 0) {
                cout << "Enemy defeated!" << endl;
                break;
            }
            enemy.attack();
            player.takeDamage(enemy.attack());
            cout << "Player health: " << player.getHealth() << endl;
            if (player.getHealth() == 0) {
                cout << "Player defeated!" << endl;
                break;
            }
        } else {
            int specialDamage = player.getSpAttackPower();
            cout << playerName << " attacks with " << specialDamage << " special attack power!" << endl;
            enemy.takeDamage(specialDamage);
            cout << "Enemy health: " << enemy.getHealth() << endl;
            if (enemy.getHealth() == 0) {
                cout << "Enemy defeated!" << endl;
                break;
            }
            enemy.attack();
            player.takeDamage(enemy.attack());
            cout << "Player health: " << player.getHealth() << endl;
            if (player.getHealth() == 0) {
                cout << "Player defeated!" << endl;
                break;
            }
        } 
        choice = choiceAfterStartGame();
    } while (choice != QUIT);
}

int main() {
    int choice;

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
