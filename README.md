Here’s the text without the comment marks:

---

Steps to Run the Program in VS Code:

1. Ensure Your `tasks.json` is Set Up:
   - Make sure your `tasks.json` file includes all required `.cpp` files for compilation.
   Example `tasks.json`:
   ```json
   {
       "version": "2.0.0",
       "tasks": [
           {
               "label": "build",
               "type": "shell",
               "command": "/usr/bin/g++",
               "args": [
                   "-g",
                   "-I", "src/Character",       // Include directory for headers
                   "src/main.cpp",              // Main program
                   "src/Character/Character.cpp",  // Character class implementation
                   "src/Character/Player.cpp",     // Player class implementation (if applicable)
                   "src/Character/Enemy.cpp",      // Enemy class implementation (if applicable)
                   "-o",
                   "main"                       // Output executable
               ],
               "group": {
                   "kind": "build",
                   "isDefault": true
               },
               "problemMatcher": ["$gcc"],
               "detail": "Generated task by VS Code"
           }
       ]
   }
   ```

2. Build the Program:
   - Press `Ctrl+Shift+B` in VS Code or go to **Terminal > Run Build Task**.
   - This will compile your program and create an executable file named `main`.

3. Run the Program:
   - Open the terminal in VS Code (press `Ctrl+``).
   - Run the executable file with the following command:
     ```bash
     ./main
     ```

4. Troubleshooting:
   - If the build fails or you get errors:
     1. Check the `tasks.json` configuration to ensure all file paths are correct.
     2. Ensure all `.cpp` and `.h` files are included and saved properly.

---