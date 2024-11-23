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
├── .vscode                          # VS Code configuration files (tasks.json, launch.json, etc.)
├── README.md                        # Project documentation or notes
├── tasks.json                       # VS Code task configuration for building the project
└── c_cpp_properties.json            # VS Code C++ settings for IntelliSense and includes
</pre>

---

# Steps to Run the Program in VS Code:

1. Install Dependencies (If Applicable):
    - Before you can run the program, ensure the following dependencies are installed:
    - **C++ Compiler (g++):** Make sure you have a C++ compiler installed. 

    - **VS Code Extensions:** Ensure you have the C++ extension installed in VS Code. You can find it in the VS extentions by searching for C/C++.
    
    
    **On Ubuntu**, you can install it with:
    ```
    sudo apt update
    sudo apt install g++
    ```

2. Create `tasks.json` and paste the following:

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


3. Update `c_cpp_properties.json` with the following:

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


4. Build the Program:
   - Press `Ctrl+Shift+B` in VS Code or go to **Terminal > Run Build Task**.
   - This will compile your program and create an executable file named `main`.

5. Run the Program:
   - Open the terminal in VS Code (press `Ctrl+``).
   - Run the executable file with the following command:
     ```bash
     ./main
     ```
---