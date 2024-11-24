#include <iostream>
#include <iomanip>
#include <string>
#include "UserInterface.h"
#include "Character.h"
#include "Enemy.h"
#include "Player.h"
using namespace std;

/*
void displayStartGame(); //Displays starting game screen
void displayMovementOption ()
void displayBattleOption()
void displayAttackOption()
void displayInventoryOption()
void displayAfterBattleOptions()
*/
void displayStartGame(){

    cout << string(border_width, '-') <<endl;
    cout << "|";
    cout << setw(content_width) << right << "Tactical Role-Playing Game";
    cout << "|" << endl;
 
     // Print options
    cout << "|";
    cout << setw(content_width - 12) << right << "(" << START_GAME << ") Start Game";
    cout << "|" << endl;

    cout << "|";
    cout << setw(content_width - 11) << right << "(" << UNIT_TEST << ") Unit Test";
    cout << "|" << endl;


    // Print the prompt message centered
   cout << "|";
   cout <<setw(content_width - 12) <<right << "Enter a number from " << min_menu_option << " to " << max_menu_option;
   cout << "|" <<endl;

   cout << "|";
   cout <<setw(content_width - 10) <<right << "or " << min_menu_option - 1 << " to exit: ";
   cout << "|" <<endl;
   cout << string(border_width, '-') <<endl;
}
int getMovementOption(){
  int userChoice;
  cin >> userChoice;
  if(userChoice > 4 || userChoice <= 0)
  {
    cout << "Error please enter a valid choice within range." << endl;
    getMovementOption();
  }
  return userChoice;
}
void displayMovementOption(){

    //Print options
    cout << string(border_width, '-') <<endl;
    cout << "|";
    cout << setw(content_width - 18) << right << "(" << UP << ") Move Up One Tile";
    cout << "|" << endl;
    cout << "|";
    cout << setw(content_width - 18) << right << "(" << DOWN << ") Move Down One Tile";
    cout << "|" << endl;
    cout << "|";
    cout << setw(content_width - 18) << right << "(" << LEFT << ") Move Left One Tile";
    cout << "|" << endl;
    cout << "|";
    cout << setw(content_width - 18) << right << "(" << RIGHT << ") Move Right One Tile";
    cout << "|" << endl;
    cout << string(border_width, '-') <<endl;

}
int getAttackOption(){
    int userChoice;
    cin >> userChoice;
    if(userChoice <= 0 || userChoice > 2 )
    {
      cout << "Error please enter a valid choice within range." << endl;
      getAttackOption();
    }
    return userChoice;
}
void displayAttackOption(){
      //Print options
    cout << string(border_width, '-') <<endl;
    cout << "|";
    cout << setw(content_width - 18) << right << "(" << UP << ") Attack";
    cout << "|" << endl;
    cout << "|";
    cout << setw(content_width - 18) << right << "(" << DOWN << ") Special Attack";
    cout << "|" << endl;
    cout << "|";
    cout << setw(content_width - 18) << right << "(" << LEFT << ") Back";
    cout << "|" << endl;
    cout << string(border_width, '-') <<endl;
}
void displayBattleLog(Player &player, Enemy &enemy){
  //Displays the combat log until either player or enemy is alive
    int attackOption;
     do {
      if(!player.isAlive())
      {
        return;
      }else if(!enemy.isAlive())
      {
        return;
      }
        displayAttackOption();
        attackOption = getAttackOption();
        if (attackOption == ATTACK) {
            player.attack();
            enemy.takeDamage(player.attack());
            cout << player.getName() << " attacks with " << player.getAttackPower() << " attack power!" << endl;
            cout << "Enemy health: " << enemy.getHealth() << endl;
            enemy.attack();
            player.takeDamage(enemy.attack());
            cout << enemy.getName() << " attacks with " << enemy.getAttackPower() << " attack power!" << endl;
            cout << "Player health: " << player.getHealth() << endl;
        } else {
            int specialDamage = player.getSpAttackPower();
            cout << player.getName() << " attacks with " << specialDamage << " special attack power!" << endl;
            enemy.takeDamage(specialDamage);
            cout << "Enemy health: " << enemy.getHealth() << endl;
            enemy.attack();
            player.takeDamage(enemy.attack());
            cout << enemy.getName() << " attacks with " << enemy.getAttackPower() << " attack power!" << endl;
            cout << "Player health: " << player.getHealth() << endl;
        }
        if(!player.isAlive())
        {
          cout <<"[Insert END GAME MENU]" << endl;
        }else if (!enemy.isAlive())
        {
          displayAfterBattle(player, enemy);
        }
    } while (attackOption != BACK);
}
void displayInventoryOption(){

}
void displayAfterBattle(Player &player, Enemy &enemy){
  cout << string(border_width, '-') <<endl;
  cout << "|";
  cout << setw(content_width - 10) << right << "Nice work! " << player.getName();
  cout << "|" << endl;
  cout << "|";
  cout << setw(content_width - 18) << right << "You have defeated a " << enemy.getName();
  cout << "|" << endl;
  cout << string(border_width, '-') <<endl;

  //Get loot details from enemy
  cout <<"You have recieved [Placeholder ITEM]" << "from: " << enemy.getName() << endl;

}
void displayEndGame();