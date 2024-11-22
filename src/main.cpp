#include <iostream>
#include "Character.h"
#include "Player.h"
#include "Enemy.h"
using namespace std;

// Press Ctrl+Shift+B (or go to Terminal > Run Build Task).

int main() {
    Character player;
    Player player1("John Smith",0, 20, 1,1);
    Enemy enemy("Goblin", 100, 10, 0, 0);

    cout << "-------- Testing Character Class! --------" << endl;
    cout << "Welcome " << player.getName() + "!" << endl;
    cout << "Is the player alive? " << (player.isAlive() ? "Yes" : "No") << endl;
    cout << "You have " << player.getAttackPower() << " attack power!" << endl;

    cout << "-------- Testing Player Class! --------" << endl;
    cout << "Welcome " << player1.getName() + "!" << endl;
    cout << "Is the player alive? " << (player1.isAlive() ? "Yes" : "No") << endl;
    cout << "You have " << player1.getAttackPower() << " attack power!" << endl;

    cout << "-------- Testing Enemy Class! --------" << endl;
    cout << "Welcome " << enemy.getName() + "!" << endl;
    cout << "Is the enemy alive? " << (enemy.isAlive() ? "Yes" : "No") << endl;
    cout << "You have " << enemy.getAttackPower() << " attack power!" << endl;


    return 0;
}
