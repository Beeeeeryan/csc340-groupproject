
---

# CSC340 Group Project

## Authors:

- Bryan Bernardo - Beeeeeryan
- Francis Gibson IV - FMGIV 
- Tony Wu - ThatCodeByTony
- Junhui Zhong - Swarm4Neuro


## Summary

This group project aims to create a basic emulation of a classic genre of a game in the video game industry, Tactical Role-Playing Games(TRPGS for short). The aim for creating this game application is to apply certain principles and ideas this group has learned throughout the semester. Contextually speaking, TRPGS are designed as turn-based combat, character development, and a linear progression type of game. Controlling a character on grid-based movement makes the game interactive for players.  Turned Base Combat allows players to take turns moving a character, executing certain actions based on strategy, resource management, and other factors. Lastly, a linear progression feature allows players to have a definitive goal which can include text based dialogue interactivity. Our hope for creating a simple prototype of a game is through utilizing inheritance, composition, and a OOP design while using the Linked List/Node Data Structure. 

---

## Project Structure

```
/CSC340-GROUPPROJECT
├── /src
│   ├── /Character
│   │   ├── Character.h              # Character base class header
│   │   ├── Character.cpp            # Character base class implementation
│   │   ├── Player.h                 # Player class header (inherits Character)
│   │   ├── Player.cpp               # Player class implementation
│   │   ├── Enemy.h                  # Enemy class header (inherits Character)
│   │   └── Enemy.cpp                # Enemy class implementation
│   ├── /SpecialAbilities
│   │   ├── SpecialAttack.h          # SpecialAttack class header
│   │   └── SpecialAttack.cpp        # SpecialAttack class implementation
│   ├── /Inventory
│   │   ├── Inventory.h              # Linked list for inventory items
│   │   ├── Inventory.cpp            # Inventory management implementation
│   │   ├── Item.h                   # Item class (represents an individual item)
│   │   ├── Item.cpp                 # Item class implementation
│   │   ├── Node.h                   # Node class for inventory items
│   │   └── Node.cpp                 # Node class implementation
│   ├── /Map
│   │   ├── Grid.h                   # Grid/map class header
│   │   └── Grid.cpp                 # Grid/map class functionality
│   ├── /UI
│   │   ├── UserInterface.h          # UI class header
│   │   └── UserInterface.cpp        # UI class implementation
│   ├── /UnitTests
│   │   ├── UnitTests.h              # Header for unit tests
│   │   └── UnitTests.cpp            # Implementation for unit tests
│   └── main.cpp                     # Main entry point of the program, contains the unit tests
├── .vscode                          # VS Code configuration files
│   ├── tasks.json                   # Task configuration for building the project
│   ├── c_cpp_properties.json        # IntelliSense and includes for C++
│   ├── launch.json                  # Debugger configuration
│   └── settings.json                # VS Code settings
├── .gitignore                       # Git ignore file
├── main                             # Compiled executable
├── README.md                        # Project documentation or notes

```

---

## Steps to Run the Program in VS Code

1. **Install Dependencies**:
    - **C++ Compiler (g++)**:
      - Open your terminal and run:
        ```
        sudo apt update
        sudo apt install g++
        ```
    - **VS Code Extensions**:
      - Search for and install **C/C++** in the Extensions panel of VS Code.

2. **Create/Update Configuration Files**:
   - In the `.vscode` folder, create or update the JSONs with the following configurations:

   ### `tasks.json`

   ```json
   {
       "version": "2.0.0",
       "tasks": [
           {
               "label": "build main",
               "type": "shell",
               "command": "/usr/bin/g++",
               "args": [
                   "-g", 
                   "-I", "${workspaceFolder}/src/Character",
                   "-I", "${workspaceFolder}/src/Map",
                   "-I", "${workspaceFolder}/src/UI",
                   "-I", "${workspaceFolder}/src/Inventory",
                   "-I", "${workspaceFolder}/src/UnitTests",
                   "${workspaceFolder}/src/main.cpp",
                   "${workspaceFolder}/src/Character/Character.cpp",
                   "${workspaceFolder}/src/Character/Player.cpp",
                   "${workspaceFolder}/src/Character/Enemy.cpp",
                   "${workspaceFolder}/src/SpecialAbilities/SpecialAttack.cpp",
                   "${workspaceFolder}/src/Map/Grid.cpp",
                   "${workspaceFolder}/src/UI/UserInterface.cpp",
                   "${workspaceFolder}/src/Inventory/Item.cpp",
                   "${workspaceFolder}/src/Inventory/Inventory.cpp",
                   "${workspaceFolder}/src/Inventory/Node.cpp", 
                   "${workspaceFolder}/src/UnitTests/UnitTests.cpp",
                   "-o",
                   "${workspaceFolder}/main"
               ],
               "group": {
                   "kind": "build",
                   "isDefault": true
               },
               "problemMatcher": ["$gcc"],
               "detail": "Generated task for building the project"
           }
       ]
   }
   ```

   ### `c_cpp_properties.json`

   ```json
   {
       "version": 4,
       "configurations": [
           {
               "name": "linux-gcc-x64",
               "includePath": [
                   "${workspaceFolder}/**",
                   "${workspaceFolder}/src/Character",
                   "${workspaceFolder}/src/Map",
                   "${workspaceFolder}/src/UI",
                   "${workspaceFolder}/src/Inventory"
               ],
               "compilerPath": "/usr/bin/g++",
               "intelliSenseMode": "linux-gcc-x64",
               "cStandard": "c11",
               "cppStandard": "c++17",
               "compilerArgs": [
                   "-Wall",
                   "-Wextra",
                   "-Wpedantic"
               ]
           }
       ]
   }
   ```

   ### `launch.json`

   ```json
   {
       "version": "0.2.0",
       "configurations": [
           {
               "name": "Debug C++ Program",
               "type": "cppdbg",
               "request": "launch",
               "program": "${workspaceFolder}/main",
               "args": [],
               "stopAtEntry": false,
               "cwd": "${workspaceFolder}",
               "environment": [],
               "externalConsole": true,
               "MIMode": "gdb",
               "setupCommands": [
                   {
                       "description": "Enable pretty-printing for gdb",
                       "text": "-enable-pretty-printing",
                       "ignoreFailures": true
                   }
               ],
               "miDebuggerPath": "/usr/bin/gdb",
               "preLaunchTask": "build main",
               "logging": {
                   "engineLogging": true
               },
               "externalConsole": true
           }
       ]
   }
   ```

   ### `settings.json`

   ```json
   {
       "C_Cpp.default.includePath": [
           "${workspaceFolder}/src/Character",
           "${workspaceFolder}/src/SpecialAbilities",
           "${workspaceFolder}/src/Inventory",
           "${workspaceFolder}/src/Map"
       ],
       "C_Cpp.default.compilerPath": "/usr/bin/g++",
       "C_Cpp.default.intelliSenseMode": "linux-gcc-x64",
       "files.associations": {
           "*.cpp": "cpp",
           "*.h": "cpp"
       },
       "C_Cpp_Runner.msvcBatchPath": ""
   }
   ```

3. **Build the Program**:
   - Press `Ctrl+Shift+B` or go to **Terminal > Run Build Task**.
   - This will compile your program and create an executable file named `main`.

4. **Run the Program**:
   - Open the terminal in VS Code (`Ctrl+``).
   - Run the compiled program:
     ```bash
     ./main
     ```

---

## Important Code

### **Creating Objects:**

```cpp
Player Default_player(name, health, attackPower, X_position, Y_position, grid);
Enemy Default_enemy(enemyName, 50, 5, 0, 3, grid);
```

### **Calling Object Functions:**

- **For Player:**
```cpp
Default_Player.getName();                         // Retrieves the player's name (Getter)
Default_Player.attack();                          // Returns the player's attack power (Getter)
Default_Player.takeDamage(amount);                // Reduces the player's health by the specified damage (Setter)
Default_Player.move(X, Y);                        // Moves the player in the grid by X and Y coordinates
Default_Player.isAlive();                         // Checks if the player's health is greater than zero (Getter)
Default_Player.getSpAttackPower();                // Retrieves the player's special attack power (Getter)
Default_Player.setEnemyCounter();                 // Updates the number of enemies defeated (Setter)
Default_Player.getEnemyCounter();                 // Retrieves the number of enemies defeated (Getter)
Default_Player.addItemToInventory(item);          // Adds a new item to the player's inventory
Default_Player.removeItemFromInventory();         // Removes an item from the player's inventory
Default_Player.displayInventory();                // Displays the player's current inventory
Default_Player.sortInventory();                   // Sorts the player's inventory items
```

- **For SpecialAbilities:**
```cpp
SpecialAttack.getSpAttackPower();      // Retrieves the special attack power (Getter)
```

- **For Enemy:**
```cpp
Default_Enemy.getName();                         // Retrieves the enemy's name (Getter)
Default_Enemy.attack();                          // Returns the enemy's attack power (Getter)
Default_Enemy.takeDamage(amount);                // Reduces the enemy's health by the specified damage
Default_Enemy.move(X, Y);                        // Moves the enemy in the grid by X and Y coordinates
Default_Enemy.isAlive();                         // Checks if the enemy's health is greater than zero (Getter)
```

- **For Grid:**
```cpp
grid.setPlayerPosition(x, y);              // Sets the player's position on the grid
grid.setEnemyPosition(x, y);               // Sets the enemy's position on the grid
grid.clearPosition(x, y);                  // Clears the position on the grid
grid.setPosition(x, y, value);             // Sets a specific value at the grid position (x, y)
grid.displayGrid();                        // Displays the grid with player, enemy, and empty spaces
grid.isValidPosition(x, y);                // Checks if the position (x, y) is within the grid bounds
grid.areAdjacent(pX, pY, eX, eY);          // Checks if two positions (player and enemy) are adjacent
```

- **For Inventory:**
```cpp
Inventory.addItem(newItem);             // Adds a new item to the inventory (Method)
Inventory.removeItem(itemName);         // Removes an item from the inventory by name (Method)
Inventory.sortItems();                  // Sorts the inventory items alphabetically (Method)
Inventory.displayInventory();           // Displays the player's current inventory (Method)
```

- **For Item:**
```cpp
Item.GetName();                         // Retrieves the item's name (Getter)
Item.GetDescription();                  // Retrieves the item's description (Getter)
Item.GetAmount();                       // Retrieves the item's amount (Getter)
Item.setAmount(newAmount);              // Sets the amount of the item (Setter)
Item.UseItem();                         // Uses the item and decreases its amount (Method)
```

- **For Node:**
```cpp
Node.getData();                     // Retrieves the node's data (Getter)
Node.setData(newItem);               // Sets the node's data with a new item (Setter)
Node.getNext();                     // Retrieves the next node (Getter)
Node.setNext(newNext);               // Sets the next node (Setter)
```

- **For UserInterface:**
```cpp
displayStartGame();                        // Displays the start game menu (Method)
displayMovementOption();                   // Displays movement options (Method)
displayAttackOption();                     // Displays attack options (Method)
displayInventoryOption(Player& player);    // Displays the inventory options (Method)
displayAfterBattle(Player& player, Enemy& enemy); // Displays after battle options (Method)
displayBattleLog(Player& player, Enemy& enemy);   // Displays the battle log during combat (Method)
displayEndGame();                          // Displays the end game screen (Method)
getMovementOption();                       // Gets the user's choice for movement (Getter/Method)
getAttackOption();                         // Gets the user's choice for attack (Getter/Method)
getInventoryOption();                      // Gets the user's inventory option choice (Getter/Method)
printCentered(const string& text, int box_width); // Prints text centered within a box (Method)
```

---

### **Inheritance:**

1. **Player** and **Enemy**:
   - Both **inherit** from **Character** (Abstract class).
   - **Character** serves as a base class, providing common properties and methods (e.g., `attack()`, `takeDamage()`, `move()`).

---

### **Compositions:**

1. **Player**:
   - **Has** a `SpecialAttack`.
   - **Has** an `Inventory`.
   - **Has** a position in a `Grid`.

2. **Enemy**:
   - **Has** a position in a `Grid`.

3. **Inventory**:
   - **Has** `Node` objects.
   - **Each Node has** an `Item`.

4. **Node**:
   - **Has** an `Item`.

---

### **Communication Between Classes:**

1. **Player and Grid/Enemy**:
   - **Player** communicates with **Grid** to set and retrieve its position using methods like `setPlayerPosition()` and `getPlayerPosition()`.
   - **Player** and **Enemy** also interact during combat using methods like `attack()`, `takeDamage()`, and `isAlive()`. Both **Player** and **Enemy** rely on the **Grid** to manage their positions.

2. **Player and Inventory**:
   - **Player** communicates with **Inventory** to manage items using methods like `addItemToInventory()`, `removeItemFromInventory()`, `displayInventory()`, and `sortInventory()`.

3. **Player and SpecialAttack**:
   - **Player** communicates with **SpecialAttack** to get the special attack power using `getSpAttackPower()`.

4. **Inventory and Item**:
   - **Inventory** communicates with **Item** through **Node** to add, remove, and display items stored in the inventory.

---

### **Polymorphism:**

1. **Player and Enemy**:
   - **Player** and **Enemy** **inherit** from **Character**, allowing them to be treated as **Character** objects. Methods like `attack()`, `takeDamage()`, and `move()` are **overridden** in both **Player** and **Enemy**

---

### **Inventory Class Functions:**

- **`sortItems()`**: 
   - This function sorts the inventory items alphabetically or by some other criteria (like item type or quantity). The exact sorting mechanism depends on the specific implementation in your code, but typically it can use a sorting algorithm (like quicksort or mergesort) to reorder the items in the inventory.
   
   Example:
   ```cpp
   Inventory.sortItems();  // Sorts items in the inventory alphabetically by name
   ```

- **`removeItem(itemName)`**:
   - This function removes an item from the inventory based on its name. Typically, this involves traversing the linked list of inventory nodes, finding the item by name, and deleting the corresponding node.
   
   Example:
   ```cpp
   Inventory.removeItem("Health Potion");  // Removes the "Health Potion" from the inventory
   ```

Both of these methods enhance the functionality of the inventory system, providing ways to keep it organized and manageable by allowing the user to delete or sort items as necessary.

These functionalities (sort and delete) are often implemented in the `Inventory` class, which internally manipulates a linked list of `Node` objects, where each `Node` contains an `Item`.
