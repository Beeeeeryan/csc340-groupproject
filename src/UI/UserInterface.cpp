#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <ctime>
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

// Function to generate a random item
Item getRandomItem() {
  // Seed the random number generator
  srand(time(0));

  // Item DB
  vector<Item> lootItems = {
    Item("Health Potion", "Restores 50 HP", 1),
    Item("Mana Potion", "Restores 30 MP", 1),
    Item("Gold Coin", "A shiny gold coin", 10),
    Item("Magic Scroll", "Contains an ancient spell", 1),
    Item("Magic Scroll", "Contains an ancient spell", 1),
    Item("Iron Sword", "A sturdy weapon with extra damage", 1),
    Item("Shield", "Provides extra defense in battle", 1)
  };

  // Randomly select an item from the vector
  int randomIndex = rand() % lootItems.size();
  return lootItems[randomIndex];
}

// Function to print centered text
void printCentered(const string& text, int box_width) {
    int padding = (box_width - 2 - text.length()) / 2; // Calculate padding (minus 2 for the borders '|')
    cout << "|" << string(padding, ' ') << text;
    // Add extra space if padding leaves room due to odd/even difference
    cout << string(box_width - 2 - padding - text.length(), ' ') << "|" << endl;
}




void displayStartGame(){

    int box_width = border_width; 

    // Print the top border
    cout << string(box_width, '-') << endl;

    // Print centered
    printCentered("Tactical Role-Playing Game", box_width);
    printCentered("(" + to_string(START_GAME) + ") Start Game", box_width);
    printCentered("(" + to_string(UNIT_TEST) + ") Unit Test", box_width);
    printCentered("Enter a number from " + to_string(min_menu_option) + " to " + to_string(max_menu_option), box_width);
    printCentered("or " + to_string(min_menu_option - 1) + " to exit: ", box_width);

    // Print the bottom border
    cout << string(box_width, '-') << endl;

}
int getMovementOption(){
  int userChoice;
  cin >> userChoice;
  if(userChoice > 5 || userChoice <= 0)
  {
    cout << "Error please enter a valid choice within range." << endl;
    getMovementOption();
  }
  return userChoice;
}
void displayMovementOption(){

    int box_width = border_width;  

    // Print the top border
    cout << string(box_width, '-') << endl;

    // Print movement options centered
    printCentered("(" + to_string(UP) + ") Move Up One Tile", box_width);
    printCentered("(" + to_string(DOWN) + ") Move Down One Tile", box_width);
    printCentered("(" + to_string(LEFT) + ") Move Left One Tile", box_width);
    printCentered("(" + to_string(RIGHT) + ") Move Right One Tile", box_width);
    printCentered("(" + to_string(INVENTORY) + ") Go to Inventory", box_width);

    // Print the bottom border
    cout << string(box_width, '-') << endl;

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
    int box_width = border_width;  

    // Print the top border
    cout << string(box_width, '-') << endl;

    printCentered("(" + to_string(ATTACK) + ") Attack", box_width);
    printCentered("(" + to_string(SPECIAL_ATTACK) + ") Special Attack", box_width);
    printCentered("(" + to_string(INVENTORY) + ") Go To Inventory", box_width);
    printCentered("(" + to_string(BACK) + ") Back", box_width);

    // Print the bottom border
    cout << string(box_width, '-') << endl;
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
        } else if(attackOption == SPECIAL_ATTACK){
            int specialDamage = player.getSpAttackPower();
            cout << player.getName() << " attacks with " << specialDamage << " special attack power!" << endl;
            enemy.takeDamage(specialDamage);
            cout << "Enemy health: " << enemy.getHealth() << endl;
            enemy.attack();
            player.takeDamage(enemy.attack());
            cout << enemy.getName() << " attacks with " << enemy.getAttackPower() << " attack power!" << endl;
            cout << "Player health: " << player.getHealth() << endl;
        }else if(attackOption == INVENTORY)
        {
          displayInventoryOption(player);
        }
        if(!player.isAlive())
        {
          cout <<"[Insert END GAME MENU]" << endl;
        }else if (!enemy.isAlive() && player.getEnemyCounter() != 3) //Hard Coded for the player to defeat 3 enemies
        {
          //Increase the enemy counter
          int newCounter = player.getEnemyCounter() + 1;
          player.setEnemyCounter(newCounter);
        if(player.getEnemyCounter() == 3)
        {
          cout << "[INSERT END GAME MENU]" << endl;
          return;
        }
          displayAfterBattle(player, enemy);
        }
    } while (attackOption != BACK);
}
int getInventoryOption(){
    int userInvOption;
    cin >> userInvOption;

    if(userInvOption == 0)
    {
      return userInvOption;
    }

    if(userInvOption < 1 || userInvOption > 5)
    {
      cout << "Error please enter a valid choice within range." << endl;
      getInventoryOption();
    }

    return userInvOption;
}
void displayInventoryOption(Player &player){
  int userChoice;
  do{
  cout << string(border_width + 13, '-') <<endl;
  cout << "|";
  cout << setw(content_width - 9) << right << player.getName() << "'s Inventory!";
  cout << "|" << endl;

  player.displayInventory();


    int box_width = 40; 

    // Print the top border
    cout << string(box_width, '-') << endl;

    printCentered("(" + to_string(DELETE) + ") Delete an Item", box_width);
    printCentered("(" + to_string(USE) + ") Use an Item", box_width);
    printCentered("(" + to_string(SORT) + ") Sort your Inventory", box_width);
    printCentered("(" + to_string(BACK) + ") Go Back", box_width);

    // Print the bottom border
    cout << string(box_width, '-') << endl;

  userChoice = getInventoryOption();
  switch (userChoice)
  {
  case DELETE:
  { 
    string newItem;
    cout << "Enter an item to be deleted: ";
    cin >> newItem;
    player.removeItemFromInventory(newItem);
  }
    break;
  case USE:
    /*TBA DELETE FEATURE*/
    break;
  case SORT:
  {
    player.sortInventory();
  }
  
  default:
    break;
  }


  }while(userChoice != BACK);

}
void displayAfterBattle(Player &player, Enemy &enemy){
    int box_width = border_width;
    // Print the top border
    cout << string(box_width, '-') << endl;

    // Print centered
    printCentered("Nice work! " + player.getName(), box_width);
    printCentered("You have defeated a " + enemy.getName(), box_width);

    // Print the bottom border
    cout << string(box_width, '-') << endl;

  //Get loot details from enemy
  
  Item lootItem = getRandomItem();
    box_width = box_width + 30; //Account for the longer text
    cout << string(box_width, '-') << endl;

    // Print  centered
    printCentered("Congrats! You have defeated an enemy!", box_width);
    printCentered("You have received: " + lootItem.GetName(), box_width);
    printCentered("Description: " + lootItem.GetDescription(), box_width);
    printCentered("Amount: " + to_string(lootItem.GetAmount()), box_width);

    // Print the bottom border
    cout << string(box_width, '-') << endl;

  //Ask if want to add to inventory or not
  char userChoice;
  cout <<"Want to Add To Inventory? Y/N: ";
  cin >> userChoice;
  if(userChoice == 'Y')
  {
    player.addItemToInventory(lootItem);
  }

}
void displayEndGame();