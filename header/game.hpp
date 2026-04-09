#pragma once

#include <raylib.h>
#include <memory>

#include "grid.hpp"

using namespace std;

class Game{
    public:

    Game(int width, int height, string title);

    void mainloop();

    void initGrid(int row, int col, int cellSize, int gap, Vector2 offset);
    private:

    void gameOver();

    unique_ptr<Grid> grid;
};