#ifndef USER_INTERFACE_H
#define USER_INTERFACE_H

#include "../Character/Character.h"
#include "../Character/Player.h"
#include "../Character/Enemy.h"
#include "../SpecialAbilities/SpecialAttack.h"
// Enum declarations
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

const int border_width = 30;
const int content_width = border_width - 5;

// Function declarations for displayMessage overloads
void displayStartGame();
void displayMovementOption();
void displayAttackOption();
void displayInventoryOption();
void displayAfterBattle(Player &player, Enemy &enemy);
void displayBattleLog(Player &player, Enemy  &enemy);
void displayEndGame();
int getMovementOption();
int getAttackOption();
int getInventoryOption();


#endif
