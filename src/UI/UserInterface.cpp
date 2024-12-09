#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <ctime>
#include <thread>   // For delay
#include <chrono>   
#include <cctype>  // For toupper()
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
    Item("Potion", "Restores 50 HP", 1, 50),
    Item("Mana Potion", "Restores 30 MP", 1, 30),
    Item("Gold Coin", "A shiny gold coin", 10, 0),
    Item("Magic Scroll", "Contains an ancient spell", 1, 0),
    Item("Magic Scroll", "Contains an ancient spell", 1 ,0),
    Item("Sword", "A sturdy weapon with extra 3 damage", 1, 3),
    Item("Diamond Shield", "Provides extra  7 defense in battle", 1, 7)
  };

  // Randomly select an item from the vector
  int randomIndex = rand() % lootItems.size();
  randomIndex = rand() % lootItems.size();
  randomIndex = rand() % lootItems.size();
  return lootItems[randomIndex];
}

// Function to generate a random enemy from a predefined list
Enemy getRandomEnemy(Grid* grid) {
    // Predefined list of enemies
    std::vector<Enemy> enemyList = {
        Enemy("Goblin", 50, 15, 0, 0, grid),
        Enemy("Orc", 100, 20, 0, 0, grid),
        Enemy("Troll", 130, 25, 0, 0, grid),
        Enemy("Skeleton", 80, 10, 0, 0, grid),
        Enemy("Zombie", 120, 12, 0, 0, grid),
        Enemy("Vampire", 170, 30, 0, 0, grid),
        Enemy("Werewolf", 120, 35, 0, 0, grid),
        Enemy("Dragon", 150, 50, 0, 0, grid)
    };

    // Randomly select an enemy from the vector
    int randomIndex = rand() % enemyList.size();
    return enemyList[randomIndex];
}

// Function to print centered text
void printCentered(const string& text, int box_width) {
    int padding = (box_width - 2 - text.length()) / 2; // Calculate padding (minus 2 for the borders '|')
    cout << "|" << string(padding, ' ') << text;
    // Add extra space if padding leaves room due to odd/even difference
    cout << string(box_width - 2 - padding - text.length(), ' ') << "|" << endl;
}

// Function to print the player's attack and status
void printPlayerTurn(const string& playerName, int playerAttackPower, int playerHealth, int enemyHealth, bool isSpecialAttack) {
    const int width = 50;
    
    // Print turn header
    cout << setfill('*') << setw(width) << "" << endl;
    cout << "* " << setfill(' ') << left << setw(width - 4)<< " Player's Turn!" << " " << endl;
    cout << setfill('*') << setw(width) << "" << endl;

     string attackType = isSpecialAttack ? "special attack power" : "attack power";

    // Print attack message
    cout << "* " << setfill(' ') << setw(width - 4) 
              << (playerName + " attacks with " + to_string(playerAttackPower) + " " + attackType + "!") << " *" << endl;
    
    // Delay before showing health status
    this_thread::sleep_for(chrono::seconds(1));

    // Print health status
    cout << "* " << setw(width - 4) << ("Player health: " + to_string(playerHealth)) << " *" << endl;
    cout << "* " << setw(width - 4) << ("Enemy health: " + to_string(enemyHealth)) << " *" << endl;

    // Bottom border
    cout << setfill('*') << setw(width) << "" << endl;
    cout << endl;
}

// Function to print the enemy's attack and status
void printEnemyTurn(const string& enemyName, int enemyAttackPower, int playerHealth, int enemyHealth) {
    const int width = 50;

    // Print turn header
    cout << setfill('*') << setw(width) << "" << endl;
    cout << "* " << setfill(' ') << left << setw(width - 4) << " Enemy's Turn!" << " *" << endl;
    cout << setfill('*') << setw(width) << "" << endl;

    // Print attack message
    cout << "* " << setfill(' ') << setw(width - 4) 
              << (enemyName + " attacks with " + to_string(enemyAttackPower) + " attack power!") << " *" << endl;

    // Delay before showing health status
    this_thread::sleep_for(chrono::seconds(1));

    // Print health status
    cout << "* " << setw(width - 4) << ("Player health: " + to_string(playerHealth)) << " *" << endl;
    cout << "* " << setw(width - 4) << ("Enemy health: " + to_string(enemyHealth)) << " *" << endl;

    // Bottom border
    cout << setfill('*') << setw(width) << "" << endl;
    cout << endl;
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
int getMovementOption() {
    string userInput;
    cin >> userInput;

    // Ensure input is a single character
    if (userInput.length() == 1) {
        char userChoice = toupper(userInput[0]);  // Convert input to uppercase

        // Check if the input is one of the valid movement keys or 'quit' key
        if (userChoice == UP || userChoice == DOWN || userChoice == LEFT || userChoice == RIGHT || userChoice == QUIT) {
            return userChoice;
        }
    }

    // Check if input is numeric (only 0 or 5 are valid)
    if (userInput.length() == 1 && isdigit(userInput[0])) {
        int numericChoice = userInput[0] - '0';  // Convert char to integer
        if (numericChoice == QUIT || numericChoice == 5) {
            return numericChoice;
        }
    }

    // If input is invalid
    cout << "Error: Please enter a valid option (W, A, S, D, 5, 0).\n";
    return getMovementOption();  // Recursively ask for input again
}

void displayMovementOption() {
    int box_width = border_width;  

    // Print the top border
    cout << string(box_width, '-') << endl;

    // Print movement options centered (with character inputs instead of numbers)
    printCentered("(" + string(1, UP) + ") Move Up One Tile", box_width);
    printCentered("(" + string(1, DOWN) + ") Move Down One Tile", box_width);
    printCentered("(" + string(1, LEFT) + ") Move Left One Tile", box_width);
    printCentered("(" + string(1, RIGHT) + ") Move Right One Tile", box_width);
    printCentered("(" + to_string(INVENTORY) + ") Go to Inventory", box_width);
    printCentered("(" + to_string(QUIT) + ") Quit Game", box_width);

    // Print the bottom border
    cout << string(box_width, '-') << endl;
}
int getAttackOption(){
    int userChoice;
    cin >> userChoice;

     // Check if input was successful
    if (cin.fail()) {  // If cin fails to read an integer
            cin.clear();  // Clear the error state
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard invalid input
            cout << "Invalid input. Please enter a valid integer.\n";
            return getAttackOption();
      }
    if(userChoice == BACK || userChoice == ATTACK || userChoice == INVENTORY || userChoice == SPECIAL_ATTACK )
    {
      return userChoice;
    }
    else{
      cout << "Error please enter a valid choice within range." << endl;
      getAttackOption();
    }
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
      
            /*Player takes turn*/
            enemy.takeDamage(player.attack());
            printPlayerTurn(player.getName(), player.getAttackPower(), player.getHealth(), enemy.getHealth(), false);

             /*Enemy's turn*/ 
            player.takeDamage(enemy.attack() - player.getArmour());
            printEnemyTurn(enemy.getName(), enemy.getAttackPower(), player.getHealth(), enemy.getHealth());  

        } else if(attackOption == SPECIAL_ATTACK){

            /*Player takes turn*/
            enemy.takeDamage(player.getSpAttackPower());
            printPlayerTurn(player.getName(), player.getSpAttackPower(), player.getHealth(), enemy.getHealth(), true);

            /*Enemy takes turn*/
            player.takeDamage(enemy.attack() - player.getArmour());
            printEnemyTurn(enemy.getName(), enemy.getAttackPower(), player.getHealth(), enemy.getHealth()); 

        }else if(attackOption == INVENTORY)
        {
          displayInventoryOption(player);
        }else if(attackOption == BACK)
        {
          return;
        }
        if(!player.isAlive())
        {
          displayLossGame();
        }else if (!enemy.isAlive() && player.getEnemyCounter() != 8) //Hard Coded for the player to defeat 3 enemies
        {
          //Increase the enemy counter
          int newCounter = player.getEnemyCounter() + 1;
          player.setEnemyCounter(newCounter);
        if(player.getEnemyCounter() == 8)
        {
          displayEndGame();
          return;
        }else
          displayAfterBattle(player, enemy);
        }
    } while (attackOption != BACK);
}
int getInventoryOption(){
    int userInvOption;
    cin >> userInvOption;

    // Check if input was successful
    if (cin.fail()) {  // If cin fails to read an integer
            cin.clear();  // Clear the error state
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard invalid input
            cout << "Invalid input. Please enter a valid integer.\n";
            return getInventoryOption();
    }

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
      string temp = player.getName() + "'s Inventory";
      cout << string(border_width + 30, '-') << endl;
      printCentered(temp, border_width + 30);

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
  {
    cout <<"Enter item name to be used:" << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the leftover newline
    string itemName;
    getline(cin, itemName);
    player.useItemFromInventory(player,itemName);
  }
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
  if(userChoice == 'Y' || userChoice == 'y')
  {
    player.addItemToInventory(lootItem);
  }

}
void displayEndGame(){
  int box_width = border_width + 30;
  printCentered("!*-*-*-*-*-*-*-*-*-*!", box_width);
  printCentered("Victory!!!", box_width);
  printCentered("Thanks for playing this Tactical Role Playing Game!", box_width);
  printCentered("Credits to, Bryan, Junhi, Francis, and Tony!!", box_width);
  printCentered("!*-*-*-*-*-*-*-*-*-*!", box_width);
  exit(0);
}
void displayLossGame(){
  int box_width = border_width + 30;
  printCentered("!*-*-*-*-*-*-*-*-*-*!", box_width);
  printCentered("You Have Died", box_width);
  printCentered("Maybe next time.....", box_width);
  printCentered("Credits to, Bryan, Junhi, Francis, and Tony!!", box_width);
  printCentered("!*-*-*-*-*-*-*-*-*-*!", box_width);
}