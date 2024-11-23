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
    Player player1("John Smith", 100, 10, 3, 0, grid);
    Enemy enemy("Goblin", 50, 5, 0, 3, grid);

 
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

int main() {
    int choice;

    do {
        choice = getMenuChoice();
        switch (choice) {
            case START_GAME:
                cout << "Starting the game..." << endl;
                break;
            case UNIT_TEST:
                cout << "Running unit tests..." << endl;
                cout << endl;
                unitTest();
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != static_cast<int>(Actions::QUIT));


    return 0;
}
