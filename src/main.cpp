#include <iostream>
#include "Character.h"
#include "Player.h"
using namespace std;

// Press Ctrl+Shift+B (or go to Terminal > Run Build Task).

int main() {
    Character player;
    Player player1("John Smith",0, 20, 1,1);

    cout << "-------- Testing Character Class! --------" << endl;
    cout << "Welcome " << player.getName() + "!" << endl;
    cout << "Is the player alive? " << (player.isAlive() ? "Yes" : "No") << endl;
    cout << "You have " << player.getAttackPower() << " attack power!" << endl;

    cout << "-------- Testing Player Class! --------" << endl;
    cout << "Welcome " << player1.getName() + "!" << endl;
    cout << "Is the player alive? " << (player1.isAlive() ? "Yes" : "No") << endl;
    cout << "You have " << player1.getAttackPower() << " attack power!" << endl;

    return 0;
}
