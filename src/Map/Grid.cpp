// Grid.cpp

#include "Grid.h"
#include <iostream>
#include <cmath>
#include "UserInterface.h"
using namespace std;

// Constructor: dynamically allocate a 4x4 grid and initialize with zeros
Grid::Grid() {
    grid = new int*[rows];  // Allocate rows
    for (int i = 0; i < rows; ++i) {
        grid[i] = new int[cols];  // Allocate columns for each row
        for (int j = 0; j < cols; ++j) {
            grid[i][j] = 0;  // Initialize all positions to zero
        }
    }
}

// Destructor: deallocate the dynamically allocated grid
Grid::~Grid() {
    for (int i = 0; i < rows; ++i) {
        delete[] grid[i];  // Deallocate each row
    }
    delete[] grid;  // Deallocate the array of row pointers
}

// Clears the position on the grid
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
    setPosition(x, y, 1);  // 1 represents the player
}

void Grid::setEnemyPosition(int x, int y) {
    setPosition(x, y, 2);  // 2 represents the enemy
}

// Displays the grid with 'P' for player, 'E' for enemy, and '_' for empty space
void Grid::displayGrid() const {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
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
}

// Check if positions are adjacent
bool Grid::areAdjacent(int pX, int pY, int eX, int eY) const {
    if (pX == -1 || eX == -1)  // Ensure valid positions
        return false;
    return (std::abs(pX - eX) <= 1 && std::abs(pY - eY) <= 1);
}

// Check if the position is within the grid bounds
bool Grid::isValidPosition(int x, int y) const {
    return (x >= 0 && x < rows && y >= 0 && y < cols);
}
