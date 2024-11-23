# Project Structure 
<pre>
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
│   │   ├── Inventory.cpp            # Implementation of inventory management
│   │   ├── Item.h                   # Item class (could represent an individual item in the inventory)
│   │   └── Item.cpp                 # Implementation of Item class
│   ├── /Map
│   │   ├── Grid.h                   # Header for grid/map class
│   │   ├── Grid.cpp                 # Implementation of grid/map functionality
│   │   ├── Tile.h                   # Tile class representing individual grid squares
│   │   └── Tile.cpp                 # Implementation of the Tile class
│   └── main.cpp                      # Main entry point of the program
├── /build                          # (optional) Directory for build output (e.g., object files, executable)
├── .vscode                          # VS Code configuration files
│   ├── tasks.json                   # VS Code task configuration for building the project
│   ├── c_cpp_properties.json        # VS Code C++ settings for IntelliSense and includes
│   ├── launch.json                  # VS Code configuration for running/debugging the project
│   └── settings.json                # VS Code settings for customizing the environment
├── README.md                        # Project documentation or notes
</pre>

---

# Steps to Run the Program in VS Code

1. Install Dependencies (If Applicable):

    - Before you can run the program, ensure the following dependencies are installed:
        - **C++ Compiler (g++):** 
            - To install the C++ compiler, open your terminal and run the following commands:
                ```
                    sudo apt update
                    sudo apt install g++
                ```

        - **VS Code Extensions:** 
            - You can find it in the VS extentions by searching for C/C++.
        
---

2. Create or update `tasks.json` and paste the following:

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
                    "${workspaceFolder}/src/main.cpp",
                    "${workspaceFolder}/src/Character/Character.cpp",
                    "${workspaceFolder}/src/Character/Player.cpp",
                    "${workspaceFolder}/src/Character/Enemy.cpp",
                    "${workspaceFolder}/src/SpecialAbilities/SpecialAttack.cpp",
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


3. Create or update `c_cpp_properties.json` with the following:

    ```c_cpp_properties.json
    {
    "configurations": [
        {
        "name": "linux-gcc-x64",
        "includePath": [
            "${workspaceFolder}/**",  // Includes all files in the workspace
            "${workspaceFolder}/src/SpecialAbilities",  // Ensure this directory is included
            "${workspaceFolder}/src/Character"  // Ensure the Character directory is also included
        ],
        "compilerPath": "/usr/bin/gcc",
        "cStandard": "${default}",
        "cppStandard": "${default}",
        "intelliSenseMode": "linux-gcc-x64",
        "compilerArgs": [
            "-Wall",
            "-Wextra",
            "-Wpedantic"
        ]
        }
    ],
    "version": 4
    }
    ```

4. Create or update `launch.json` and paste the following:

    ```launch.json
        {
    "version": "0.2.0",
    "configurations": [
        {
        "name": "Debug C++ Program",
        "type": "cppdbg",
        "request": "launch",
        "program": "${workspaceFolder}/main",  // Path to the compiled executable
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
        "miDebuggerPath": "/usr/bin/gdb",  // Path to gdb debugger
        "preLaunchTask": "build main",     // This will run the build task before launching
        "logging": {
            "engineLogging": true
        },
        "externalConsole": true
        }
    ]
    }
    ```

5. Create or update `settings.json` and paste the following:

    ```settings.json
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

---


6. Build the Program:
   - Press `Ctrl+Shift+B` in VS Code or go to **Terminal > Run Build Task**.
   - This will compile your program and create an executable file named `main`.

7. Run the Program:
   - Open the terminal in VS Code (press `Ctrl+``).
   - Run the executable file with the following command:
     ```bash
     ./main
     ```
     
---

# Important Code

- **Objects**
    - Creating `Default_player` and `Default_enemy` Objects:
    - `Default_player` and `Default_enemy` are both being created with various attributes (name, health, attack power, etc.) and a reference to the `Grid` object. The player has coordinates (`X_position`, `Y_position`) for their location in the grid.
    ```cpp
    Player Default_player(name, health, attackPower, X_position, Y_position, grid);
    Enemy Default_enemy(enemyName, 50, 5, 0, 3, grid);
    ```

- **Calling Object Functions**
    - Each of these functions performs a specific task related to the `Default_player` and `Default_enemy` objects, such as performing an attack, checking health, applying damage, moving the player, or checking if the player is still alive.
    ```cpp
    Default_player.attack();               // Returns int value of player's attack value.
    Default_player.getHealth();            // Returns int value of player's health.
    Default_player.takeDamage(parameter);  // Subtracts from player object's health.
    Default_player.getSpAttackPower();     // Returns int value of player's special attack power.
    Default_player.move(X, Y);             // Moves the player's position on the grid.
    Default_player.isAlive();              // Checks if player's health is 0 or not.
                                           // Currently returns 1 or 0.
    ```

    ```cpp
    Default_enemy.attack();                // Returns int value of enemy's attack value.
    Default_enemy.getHealth();             // Returns int value of enemy's health.
    Default_enemy.takeDamage(parameter);   // Subtracts from enemy's health.
    Default_enemy.move(X, Y);              // Moves the enemy's position on the grid.
    Default_enemy.isAlive();               // Checks if enemy's health is 0 or not. 
                                           //Currently returns 1 or 0.
    ```



