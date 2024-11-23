#include <iostream>
#include "Character.h"
#include "Player.h"
#include "Enemy.h"
#include "Grid.h"

using namespace std;

int main() {
    Grid grid;
    Player player1("John Smith", 100, 10, 2, 1, grid);
    Enemy enemy("Goblin", 50, 5, 0, 3, grid);

    // Display the initial grid
    cout << "-------- Initial Grid State --------" << endl;
    grid.displayGrid();
    cout << endl;

    // Display player and enemy details
    cout << "-------- Testing Player Class! --------" << endl;
    Position pos2 = player1.getPosition();
    cout << "Welcome " << player1.getName() + "!" << endl;
    cout << "Is " << player1.getName() << " alive? " << (player1.isAlive() ? "Yes" : "No") << endl;
    cout << player1.getName() << " has " << player1.getHealth() << " health!" << endl;
    cout << player1.getName() << " has " << player1.getAttackPower() << " attack power!" << endl;
    player1.attack();
    cout << player1.getName() << " is positioned at (" << pos2.x << ", " << pos2.y << ")" << endl;
    cout << endl;

    cout << "-------- Testing Enemy Class! --------" << endl;
    Position pos3 = enemy.getPosition();
    cout << "Welcome " << enemy.getName() + "!" << endl;
    cout << "Is " << enemy.getName() << " alive? " << (enemy.isAlive() ? "Yes" : "No") << endl;
    cout << enemy.getName() << " has " << enemy.getHealth() << " health!" << endl;
    cout << enemy.getName() << " has " << enemy.getAttackPower() << " attack power!" << endl;
    enemy.attack();
    cout << enemy.getName() << " is positioned at (" << pos3.x << ", " << pos3.y << ")" << endl;
    cout << endl;


    cout << "-------- Testing Player Movement! --------" << endl;
    grid.setPlayerPosition(player1.getPosition().x, player1.getPosition().y);
    grid.setEnemyPosition(enemy.getPosition().x, enemy.getPosition().y);

    grid.displayGrid();
    cout << endl;

    player1.move(-1, 0);  
    enemy.move(0, -2);   

    grid.displayGrid();


    return 0;
}
