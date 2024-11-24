// Grid.h

#ifndef GRID_H
#define GRID_H

#include <iostream>
#include <string>

class Grid {
private:
    int grid[4][4];  // 4x4 grid

public:
    Grid();

    void setPlayerPosition(int x, int y);
    void setEnemyPosition(int x, int y);
    void clearPosition(int x, int y);
    void setPosition(int x, int y, int value);
    void displayGrid() const;
    bool isValidPosition(int x, int y) const;
    bool areAdjacent(int pX, int pY, int eX, int eY) const;
};

#endif
