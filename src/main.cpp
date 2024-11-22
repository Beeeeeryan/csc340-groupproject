#include <iostream>
#include "Character.h"
#include "Player.h"
#include "Enemy.h"
using namespace std;

int main() {
    Character player; // test default constructor of Character class.
    Player player1("John Smith",0, 20, 1,1); // test parameterized constructor of Player class.
    Enemy enemy("Goblin", 100, 10, 3, 1); // test parameterized constructor of Enemy class.
    Position pos = player.getPosition();  // Get position using the Position struct
    Position pos2 = player1.getPosition();  // Get position using the Position struct
    Position pos3 = enemy.getPosition();  // Get position using the Position struct


    cout << "-------- Testing Character Class! --------" << endl;
    cout << "Welcome " << player.getName() + "!" << endl;
    cout << "Is the player alive? " << (player.isAlive() ? "Yes" : "No") << endl;
    cout << "You have " << player.getAttackPower() << " attack power!" << endl;
    cout << player.getName() << " is positioned at (" << pos.x << ", " << pos.y << ")" << endl;
    cout << endl;

    cout << "-------- Testing Player Class! --------" << endl;
    cout << "Welcome " << player1.getName() + "!" << endl;
    cout << "Is the player alive? " << (player1.isAlive() ? "Yes" : "No") << endl;
    cout << "You have " << player1.getAttackPower() << " attack power!" << endl;
    cout << player1.getName() << " is positioned at (" << pos2.x << ", " << pos2.y << ")" << endl;
    cout << endl;

    cout << "-------- Testing Enemy Class! --------" << endl;
    cout << "Welcome " << enemy.getName() + "!" << endl;
    cout << "Is the enemy alive? " << (enemy.isAlive() ? "Yes" : "No") << endl;
    cout << "You have " << enemy.getAttackPower() << " attack power!" << endl;
    cout << enemy.getName() << " is positioned at (" << pos3.x << ", " << pos3.y << ")" << endl;



    return 0;
}
