#include <iostream>
#include "Character.h"
using namespace std;

// Press Ctrl+Shift+B (or go to Terminal > Run Build Task).

int main() {
    Character player;
    cout << "Testing Character Class!" << endl;
    cout << "Is the player alive?" << (player.isAlive() ? "Yes" : "No") << endl;
    return 0;
}
