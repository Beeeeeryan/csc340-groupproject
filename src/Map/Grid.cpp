// Grid.cpp

#include "Grid.h"

Grid::Grid() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            grid[i][j] = 0;  // 0 represents an empty space ('_')
        }
    }
}

