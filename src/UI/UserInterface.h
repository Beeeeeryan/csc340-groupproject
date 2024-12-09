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
    UP = 'W',
    DOWN = 'S',
    LEFT = 'A',
    RIGHT = 'D',
};

enum InvOptions{
    DELETE = 1,
    USE = 2,
    SORT = 3,
};

enum Options {
    BACK = 0,
    ATTACK = 1,
    SPECIAL_ATTACK = 2,
    INVENTORY = 5,
};
const int min_menu_option = 1;
const int max_menu_option = 2;

const int border_width = 30;
const int content_width = border_width - 5;

void displayStartGame();
void displayMovementOption();
void displayAttackOption();
void displayInventoryOption(Player& player);
void displayAfterBattle(Player &player, Enemy &enemy);
void displayBattleLog(Player &player, Enemy  &enemy);
void displayEndGame();
void displayLossGame();
int getMovementOption();
int getAttackOption();
int getInventoryOption();
void printCentered(const std::string& text, int box_width);
void printPlayerTurn(const std::string& playerName, int playerAttackPower, int playerHealth, int enemyHealth);
void printEnemyTurn(const std::string& enemyName, int enemyAttackPower, int playerHealth, int enemyHealth);
Enemy getRandomEnemy(Grid* grid);


#endif
