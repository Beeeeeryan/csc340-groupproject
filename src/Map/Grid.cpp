// Grid.cpp

#include "Grid.h"
#include <iostream>
#include <cmath>
#include "UserInterface.h"
using namespace std;

// Populates the grid with zeros
Grid::Grid() {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            grid[i][j] = 0;
        }
    }
}

// Clears the prevoius position of the player or enemy
// So that we don't see duplicate positions on the grid
void Grid::clearPosition(int x, int y) {
    if (isValidPosition(x, y)) {
        grid[x][y] = 0;
    }
}

void Grid::setPosition(int x, int y, int value) {
    if (isValidPosition(x, y)) {
        grid[x][y] = value;
    }
}

void Grid::setPlayerPosition(int x, int y) {
    setPosition(x, y, 1);
}

void Grid::setEnemyPosition(int x, int y) {
    setPosition(x, y, 2);
}

// Displays the grid
// Displays 'P' for player, 'E' for enemy and '_' for empty space
// If the grid has a 0, it displays '_'
// If the grid has a 1, it displays 'P'
// If the grid has a 2, it displays 'E'
void Grid::displayGrid() const {
    // Find positions of P and E
    int pX = -1, pY = -1, eX = -1, eY = -1;

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (grid[i][j] == 1) {  // Player found
                pX = i;
                pY = j;
            } else if (grid[i][j] == 2) {  // Enemy found
                eX = i;
                eY = j;
            }

            // Print the grid symbol
            if (grid[i][j] == 0) {
                std::cout << "_ ";
            } else if (grid[i][j] == 1) {
                std::cout << "P ";
            } else if (grid[i][j] == 2) {
                std::cout << "E ";
            }
        }
        std::cout << std::endl;
   }
    // Check if P and E are adjacent
    //if (areAdjacent(pX, pY, eX, eY)) {
       // displayAttackOption();
    //}
}

// Function to check adjacency
bool Grid::areAdjacent(int pX, int pY, int eX, int eY) const{
    // Ensure valid positions
    if (pX == -1 || eX == -1) 
    return false;

    // Check if positions are adjacent
    return (std::abs(pX - eX) <= 1 && std::abs(pY - eY) <= 1);
}

// Checks if the position is within the grid
bool Grid::isValidPosition(int x, int y) const {
    return (x >= 0 && x < 4 && y >= 0 && y < 4);
}
