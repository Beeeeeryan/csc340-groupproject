// Grid.cpp

#include "Grid.h"

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
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
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

// Checks if the position is within the grid
bool Grid::isValidPosition(int x, int y) const {
    return (x >= 0 && x < 4 && y >= 0 && y < 4);
}
